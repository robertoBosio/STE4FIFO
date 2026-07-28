# STE4FIFO Artifact

This repository contains the artifact for:

**One-Shot Cosimulation-Free Buffer Sizing for Large-Scale HLS Dataflow Designs**

The artifact focuses on the core contribution of the paper: Self-Timed
Execution (STE) models used to compute FIFO sizes for large HLS dataflow
designs. It also includes generated HLS kernel variants sized by the proposed
method and by comparison techniques.

The accepted paper PDF is included as `ESWEEK_FIFO2026_MAIN_RESPONSE.pdf`.

## Artifact Scope

Included:

- STE source code for each benchmark model
- Generated HLS kernels for the proposed method and comparison techniques
- Testbenches and input/golden-output data used by the benchmark kernels
- Shared nn2FPGA-derived HLS operator headers
- Documentation required for artifact evaluation

Not included:

- FIFOAdvisor installation and exploration flow
- LightningSim installation and instrumentation flow
- Full C/RTL cosimulation or FPGA deployment automation

The artifact is intended to support inspection and execution of the included
STE models. It can regenerate the proposed-method FIFO sizes reported in Table
II and provides a dedicated HLS/cosim script for Table I. It does not fully
regenerate FIFOAdvisor exploration times or Table III LightningSim comparisons.

## Repository Structure

```text
.
├── artifact/                         # Review scripts and result notes
├── ResNet8/                          # Benchmark source, data, kernels, STE
├── ResNet20/
├── MobileNetV2/
├── YOLOv5nu/
├── YOLOv10n/
├── nn2FPGA/                          # Shared HLS operator headers
├── ESWEEK_FIFO2026_MAIN_RESPONSE.pdf
├── INSTALL
├── LICENSE
├── REQUIREMENTS
└── STATUS
```

Each benchmark directory has the following layout:

```text
benchmark/
├── data/                             # Input data and golden references
├── kernels/                          # Generated HLS kernels
├── testbenches/                      # HLS testbenches
├── STE/                              # Self-Timed Execution model
└── script.tcl                        # Vitis HLS project script
```

## Benchmarks

The artifact contains the five DNN benchmarks used in the paper:

- `ResNet8`
- `ResNet20`
- `MobileNetV2`
- `YOLOv5nu`
- `YOLOv10n`

The HLS source code for the benchmark designs was generated from nn2FPGA-based
flows and then modified to instantiate FIFO depths from the evaluated sizing
techniques.

## Kernel Variants

The `kernels/` directory of each benchmark contains variants for several FIFO
sizing techniques:

- `kernel_original.cpp`: original nn2FPGA-style kernel
- `kernel_heuristic.cpp`: FIFOAdvisor heuristic-sized kernel
- `kernel_bisection.cpp`: bisection-sized kernel
- `kernel_sa.cpp`: simulated-annealing-sized kernel
- `kernel_group-sa.cpp`: grouped simulated-annealing-sized kernel
- `kernel_mem.cpp` or `kernel_lightning.cpp`: memory-interface variants used for external tools
- `kernel_stream_*.cpp`: stream-interface variants used for resource-oriented HLS runs

These generated kernels are provided so reviewers can inspect the resulting FIFO
depth annotations and run selected HLS flows if desired.

## Quick Start

Check the local environment:

```bash
artifact/check_environment.sh
```

Run the STE model for a single benchmark:

```bash
artifact/run_ste.sh ResNet8
```

The STE run writes `fifo_depth.json` in the selected benchmark's `STE/`
directory, for example `ResNet8/STE/fifo_depth.json`.

Expected proposed-method FIFO sizes are listed in
`artifact/expected_ste_results.md`.

Run the Table I HLS/cosim flow:

```bash
artifact/table1/run_table1.py
```

MobileNetV2 and the YOLO benchmarks can take days to complete in HLS/cosim,
depending on the machine and Vitis installation.

## Requirements

Running the included HLS/STE flows requires AMD Vitis HLS 2023.2 or a compatible
installation that provides the HLS headers and `vitis_hls` executable.

See `REQUIREMENTS` and `INSTALL` for details.

## Paper Result Coverage

The artifact intentionally separates the included core STE flow from results
that require additional third-party infrastructure. See
`artifact/table_coverage.md` for a table-by-table summary.

In short:

- Table II proposed-method FIFO sizes: supported by the included STE code
- Table II FIFOAdvisor exploration times: not regenerated here
- Table I process/FIFO/latency/II rows: supported by `artifact/table1/run_table1.py`
- Table III LightningSim comparison: not regenerated here

## License

This artifact is released under the MIT License. See `LICENSE`.
