#!/usr/bin/env python3
from __future__ import annotations

import argparse
from collections import Counter
import json
import re
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


def normalize_fifo_name(name: str) -> str:
    return name[:-1] if name.endswith("_") else name


EXCLUDED_STE_PREFIXES = (
    "StreamingMemory_",
    "NHWCToStream_1_",
)


def load_widths(width_report) -> dict[str, int]:
    payload = json.loads(width_report.read_text())
    widths: dict[str, int] = {}
    for fifo in payload.get("per_fifo", []):
        name = fifo.get("name")
        width_bytes = fifo.get("width_bytes")
        if name is not None and width_bytes is not None:
            width = int(width_bytes)
            widths[normalize_fifo_name(str(name))] = width
    return widths


def type_width_bits(type_name: str) -> int | None:
    array_match = re.fullmatch(r"std::array<\s*(.+)\s*,\s*(\d+)\s*>", type_name)
    if array_match:
        inner_width = type_width_bits(array_match.group(1).strip())
        if inner_width is None:
            return None
        return inner_width * int(array_match.group(2))

    scalar_match = re.fullmatch(r"ap_(?:u?int)<\s*(\d+)\s*>", type_name)
    if scalar_match:
        return int(scalar_match.group(1))

    axis_match = re.fullmatch(r"ap_axiu<\s*(\d+)\s*,.*>", type_name)
    if axis_match:
        return int(axis_match.group(1))

    return None


def load_ste_widths(ste_cpp: Path) -> dict[str, int]:
    widths: dict[str, int] = {}
    declaration_re = re.compile(r"\s*hls::stream<(.+)>\s+(\w+)(?:\[(\d+)\])?;")
    for line in ste_cpp.read_text().splitlines():
        match = declaration_re.fullmatch(line)
        if not match:
            continue

        width_bits = type_width_bits(match.group(1).strip())
        if width_bits is None:
            continue
        width_bytes = (width_bits + 7) // 8
        base_name = match.group(2)
        count = int(match.group(3) or 1)
        for index in range(count):
            widths[f"{base_name}_{index}_"] = width_bytes
            widths[f"{base_name}_{index}"] = width_bytes
    return widths


def compute_size_bytes(depths: dict[str, int], widths: dict[str, int]) -> int:
    missing = sorted(name for name in depths if normalize_fifo_name(name) not in widths and name not in widths)
    if missing:
        preview = ", ".join(missing[:10])
        raise SystemExit(
            "Cannot compute STE FIFO memory because width metadata is missing for "
            f"{len(missing)} FIFO(s): {preview}"
        )
    total = 0
    for name, depth in depths.items():
        width = widths.get(normalize_fifo_name(name), widths.get(name))
        total += (int(depth) + 1) * width
    return total


def prefix_histogram(names: list[str]) -> dict[str, int]:
    counts = Counter(name.split("_", 1)[0] for name in names)
    return dict(sorted(counts.items()))


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
            f"Missing FIFOAdvisor width report: {width_report}\n"
            "Generate it with: artifact/table2/run_table2_fifoadvisor.py "
            f"--benchmark {benchmark.name} --observed-depths-only"
        )

    payload = json.loads(benchmark.ste_json.read_text())
    depths = {str(name): int(depth) for name, depth in payload["fifo_depth"].items()}
    hls_widths = load_widths(width_report)
    ste_widths = load_ste_widths(benchmark.ste_dir / "STE.cpp")

    included_depths: dict[str, int] = {}
    excluded_names: list[str] = []
    for name, depth in depths.items():
        if any(name.startswith(prefix) for prefix in EXCLUDED_STE_PREFIXES):
            excluded_names.append(name)
            continue
        included_depths[name] = depth

    widths = {**ste_widths, **hls_widths}
    size_bytes = compute_size_bytes(included_depths, widths)
    time_ms = float(payload["Simulation time (ms)"])

    result = {
        "benchmark": benchmark.name,
        "technique": "our_method",
        "technique_label": "Our method",
        "final_size_bytes": size_bytes,
        "final_time_seconds": time_ms / 1000.0,
        "source_path": str(benchmark.ste_json.relative_to(REPO_ROOT)),
        "width_source_path": str((benchmark.ste_dir / "STE.cpp").relative_to(REPO_ROOT)),
        "width_report_path": str(width_report.relative_to(REPO_ROOT)),
        "included_fifo_count": len(included_depths),
        "excluded_fifo_count": len(excluded_names),
        "excluded_examples": sorted(excluded_names)[:20],
        "excluded_prefix_histogram": prefix_histogram(excluded_names),
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
