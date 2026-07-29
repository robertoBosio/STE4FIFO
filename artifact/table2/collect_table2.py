#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
from pathlib import Path

from benchmarks import (
    RESULTS_DIR,
    SOLVERS,
    TECHNIQUE_LABELS,
    normalized_path,
    select_benchmarks,
)


ORDER = ("our_method", "bisection", "heuristic", "group-sa", "sa")


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Collect normalized Table II size/time results.")
    parser.add_argument("--benchmark", action="append", help="Benchmark to collect. May be repeated.")
    return parser


def load_result(benchmark, technique: str) -> dict | None:
    path = normalized_path(benchmark, technique)
    if not path.exists():
        return None
    return json.loads(path.read_text())


def format_int(value: int | None) -> str:
    return "" if value is None else f"{value:,}"


def format_time(value: float | None) -> str:
    if value is None:
        return ""
    if value >= 100:
        return f"{value:.0f}"
    if value >= 10:
        return f"{value:.1f}"
    return f"{value:.2f}"


def format_delta(value: float | None) -> str:
    if value is None:
        return "-"
    return f"{value:.1f}"


def collect(benchmarks) -> dict:
    rows = []
    for benchmark in benchmarks:
        available = [result for tech in ORDER if (result := load_result(benchmark, tech))]
        best_size = min((row["final_size_bytes"] for row in available), default=None)
        for technique in ORDER:
            result = load_result(benchmark, technique)
            if result is None:
                continue
            size = result["final_size_bytes"]
            delta = None if best_size in (None, 0) or size == best_size else (size - best_size) / best_size * 100.0
            rows.append(
                {
                    "benchmark": benchmark.name,
                    "naive_size_bytes": benchmark.naive_size_bytes,
                    "technique": technique,
                    "technique_label": TECHNIQUE_LABELS[technique],
                    "final_time_seconds": result["final_time_seconds"],
                    "final_size_bytes": size,
                    "delta_size_percent": delta,
                    "lut": result.get("lut"),
                    "ff": result.get("ff"),
                    "dsp": result.get("dsp"),
                    "bram": result.get("bram"),
                    "source_path": result.get("source_path"),
                }
            )
    return {"rows": rows}


def write_markdown(payload: dict) -> Path:
    out = RESULTS_DIR / "table2_size_time.md"
    out.parent.mkdir(parents=True, exist_ok=True)
    lines = [
        "# Table II Size/Time Results",
        "",
        "| Model | Naive size (B) | Technique | Final time (s) | size (B) | Delta size (%) | LUT | FF | DSP | BRAM |",
        "| --- | ---: | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |",
    ]
    for row in payload["rows"]:
        lines.append(
            "| {benchmark} | {naive} | {technique} | {time} | {size} | {delta} | {lut} | {ff} | {dsp} | {bram} |".format(
                benchmark=row["benchmark"],
                naive=format_int(row["naive_size_bytes"]),
                technique=row["technique_label"],
                time=format_time(row["final_time_seconds"]),
                size=format_int(row["final_size_bytes"]),
                delta=format_delta(row["delta_size_percent"]),
                lut=format_int(row["lut"]),
                ff=format_int(row["ff"]),
                dsp=format_int(row["dsp"]),
                bram=format_int(row["bram"]),
            )
        )
    out.write_text("\n".join(lines) + "\n")
    return out


def main() -> None:
    args = build_parser().parse_args()
    payload = collect(select_benchmarks(args.benchmark))
    path = write_markdown(payload)
    print(f"Wrote {path}")


if __name__ == "__main__":
    main()
