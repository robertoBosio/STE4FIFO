#!/usr/bin/env python3
from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[2]
TABLE2_DIR = REPO_ROOT / "artifact" / "table2"
GENERATED_DIR = TABLE2_DIR / "generated"
RESULTS_DIR = TABLE2_DIR / "results"


@dataclass(frozen=True)
class SolverConfig:
    maxfun: int | None = None
    n_scaling_factors: int | None = None
    round_type: str | None = None
    init_with_largest: bool = False


@dataclass(frozen=True)
class Benchmark:
    name: str
    directory: str
    top: str
    part: str
    naive_size_bytes: int
    solver_configs: dict[str, SolverConfig]
    fifo_override_json: Path | None = None

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
    def ste_width_manifest(self) -> Path:
        return TABLE2_DIR / "stream_widths" / f"{self.name}.json"

    @property
    def lightning_kernel(self) -> Path:
        return self.bench_dir / "kernels" / "kernel_lightning.cpp"

    @property
    def lightning_testbench(self) -> Path:
        return self.bench_dir / "testbenches" / "testbench_lightning.cpp"

    @property
    def include_dir(self) -> Path:
        return REPO_ROOT / "nn2FPGA" / "include"

BENCHMARKS: tuple[Benchmark, ...] = (
    Benchmark(
        "ResNet8",
        "ResNet8",
        "resnet8",
        "xck26-sfvc784-2LV-c",
        1_302_694,
        {
            "bisection": SolverConfig(),
            "heuristic": SolverConfig(),
            "group-sa": SolverConfig(maxfun=10_000, n_scaling_factors=10, init_with_largest=True),
            "sa": SolverConfig(maxfun=10_000, n_scaling_factors=10, init_with_largest=True),
        },
    ),
    Benchmark(
        "ResNet20",
        "ResNet20",
        "resnet20",
        "xczu9eg-ffvb1156-2-e",
        3_753_670,
        {
            "bisection": SolverConfig(),
            "heuristic": SolverConfig(),
            "group-sa": SolverConfig(maxfun=10_000, n_scaling_factors=10, init_with_largest=True),
            "sa": SolverConfig(maxfun=10_000, n_scaling_factors=10, init_with_largest=True),
        },
        REPO_ROOT / "ResNet20" / "resnet20_critical_fifos.json",
    ),
    Benchmark(
        "MobileNetV2",
        "MobileNetV2",
        "mobilenet_v2",
        "xczu9eg-ffvb1156-2-e",
        77_669_659,
        {
            "bisection": SolverConfig(),
            "heuristic": SolverConfig(),
            "group-sa": SolverConfig(maxfun=10_000, n_scaling_factors=5, init_with_largest=True),
            "sa": SolverConfig(maxfun=10_000, n_scaling_factors=5, init_with_largest=True),
        },
    ),
    Benchmark(
        "YOLOv5nu",
        "YOLOv5nu",
        "yolov5nu",
        "xczu9eg-ffvb1156-2-e",
        252_398_688,
        {
            "bisection": SolverConfig(),
            "heuristic": SolverConfig(),
            "group-sa": SolverConfig(maxfun=10_000, n_scaling_factors=2, init_with_largest=True),
            "sa": SolverConfig(maxfun=10_000, n_scaling_factors=2, init_with_largest=True),
        },
    ),
    Benchmark(
        "YOLOv10n",
        "YOLOv10n",
        "yolov10n",
        "xczu9eg-ffvb1156-2-e",
        234_185_011,
        {
            "bisection": SolverConfig(),
            "heuristic": SolverConfig(),
            "group-sa": SolverConfig(maxfun=10_000, n_scaling_factors=2, init_with_largest=True),
            "sa": SolverConfig(maxfun=10_000, n_scaling_factors=2, init_with_largest=True),
        },
        REPO_ROOT / "YOLOv10n" / "yolov10n_critical_fifos.json",
    ),
)

SOLVERS: tuple[str, ...] = ("bisection", "heuristic", "group-sa", "sa")
RESOURCE_TECHNIQUES: tuple[str, ...] = ("our_method",) + SOLVERS
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


def resource_technique_names() -> list[str]:
    return list(RESOURCE_TECHNIQUES)


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


def select_resource_techniques(names: list[str] | None) -> list[str]:
    if not names:
        return list(RESOURCE_TECHNIQUES)

    selected = []
    for name in names:
        if name not in RESOURCE_TECHNIQUES:
            valid = ", ".join(RESOURCE_TECHNIQUES)
            raise SystemExit(f"Unknown technique '{name}'. Valid techniques: {valid}")
        selected.append(name)
    return selected


def raw_fifoadvisor_dir(benchmark: Benchmark) -> Path:
    return RESULTS_DIR / "raw" / "fifoadvisor" / benchmark.name


def normalized_dir(benchmark: Benchmark) -> Path:
    return RESULTS_DIR / "normalized" / benchmark.name


def normalized_path(benchmark: Benchmark, technique: str) -> Path:
    return normalized_dir(benchmark) / f"{technique}.json"


def resource_kernel_path(benchmark: Benchmark, technique: str) -> Path:
    if technique == "our_method":
        name = "kernel_original.cpp"
    else:
        name = f"kernel_stream_{technique}.cpp"
    return benchmark.bench_dir / "kernels" / name


def resource_testbench_path(benchmark: Benchmark) -> Path:
    return benchmark.bench_dir / "testbenches" / "testbench_original.cpp"


def raw_resource_dir(benchmark: Benchmark) -> Path:
    return RESULTS_DIR / "raw" / "resources" / benchmark.name


def resource_project_dir(benchmark: Benchmark, technique: str) -> Path:
    return GENERATED_DIR / benchmark.name / f"{benchmark.top}_table2_{technique}_resources_HLS_project"


def resource_solution_dir(benchmark: Benchmark, technique: str) -> Path:
    return resource_project_dir(benchmark, technique) / "solution_0"


def resource_csynth_report_path(benchmark: Benchmark, technique: str) -> Path:
    return resource_solution_dir(benchmark, technique) / "syn" / "report" / f"{benchmark.top}_csynth.rpt"


def hls_project_dir(benchmark: Benchmark) -> Path:
    return GENERATED_DIR / benchmark.name / f"{benchmark.top}_table2_lightning_HLS_project"


def hls_solution_dir(benchmark: Benchmark) -> Path:
    return hls_project_dir(benchmark) / "solution_0"
