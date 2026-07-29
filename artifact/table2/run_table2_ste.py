#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import re
import subprocess
from pathlib import Path

from benchmarks import (
    GENERATED_DIR,
    REPO_ROOT,
    normalized_path,
    resource_csynth_report_path,
    resource_solution_dir,
    select_benchmarks,
)


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Run and normalize Table II STE size/time results."
    )
    parser.add_argument("--benchmark", action="append", help="Benchmark to run. May be repeated.")
    parser.add_argument(
        "--parse-only",
        action="store_true",
        help="Do not rerun STE or csynth; parse existing fifo_depth.json and csynth reports.",
    )
    return parser

def run_ste(benchmark) -> None:
    benchmark.ste_json.unlink(missing_ok=True)
    subprocess.run(
        ["vitis_hls", "-f", "run_ste.tcl"],
        cwd=benchmark.ste_dir,
        check=True,
    )


def make_csynth_tcl(benchmark) -> Path:
    gen_dir = GENERATED_DIR / benchmark.name
    gen_dir.mkdir(parents=True, exist_ok=True)
    kernel_cpp = benchmark.bench_dir / "kernels" / "kernel_original.cpp"
    tb_cpp = benchmark.bench_dir / "testbenches" / "testbench_original.cpp"
    proj_dir = resource_solution_dir(benchmark, "our_method").parent
    tcl_path = gen_dir / "build_our_method_csynth.tcl"
    tcl = f"""set script_dir  [file normalize \"{benchmark.bench_dir}\"]
set inc_dir     [file normalize \"{benchmark.include_dir}\"]
set kernel_cpp  [file normalize \"{kernel_cpp}\"]
set tb_cpp      [file normalize \"{tb_cpp}\"]
set proj_dir    [file normalize \"{proj_dir}\"]
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
    tcl_path.write_text(tcl)
    return tcl_path


def run_csynth(tcl_path: Path) -> None:
    subprocess.run(["vitis_hls", "-f", str(tcl_path)], cwd=REPO_ROOT, check=True)


def parse_total_fifo_bits(report: Path) -> int:
    if not report.exists():
        raise SystemExit(f"Missing csynth report: {report}")

    total_row = re.compile(r"^\|\s*Total\s*\|(?P<body>.*)\|$")
    in_fifo_section = False
    for raw_line in report.read_text().splitlines():
        line = raw_line.strip()
        if not in_fifo_section:
            if line == "* FIFO:":
                in_fifo_section = True
            continue

        match = total_row.match(line)
        if not match:
            continue
        fields = [field.strip() for field in match.group("body").split("|")]
        if len(fields) < 7:
            break
        try:
            return int(fields[-1])
        except ValueError as error:
            raise SystemExit(f"Could not parse total FIFO bits from {report}: {raw_line}") from error

    raise SystemExit(f"Could not find FIFO Total row in {report}")


def fifo_bytes_from_report(report: Path) -> int:
    return (parse_total_fifo_bits(report) + 7) // 8


def normalize_ste(benchmark) -> Path:
    payload = json.loads(benchmark.ste_json.read_text())
    time_ms = float(payload["Simulation time (ms)"])
    size_report = resource_csynth_report_path(benchmark, "our_method")
    size_bytes = fifo_bytes_from_report(size_report)

    result = {
        "benchmark": benchmark.name,
        "technique": "our_method",
        "technique_label": "Our method",
        "final_size_bytes": size_bytes,
        "final_time_seconds": time_ms / 1000.0,
        "source_path": str(benchmark.ste_json.relative_to(REPO_ROOT)),
        "size_report_path": str(size_report.relative_to(REPO_ROOT)),
        "simulation_cycles": payload.get("Simulation cycles"),
        "ii": payload.get("II"),
        "notes": [],
    }

    out = normalized_path(benchmark, "our_method")
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(json.dumps(result, indent=2) + "\n")
    return out


def main() -> None:
    args = build_parser().parse_args()
    for benchmark in select_benchmarks(args.benchmark):
        if not args.parse_only:
            run_ste(benchmark)
            tcl_path = make_csynth_tcl(benchmark)
            print(f"Wrote {tcl_path}")
            run_csynth(tcl_path)
        if not benchmark.ste_json.exists():
            raise SystemExit(f"Missing STE output: {benchmark.ste_json}")
        size_report = resource_csynth_report_path(benchmark, "our_method")
        if not size_report.exists():
            raise SystemExit(f"Missing csynth report: {size_report}")
        out = normalize_ste(benchmark)
        print(f"Wrote {out}")


if __name__ == "__main__":
    main()
