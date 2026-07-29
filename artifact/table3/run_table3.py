#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import shutil
import subprocess
import sys
from pathlib import Path


SCRIPT_DIR = Path(__file__).resolve().parent
REPO_ROOT = SCRIPT_DIR.parents[1]
TABLE2_DIR = REPO_ROOT / "artifact" / "table2"
sys.path.insert(0, str(TABLE2_DIR))

from benchmarks import BENCHMARKS, Benchmark  # noqa: E402


RECORDED_MEMORY_BYTES = {
    "ResNet8": 39_809,
    "ResNet20": 57_952,
    "MobileNetV2": 341_344,
    "YOLOv5nu": 1_465_118,
    "YOLOv10n": 1_932_470,
}


def benchmark_by_name(name: str) -> Benchmark:
    for benchmark in BENCHMARKS:
        if benchmark.name.lower() == name.lower():
            return benchmark
    known = ", ".join(benchmark.name for benchmark in BENCHMARKS)
    raise SystemExit(f"Unknown benchmark '{name}'. Known benchmarks: {known}")


def generated_dir(root: Path) -> Path:
    return root / "artifact" / "table3" / "generated"


def results_dir(root: Path) -> Path:
    return root / "artifact" / "table3" / "results"


def make_table3_tcl(benchmark: Benchmark, gen_dir: Path) -> Path:
    bench_dir = REPO_ROOT / benchmark.directory
    project_dir = gen_dir / benchmark.directory / f"{benchmark.top}_table3_lightning_ste_HLS_project"
    tcl = f"""set script_dir  [file normalize \"{bench_dir}\"]
set inc_dir     [file normalize [file join $script_dir ../nn2FPGA/include]]
set kernel_cpp  [file normalize [file join $script_dir kernels/kernel_lightning_ste.cpp]]
set tb_cpp      [file normalize [file join $script_dir testbenches/testbench_lightning.cpp]]
set proj_dir    [file normalize \"{project_dir}\"]
set sol_name    \"solution_0\"

open_project -reset $proj_dir
set_top {benchmark.top}
add_files $kernel_cpp -cflags [format {{-I%s}} $inc_dir]
add_files -tb $tb_cpp -cflags [format {{-I%s}} $inc_dir]

open_solution -reset $sol_name
set_part {benchmark.part}
create_clock -period 5
config_compile -pipeline_style flp

csynth_design

exit
"""
    output = gen_dir / benchmark.directory / "run_table3.tcl"
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(tcl)
    return output


def run_hls(tcl: Path) -> None:
    vitis_hls = shutil.which("vitis_hls")
    if vitis_hls is None:
        raise RuntimeError("vitis_hls not found in PATH")
    subprocess.run([vitis_hls, "-f", str(tcl)], cwd=REPO_ROOT, check=True)


def solution_dir(root: Path, benchmark: Benchmark) -> Path:
    return generated_dir(root) / benchmark.directory / f"{benchmark.top}_table3_lightning_ste_HLS_project" / "solution_0"


def observed_report_path(root: Path, benchmark: Benchmark) -> Path:
    return results_dir(root) / "raw" / benchmark.name / "observed_depth.json"


def normalized_report_path(root: Path, benchmark: Benchmark) -> Path:
    return results_dir(root) / "normalized" / f"{benchmark.name}.json"


def run_fifo_advisor(benchmark: Benchmark, report_path: Path) -> None:
    fifo_advisor = shutil.which("fifo-advisor")
    if fifo_advisor is None:
        raise RuntimeError("fifo-advisor not found in PATH. Run 'source artifact/fifoadvisor/setup_env.sh' first.")

    report_path.parent.mkdir(parents=True, exist_ok=True)
    if report_path.exists():
        report_path.unlink()

    command = [
        fifo_advisor,
        str(solution_dir(REPO_ROOT, benchmark)),
        "--output",
        str(report_path),
        "--report-observed-depths",
    ]
    if benchmark.fifo_override_json is not None:
        command.extend(["--fifo-depth-overrides", str(benchmark.fifo_override_json)])
    subprocess.run(command, cwd=REPO_ROOT, check=True)


def find_observed_memory_bytes(payload):
    if isinstance(payload, dict):
        if "observed_memory_bytes" in payload:
            return payload["observed_memory_bytes"]
        for value in payload.values():
            found = find_observed_memory_bytes(value)
            if found is not None:
                return found
        return None
    if isinstance(payload, list):
        for value in payload:
            found = find_observed_memory_bytes(value)
            if found is not None:
                return found
    return None


def collect_row(root: Path, benchmark: Benchmark) -> dict[str, str | int]:
    report_path = observed_report_path(root, benchmark)
    if not report_path.exists():
        raise RuntimeError(f"Missing observed-depth report: {report_path}")

    payload = json.loads(report_path.read_text())
    observed = find_observed_memory_bytes(payload)
    if observed is None:
        raise RuntimeError(f"Could not find observed_memory_bytes in {report_path}")

    recorded = RECORDED_MEMORY_BYTES[benchmark.name]
    observed = int(observed)
    delta = ((recorded - observed) / recorded) * 100.0

    normalized = {
        "benchmark": benchmark.name,
        "recorded_memory_bytes": recorded,
        "observed_memory_bytes": observed,
        "delta_percent": delta,
        "source_path": str(report_path.relative_to(root)),
    }
    normalized_path = normalized_report_path(root, benchmark)
    normalized_path.parent.mkdir(parents=True, exist_ok=True)
    normalized_path.write_text(json.dumps(normalized, indent=2) + "\n")

    return {
        "benchmark": benchmark.name,
        "recorded": recorded,
        "observed": observed,
        "delta": f"{delta:.2f}",
    }


def print_table(rows: list[dict[str, str | int]]) -> None:
    headers = ["Benchmark", "Recorded (B)", "Observed (B)", "Delta (%)"]
    body = [
        [str(row["benchmark"]), str(row["recorded"]), str(row["observed"]), str(row["delta"])]
        for row in rows
    ]
    widths = [len(header) for header in headers]
    for row in body:
        widths = [max(width, len(value)) for width, value in zip(widths, row)]

    print("  ".join(header.ljust(width) for header, width in zip(headers, widths)))
    print("  ".join("-" * width for width in widths))
    for row in body:
        print("  ".join(value.ljust(width) for value, width in zip(row, widths)))


def main() -> int:
    parser = argparse.ArgumentParser(description="Run and report Table III observed FIFO memory.")
    parser.add_argument("--benchmark", action="append", help="Benchmark to run. May be repeated.")
    parser.add_argument("--parse-only", action="store_true", help="Only parse existing reports; do not run Vitis HLS or FIFOAdvisor.")
    args = parser.parse_args()

    root = REPO_ROOT
    benchmarks = [benchmark_by_name(name) for name in args.benchmark] if args.benchmark else list(BENCHMARKS)

    if not args.parse_only:
        for benchmark in benchmarks:
            tcl = make_table3_tcl(benchmark, generated_dir(root))
            run_hls(tcl)
            run_fifo_advisor(benchmark, observed_report_path(root, benchmark))

    rows = [collect_row(root, benchmark) for benchmark in benchmarks]
    print_table(rows)
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except subprocess.CalledProcessError as error:
        print(f"Command failed with exit code {error.returncode}: {' '.join(error.cmd)}", file=sys.stderr)
        raise SystemExit(error.returncode)
    except Exception as error:
        print(f"error: {error}", file=sys.stderr)
        raise SystemExit(1)
