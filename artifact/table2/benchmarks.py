#!/usr/bin/env python3
from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[2]
TABLE2_DIR = REPO_ROOT / "artifact" / "table2"
GENERATED_DIR = TABLE2_DIR / "generated"
RESULTS_DIR = TABLE2_DIR / "results"


@dataclass(frozen=True)
class Benchmark:
    name: str
    directory: str
    top: str
    part: str
    naive_size_bytes: int

    @property
    def bench_dir(self) -> Path:
        return REPO_ROOT / self.directory

    @property
    def ste_dir(self) -> Path:
        return self.bench_dir / "STE"

    @property
    def ste_json(self) -> Path:
        return self.ste_dir / "fifo_depth.json"

    @property
    def lightning_kernel(self) -> Path:
        return self.bench_dir / "kernels" / "kernel_lightning.cpp"

    @property
    def lightning_testbench(self) -> Path:
        return self.bench_dir / "testbenches" / "testbench_lightning.cpp"

    @property
    def include_dir(self) -> Path:
        return REPO_ROOT / "nn2FPGA" / "include"

    @property
    def fifo_override_json(self) -> Path:
        slug = self.name.lower()
        return REPO_ROOT / "artifact" / "fifoadvisor" / "depth_overrides" / f"{slug}.json"


BENCHMARKS: tuple[Benchmark, ...] = (
    Benchmark("ResNet8", "ResNet8", "resnet8", "xck26-sfvc784-2LV-c", 1_302_694),
    Benchmark("ResNet20", "ResNet20", "resnet20", "xczu9eg-ffvb1156-2-e", 3_753_670),
    Benchmark("MobileNetV2", "MobileNetV2", "mobilenet_v2", "xczu9eg-ffvb1156-2-e", 77_669_659),
    Benchmark("YOLOv5nu", "YOLOv5nu", "yolov5nu", "xczu9eg-ffvb1156-2-e", 252_398_688),
    Benchmark("YOLOv10n", "YOLOv10n", "yolov10n", "xczu9eg-ffvb1156-2-e", 234_185_011),
)

SOLVERS: tuple[str, ...] = ("bisection", "heuristic", "group-sa", "sa")
TECHNIQUE_LABELS = {
    "our_method": "Our method",
    "bisection": "Bisection",
    "heuristic": "Heuristic",
    "group-sa": "Grouped SA",
    "sa": "SA",
}


def benchmark_names() -> list[str]:
    return [benchmark.name for benchmark in BENCHMARKS]


def solver_names() -> list[str]:
    return list(SOLVERS)


def select_benchmarks(names: list[str] | None) -> list[Benchmark]:
    if not names:
        return list(BENCHMARKS)

    by_name = {benchmark.name: benchmark for benchmark in BENCHMARKS}
    selected = []
    for name in names:
        if name not in by_name:
            valid = ", ".join(benchmark_names())
            raise SystemExit(f"Unknown benchmark '{name}'. Valid benchmarks: {valid}")
        selected.append(by_name[name])
    return selected


def select_solvers(names: list[str] | None) -> list[str]:
    if not names:
        return list(SOLVERS)

    selected = []
    for name in names:
        if name not in SOLVERS:
            valid = ", ".join(SOLVERS)
            raise SystemExit(f"Unknown solver '{name}'. Valid solvers: {valid}")
        selected.append(name)
    return selected


def raw_fifoadvisor_dir(benchmark: Benchmark) -> Path:
    return RESULTS_DIR / "raw" / "fifoadvisor" / benchmark.name


def normalized_dir(benchmark: Benchmark) -> Path:
    return RESULTS_DIR / "normalized" / benchmark.name


def normalized_path(benchmark: Benchmark, technique: str) -> Path:
    return normalized_dir(benchmark) / f"{technique}.json"


def hls_project_dir(benchmark: Benchmark) -> Path:
    return GENERATED_DIR / benchmark.name / f"{benchmark.top}_table2_lightning_HLS_project"


def hls_solution_dir(benchmark: Benchmark) -> Path:
    return hls_project_dir(benchmark) / "solution_0"
