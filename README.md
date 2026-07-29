# STE4FIFO Artifact

This repository contains the artifact for:

**One-Shot Cosimulation-Free Buffer Sizing for Large-Scale HLS Dataflow Designs**


## Requirements At A Glance

- AMD Vitis HLS 2023.2 is required for all reproduced results.
- Vivado and a ZCU102 license are required for reproducing the Table II
  resource section.
- A Linux x86_64 machine with 128 GB RAM and at least 0.5 TB of available
  disk space is recommended.
- FIFOAdvisor-dependent flows are supported through
  `artifact/fifoadvisor/setup_env.sh`.
- An optional Docker environment is provided under
  `artifact/docker/ubuntu22-vitis/`.

## Artifact Scope

Included:

- STE source code for each benchmark model
- generated HLS kernels for the proposed method and comparison techniques
- testbenches and input/golden-output data used by the benchmark kernels
- shared nn2FPGA-derived HLS operator headers
- documentation required for artifact evaluation
- reproduction scripts for the reported table flows
- an optional Dockerfile and container launch scripts for the review environment

The artifact supports regeneration of the reported results through documented
workflows with different tool requirements depending on the table and metric.
FIFOAdvisor-dependent flows are installed automatically through the provided
setup script rather than being vendored directly in the main repository.

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

## Quick Verification

Check the local environment:

```bash
artifact/check_environment.sh
```

Run the STE model for a single benchmark:

```bash
vitis_hls -f ResNet8/STE/run_ste.tcl
```

The STE run writes `fifo_depth.json` in the selected benchmark's `STE/`
directory, for example `ResNet8/STE/fifo_depth.json`.

This JSON file contains the per-FIFO depth output used by the Table II
proposed-method flow.

## Kernel Variants

The `kernels/` directory of each benchmark contains variants for several FIFO
sizing techniques:

- `kernel_original.cpp`: original nn2FPGA-style kernel
- `kernel_stream_heuristic.cpp`: FIFOAdvisor heuristic-sized kernel
- `kernel_stream_bisection.cpp`: bisection-sized kernel
- `kernel_stream_sa.cpp`: simulated-annealing-sized kernel
- `kernel_stream_group-sa.cpp`: grouped simulated-annealing-sized kernel
- `kernel_lightning.cpp`: memory-interface variants used for external tools

These generated kernels are provided so reviewers can inspect the resulting FIFO
depth annotations and run selected HLS flows if desired.

## Result Reproduction Matrix

| Result | Command path | Required tools |
| --- | --- | --- |
| Table I process, FIFO, latency, and II rows | `artifact/table1/run_table1.py` | AMD Vitis HLS 2023.2 |
| Table II proposed-method FIFO size and timing rows | `artifact/table2/run_table2_ste.py` | AMD Vitis HLS 2023.2 |
| Table II FIFOAdvisor comparison rows | `artifact/table2/run_table2_fifoadvisor.py` | AMD Vitis HLS 2023.2, FIFOAdvisor setup |
| Table II resource section | `artifact/table2/run_table2_resources.py` | AMD Vitis HLS 2023.2, Vivado, ZCU102 license |
| Table III observed FIFO memory comparison | `artifact/table3/run_table3.py` | AMD Vitis HLS 2023.2, FIFOAdvisor setup |

## Tool-Specific Setup

FIFOAdvisor is not stored as source code in the main repository. The artifact
provides an automated setup script:

```bash
source artifact/fifoadvisor/setup_env.sh
```

This script creates the required environment and installs FIFOAdvisor
automatically. It also installs the LightningSim package declared in
`artifact/fifoadvisor/environment.yml`.

An optional Docker environment is also provided under
`artifact/docker/ubuntu22-vitis/`. It offers an Ubuntu userspace and helper
scripts for running the artifact with host-mounted Xilinx tools.

## Reproducing Table I

Run the Table I HLS/cosim flow:

```bash
artifact/table1/run_table1.py
```

To print Table I rows from existing reports without rerunning HLS:

```bash
artifact/table1/run_table1.py --parse-only
```

Generated TCL scripts and HLS projects are written under `artifact/table1/generated/`.

The script prints the Table I rows directly from the generated reports. The
supporting cosimulation and synthesis reports used to collect those values are
stored under `artifact/table1/generated/`.

MobileNetV2 and the YOLO benchmarks can take days to complete in HLS/cosim,
depending on the machine and Vitis installation.

## Reproducing Table II

Run the proposed-method FIFO size and timing flow:

```bash
artifact/table2/run_table2_ste.py --benchmark ResNet8
```

Run the FIFOAdvisor comparison flow:

```bash
artifact/table2/run_table2_fifoadvisor.py --benchmark ResNet8
```

Run the resource-oriented flow:

```bash
artifact/table2/run_table2_resources.py --benchmark ResNet8
```

The Table II resource section requires Vivado and a ZCU102 license.

Generated HLS projects and implementation reports are written under
`artifact/table2/generated/`.

Collected Table II outputs are written under `artifact/table2/results/`:

- normalized per-benchmark summaries: `artifact/table2/results/normalized/`
- raw FIFOAdvisor outputs: `artifact/table2/results/raw/fifoadvisor/`
- raw resource summaries: `artifact/table2/results/raw/resources/`

Use `artifact/table2/collect_table2.py` to read the normalized outputs and
print the collected Table II rows.

## Reproducing Table III

Activate the FIFOAdvisor environment first:

```bash
source artifact/fifoadvisor/setup_env.sh
```

Then run:

```bash
artifact/table3/run_table3.py --benchmark ResNet8
```

Generated HLS projects are written under `artifact/table3/generated/`.

Collected Table III outputs are written under `artifact/table3/results/`:

- raw observed-depth reports: `artifact/table3/results/raw/`
- normalized per-benchmark summaries: `artifact/table3/results/normalized/`

The script prints the Table III rows and also stores the normalized JSON
summaries in `artifact/table3/results/normalized/`.

## Requirements

Running the included flows requires AMD Vitis HLS 2023.2. Table II resource
reproduction additionally requires Vivado and a ZCU102 license.

See `REQUIREMENTS` and `INSTALL` for details.

## License

This artifact is released under the MIT License. See `LICENSE`.
