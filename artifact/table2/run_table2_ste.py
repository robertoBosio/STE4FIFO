#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import subprocess

from benchmarks import REPO_ROOT, normalized_path, raw_fifoadvisor_dir, select_benchmarks


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Run and normalize Table II STE size/time results."
    )
    parser.add_argument("--benchmark", action="append", help="Benchmark to run. May be repeated.")
    parser.add_argument(
        "--parse-only",
        action="store_true",
        help="Do not rerun STE; parse existing fifo_depth.json files.",
    )
    return parser


def load_widths(width_report: Path) -> dict[str, int]:
    payload = json.loads(width_report.read_text())
    widths: dict[str, int] = {}
    for fifo in payload.get("per_fifo", []):
        name = fifo.get("name")
        width_bytes = fifo.get("width_bytes")
        if name is not None and width_bytes is not None:
            widths[str(name)] = int(width_bytes)
    return widths


def compute_size_bytes(depths: dict[str, int], widths: dict[str, int]) -> int:
    missing = sorted(name for name in depths if name not in widths)
    if missing:
        preview = ", ".join(missing[:10])
        raise SystemExit(
            "Cannot compute STE FIFO memory because width metadata is missing for "
            f"{len(missing)} FIFO(s): {preview}"
        )
    return sum(int(depth) * widths[name] for name, depth in depths.items())


def run_ste(benchmark: str) -> None:
    subprocess.run(
        [str(REPO_ROOT / "artifact" / "run_ste.sh"), benchmark],
        cwd=REPO_ROOT,
        check=True,
    )


def normalize_ste(benchmark) -> Path:
    width_report = raw_fifoadvisor_dir(benchmark) / "observed_depths.json"
    if not width_report.exists():
        raise SystemExit(
            f"Missing FIFO width report: {width_report}\n"
            "Generate it with: artifact/table2/run_table2_fifoadvisor.py "
            f"--benchmark {benchmark.name} --observed-depths-only"
        )

    payload = json.loads(benchmark.ste_json.read_text())
    depths = {str(name): int(depth) for name, depth in payload["fifo_depth"].items()}
    widths = load_widths(width_report)
    size_bytes = compute_size_bytes(depths, widths)
    time_ms = float(payload["Simulation time (ms)"])

    result = {
        "benchmark": benchmark.name,
        "technique": "our_method",
        "technique_label": "Our method",
        "final_size_bytes": size_bytes,
        "final_time_seconds": time_ms / 1000.0,
        "source_path": str(benchmark.ste_json.relative_to(REPO_ROOT)),
        "width_source_path": str(width_report.relative_to(REPO_ROOT)),
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
            run_ste(benchmark.name)
        if not benchmark.ste_json.exists():
            raise SystemExit(f"Missing STE output: {benchmark.ste_json}")
        out = normalize_ste(benchmark)
        print(f"Wrote {out}")


if __name__ == "__main__":
    main()
