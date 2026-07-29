#!/usr/bin/env python3
import argparse
import json
import re
import shutil
import subprocess
import sys
from dataclasses import dataclass
from pathlib import Path


@dataclass(frozen=True)
class Benchmark:
    name: str
    directory: str
    top: str
    part: str
    argv_files: tuple[str, ...]


BENCHMARKS = [
    Benchmark("ResNet8", "ResNet8", "resnet8", "xck26-sfvc784-2LV-c", ("global_in.txt", "global_out.txt")),
    Benchmark("ResNet20", "ResNet20", "resnet20", "xczu9eg-ffvb1156-2-e", ("global_in.txt", "global_out.txt")),
    Benchmark("MobileNetV2", "MobileNetV2", "mobilenet_v2", "xczu9eg-ffvb1156-2-e", ("global_in.txt", "global_out.txt")),
    Benchmark("YOLOv5nu", "YOLOv5nu", "yolov5nu", "xczu9eg-ffvb1156-2-e", ("global_in.txt", "global_out.txt")),
    Benchmark("YOLOv10n", "YOLOv10n", "yolov10n", "xczu9eg-ffvb1156-2-e", ("global_in.txt", "global_out_2.txt", "global_out.txt", "global_out_1.txt")),
]


def repo_root() -> Path:
    return Path(__file__).resolve().parents[2]


def benchmark_by_name(name: str) -> Benchmark:
    for benchmark in BENCHMARKS:
        if benchmark.name.lower() == name.lower():
            return benchmark
    known = ", ".join(benchmark.name for benchmark in BENCHMARKS)
    raise SystemExit(f"Unknown benchmark '{name}'. Known benchmarks: {known}")


def make_table1_tcl(root: Path, benchmark: Benchmark, generated_dir: Path) -> Path:
    bench_dir = root / benchmark.directory
    project_dir = generated_dir / benchmark.directory / f"{benchmark.top}_table1_mem_HLS_project"
    argv_files = " ".join(f"[file normalize [file join $script_dir data {name}]]" for name in benchmark.argv_files)
    tcl = f"""set script_dir  [file normalize \"{bench_dir}\"]
set inc_dir     [file normalize [file join $script_dir ../nn2FPGA/include]]
set kernel_cpp  [file normalize [file join $script_dir kernels/kernel_mem.cpp]]
set tb_cpp      [file normalize [file join $script_dir testbenches/testbench_mem.cpp]]
set argv_files  [list {argv_files}]
set cosim_argv  [join $argv_files " "]
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

csim_design -argv $cosim_argv
csynth_design
cosim_design -argv $cosim_argv

    exit
"""
    output = generated_dir / benchmark.directory / "run_table1.tcl"
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(tcl)
    return output


def run_hls(root: Path, benchmark: Benchmark, tcl: Path) -> None:
    vitis_hls = shutil.which("vitis_hls")
    if vitis_hls is None:
        raise RuntimeError("vitis_hls not found in PATH")
    subprocess.run([vitis_hls, "-f", str(tcl)], cwd=root, check=True)


def project_dir(root: Path, benchmark: Benchmark, generated_dir: Path) -> Path:
    return generated_dir / benchmark.directory / f"{benchmark.top}_table1_mem_HLS_project" / "solution_0"


def parse_cosim_report(solution_dir: Path, benchmark: Benchmark) -> tuple[str, str]:
    report = solution_dir / "sim" / "report" / f"{benchmark.top}_cosim.rpt"
    if not report.exists():
        raise RuntimeError(f"Missing cosim report: {report}")

    for line in report.read_text().splitlines():
        if "|" not in line or "Verilog" not in line:
            continue
        fields = [field.strip() for field in line.split("|")]
        if len(fields) < 10:
            continue
        status = fields[2]
        if status != "Pass":
            raise RuntimeError(f"Cosim did not pass for {benchmark.name}: status={status}")
        return fields[5], fields[8]

    raise RuntimeError(f"Could not parse Verilog row in {report}")


def parse_processes(solution_dir: Path, benchmark: Benchmark) -> int:
    protoinst = solution_dir / ".debug" / f"{benchmark.top}.protoinst"
    if not protoinst.exists():
        raise RuntimeError(f"Missing protoinst file: {protoinst}")
    data = json.loads(protoinst.read_text())
    instances = data["modules"][benchmark.top]["proto_instances"]
    return sum(1 for name in instances if not name.startswith(f"/AESL_inst_{benchmark.top}_activity"))


def parse_fifos(root: Path, solution_dir: Path, benchmark: Benchmark) -> int:
    monitor = solution_dir / "sim" / "verilog" / "dataflow_monitor.sv"
    if monitor.exists():
        count = len(re.findall(r"\bdf_fifo_intf\s+fifo_intf_\d+\b", monitor.read_text()))
        if count:
            return count

    ste = root / benchmark.directory / "STE" / "STE.cpp"
    match = re.search(r"stream_max_size\[(\d+)\]", ste.read_text())
    if not match:
        raise RuntimeError(f"Could not parse FIFO count from {monitor} or {ste}")
    return int(match.group(1))


def collect_row(root: Path, benchmark: Benchmark, generated_dir: Path) -> dict[str, str | int]:
    solution_dir = project_dir(root, benchmark, generated_dir)
    latency, ii = parse_cosim_report(solution_dir, benchmark)
    return {
        "benchmark": benchmark.name,
        "processes": parse_processes(solution_dir, benchmark),
        "fifos": parse_fifos(root, solution_dir, benchmark),
        "latency": latency,
        "ii": ii,
    }


def print_table(rows: list[dict[str, str | int]]) -> None:
    headers = ["Benchmark", "Processes", "FIFOs", "Latency", "II"]
    body = [
        [str(row["benchmark"]), str(row["processes"]), str(row["fifos"]), str(row["latency"]), str(row["ii"])]
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
    parser = argparse.ArgumentParser(description="Run and report Table I HLS/cosim metrics.")
    parser.add_argument("--benchmark", action="append", help="Benchmark to run. May be repeated.")
    parser.add_argument("--parse-only", action="store_true", help="Only parse existing reports; do not run Vitis HLS.")
    args = parser.parse_args()

    root = repo_root()
    benchmarks = [benchmark_by_name(name) for name in args.benchmark] if args.benchmark else BENCHMARKS
    generated_dir = root / "artifact" / "table1" / "generated"

    if not args.parse_only:
        for benchmark in benchmarks:
            tcl = make_table1_tcl(root, benchmark, generated_dir)
            run_hls(root, benchmark, tcl)

    rows = [collect_row(root, benchmark, generated_dir) for benchmark in benchmarks]
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
