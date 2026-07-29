#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import subprocess
from pathlib import Path

from benchmarks import (
    GENERATED_DIR,
    REPO_ROOT,
    TECHNIQUE_LABELS,
    normalized_path,
    raw_resource_dir,
    resource_kernel_path,
    resource_solution_dir,
    resource_testbench_path,
    select_benchmarks,
    select_resource_techniques,
)


RESOURCE_KEYS = ("LUT", "FF", "DSP", "BRAM")


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Run Table II resource synthesis/export for fixed kernel variants."
    )
    parser.add_argument("--benchmark", action="append", help="Benchmark to run. May be repeated.")
    parser.add_argument("--technique", action="append", help="Technique to run. May be repeated.")
    parser.add_argument(
        "--generate-only",
        action="store_true",
        help="Generate HLS TCL scripts and exit without running Vitis HLS.",
    )
    parser.add_argument(
        "--parse-only",
        action="store_true",
        help="Do not rerun Vitis HLS; parse existing export reports.",
    )
    return parser


def make_hls_tcl(benchmark, technique: str) -> Path:
    gen_dir = GENERATED_DIR / benchmark.name
    gen_dir.mkdir(parents=True, exist_ok=True)
    kernel_cpp = resource_kernel_path(benchmark, technique)
    if not kernel_cpp.exists():
        raise SystemExit(f"Missing kernel for {benchmark.name} {technique}: {kernel_cpp}")

    tcl_path = gen_dir / f"build_{technique}_resource_solution.tcl"
    proj_dir = resource_solution_dir(benchmark, technique).parent
    tb_cpp = resource_testbench_path(benchmark)
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
export_design -flow syn

exit
"""
    tcl_path.write_text(tcl)
    return tcl_path


def run_hls(tcl_path: Path) -> None:
    subprocess.run(["vitis_hls", "-f", str(tcl_path)], cwd=REPO_ROOT, check=True)


def resource_report_path(benchmark, technique: str) -> Path:
    return resource_solution_dir(benchmark, technique) / "impl" / "report" / "verilog" / f"{benchmark.top}_export.rpt"


def parse_resource_report(report: Path) -> dict[str, int]:
    if not report.exists():
        raise SystemExit(f"Missing export report: {report}")

    values: dict[str, int] = {}
    in_resources = False
    for raw_line in report.read_text().splitlines():
        line = raw_line.strip()
        if line == "#=== Post-Synthesis Resource usage ===":
            in_resources = True
            continue
        if not in_resources:
            continue
        if line.startswith("#==="):
            break
        if ":" not in line:
            continue
        key, value = [field.strip() for field in line.split(":", 1)]
        if key in RESOURCE_KEYS:
            values[key.lower()] = int(value)

    missing = [key.lower() for key in RESOURCE_KEYS if key.lower() not in values]
    if missing:
        raise SystemExit(f"Could not parse resource keys {missing} from {report}")
    return values


def normalize_resource_result(benchmark, technique: str, report: Path) -> Path:
    resources = parse_resource_report(report)
    result = {
        "benchmark": benchmark.name,
        "technique": technique,
        "technique_label": TECHNIQUE_LABELS[technique],
        "lut": resources["lut"],
        "ff": resources["ff"],
        "dsp": resources["dsp"],
        "bram": resources["bram"],
        "resource_report_path": str(report.relative_to(REPO_ROOT)),
        "notes": [],
    }
    out = raw_resource_dir(benchmark) / f"{technique}.json"
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(json.dumps(result, indent=2) + "\n")

    normalized = normalized_path(benchmark, technique)
    payload = json.loads(normalized.read_text()) if normalized.exists() else {
        "benchmark": benchmark.name,
        "technique": technique,
        "technique_label": TECHNIQUE_LABELS[technique],
        "notes": [],
    }
    payload.update(result)
    normalized.parent.mkdir(parents=True, exist_ok=True)
    normalized.write_text(json.dumps(payload, indent=2) + "\n")
    return normalized


def main() -> None:
    args = build_parser().parse_args()
    if args.generate_only and args.parse_only:
        raise SystemExit("--generate-only and --parse-only are mutually exclusive")

    benchmarks = select_benchmarks(args.benchmark)
    techniques = select_resource_techniques(args.technique)

    for benchmark in benchmarks:
        for technique in techniques:
            tcl_path = make_hls_tcl(benchmark, technique)
            print(f"Wrote {tcl_path}")
            if args.generate_only:
                continue
            if not args.parse_only:
                run_hls(tcl_path)
            report = resource_report_path(benchmark, technique)
            out = normalize_resource_result(benchmark, technique, report)
            print(f"Wrote {out}")


if __name__ == "__main__":
    main()
