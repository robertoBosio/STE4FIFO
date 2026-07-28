#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import shlex
import subprocess

from benchmarks import (
    GENERATED_DIR,
    REPO_ROOT,
    TECHNIQUE_LABELS,
    hls_project_dir,
    hls_solution_dir,
    normalized_path,
    raw_fifoadvisor_dir,
    select_benchmarks,
    select_solvers,
)


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Build Table II kernel_lightning solutions and run FIFOAdvisor."
    )
    parser.add_argument("--benchmark", action="append", help="Benchmark to run. May be repeated.")
    parser.add_argument("--solver", action="append", help="FIFOAdvisor solver to run. May be repeated.")
    parser.add_argument(
        "--fifo-advisor-cmd",
        default="fifo-advisor",
        help="FIFOAdvisor command or module wrapper (default: fifo-advisor).",
    )
    parser.add_argument(
        "--skip-hls",
        action="store_true",
        help="Do not rebuild the kernel_lightning HLS solution.",
    )
    parser.add_argument(
        "--generate-only",
        action="store_true",
        help="Generate HLS TCL scripts and exit without running HLS or FIFOAdvisor.",
    )
    parser.add_argument(
        "--observed-depths-only",
        action="store_true",
        help="Only write the FIFOAdvisor start-vs-observed width/depth report.",
    )
    parser.add_argument("--n-samples", type=int, default=None)
    parser.add_argument("--seed", type=int, default=None)
    parser.add_argument("--maxfun", type=int, default=None)
    parser.add_argument("--n-scaling-factors", type=int, default=None)
    parser.add_argument("--round-type", default=None)
    parser.add_argument("--init-with-largest", action="store_true")
    return parser


def make_hls_tcl(benchmark) -> Path:
    gen_dir = GENERATED_DIR / benchmark.name
    gen_dir.mkdir(parents=True, exist_ok=True)
    project_dir = hls_project_dir(benchmark)
    tcl_path = gen_dir / "build_lightning_solution.tcl"
    tcl = f"""set script_dir  [file normalize \"{benchmark.bench_dir}\"]
set inc_dir     [file normalize \"{benchmark.include_dir}\"]
set kernel_cpp  [file normalize \"{benchmark.lightning_kernel}\"]
set tb_cpp      [file normalize \"{benchmark.lightning_testbench}\"]
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
    tcl_path.write_text(tcl)
    return tcl_path


def run_hls(tcl_path: Path) -> None:
    subprocess.run(["vitis_hls", "-f", str(tcl_path)], cwd=REPO_ROOT, check=True)


def fifo_advisor_base_cmd(command: str) -> list[str]:
    return shlex.split(command)


def common_fifo_advisor_args(args, benchmark, output: Path) -> list[str]:
    command = [str(hls_solution_dir(benchmark)), "--output", str(output)]
    if benchmark.fifo_override_json.exists():
        command.extend(["--fifo-depth-overrides", str(benchmark.fifo_override_json)])
    return command


def run_observed_depth_report(args, benchmark) -> Path:
    out = raw_fifoadvisor_dir(benchmark) / "observed_depths.json"
    out.parent.mkdir(parents=True, exist_ok=True)
    if out.exists():
        out.unlink()
    command = fifo_advisor_base_cmd(args.fifo_advisor_cmd)
    command.extend(common_fifo_advisor_args(args, benchmark, out))
    command.append("--report-observed-depths")
    subprocess.run(command, cwd=REPO_ROOT, check=True)
    return out


def solver_extra_args(args) -> list[str]:
    extra: list[str] = []
    for flag, value in (
        ("--n-samples", args.n_samples),
        ("--seed", args.seed),
        ("--maxfun", args.maxfun),
        ("--n-scaling-factors", args.n_scaling_factors),
        ("--round-type", args.round_type),
    ):
        if value is not None:
            extra.extend([flag, str(value)])
    if args.init_with_largest:
        extra.append("--init-with-largest")
    return extra


def normalize_solver_result(benchmark, solver: str, raw_path: Path) -> Path:
    payload = json.loads(raw_path.read_text())
    evaluation = payload["evaluations"]
    result = {
        "benchmark": benchmark.name,
        "technique": solver,
        "technique_label": TECHNIQUE_LABELS[solver],
        "final_size_bytes": evaluation["byte_usage_total"],
        "final_time_seconds": evaluation["dse_time"],
        "source_path": str(raw_path.relative_to(REPO_ROOT)),
        "baseline_report_path": str((raw_fifoadvisor_dir(benchmark) / "observed_depths.json").relative_to(REPO_ROOT)),
        "deadlock": evaluation.get("deadlock"),
        "latency": evaluation.get("latency"),
        "notes": [],
    }
    out = normalized_path(benchmark, solver)
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(json.dumps(result, indent=2) + "\n")
    return out


def run_solver(args, benchmark, solver: str) -> Path:
    raw_path = raw_fifoadvisor_dir(benchmark) / f"{solver}.json"
    raw_path.parent.mkdir(parents=True, exist_ok=True)
    if raw_path.exists():
        raw_path.unlink()
    command = fifo_advisor_base_cmd(args.fifo_advisor_cmd)
    command.extend(common_fifo_advisor_args(args, benchmark, raw_path))
    command.extend(["--solver", solver])
    command.extend(solver_extra_args(args))
    subprocess.run(command, cwd=REPO_ROOT, check=True)
    return normalize_solver_result(benchmark, solver, raw_path)


def main() -> None:
    args = build_parser().parse_args()
    benchmarks = select_benchmarks(args.benchmark)
    solvers = [] if args.observed_depths_only else select_solvers(args.solver)

    for benchmark in benchmarks:
        tcl_path = make_hls_tcl(benchmark)
        print(f"Wrote {tcl_path}")
        if args.generate_only:
            continue
        if not args.skip_hls:
            run_hls(tcl_path)
        solution_dir = hls_solution_dir(benchmark)
        if not solution_dir.exists():
            raise SystemExit(f"Missing HLS solution: {solution_dir}")
        observed = run_observed_depth_report(args, benchmark)
        print(f"Wrote {observed}")
        for solver in solvers:
            out = run_solver(args, benchmark, solver)
            print(f"Wrote {out}")


if __name__ == "__main__":
    main()
