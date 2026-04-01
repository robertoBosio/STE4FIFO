# STE4FIFO

This repository contains the source code used to produce the results of\
**"One-Shot Cosimulation-Free Buffer Sizing for Large-Scale HLS Dataflow
Designs"**.

It includes benchmark networks and the corresponding kernels generated
through different FIFO sizing strategies, along with testbenches and
scripts for simulation and evaluation.

------------------------------------------------------------------------

## Repository Structure

    .
    ├── ResNet8/
    ├── ResNet20/
    ├── MobileNetV2/
    ├── YOLOv5nu/
    ├── YOLOv10n/
    ├── nn2FPGA/

-   The first five directories correspond to the **benchmarks used in
    the paper**.
-   `nn2FPGA/` contains the **operators and base infrastructure**
    derived from the nn2FPGA framework.

------------------------------------------------------------------------

## Benchmarks

Each benchmark directory (`ResNet8`, `ResNet20`, `MobileNetV2`,
`YOLOv5nu`, `YOLOv10n`) has the same internal structure:

    benchmark/
    ├── data/
    ├── kernels/
    ├── testbenches/
    ├── STE/

### `data/`

Contains: - Input data for simulation - Expected outputs (golden
references)

Used to validate correctness during simulations.

------------------------------------------------------------------------

### `kernels/`

Contains the generated kernels obtained through FIFOAdvisor exploration
using four algorithms:

-   **Bisection**
-   **Heuristic**
-   **Simulated Annealing (SA)**
-   **Group Simulated Annealing (Group-SA)**

Each kernel exists in multiple variants:

-   **Stream-based version**\
    Uses streaming interfaces and includes weight loading at startup.\
    This version is used to collect resource utilization.

    Example:

        kernel_stream_heuristic.cpp

-   **Reduced version (no weight streaming)**\
    Identical to the stream-based version but without weight loading
    logic.\
    This version is used to measure latency and Initiation Interval
    (II).

    Example:

        kernel_heuristic.cpp

-   **nn2FPGA original version**\
    Original nn2FPGA kernel with FIFOs sized using the STE technique.

    Example:

        kernel_original.cpp

-   **LightningSim version**\
    Uses memory interfaces instead of streams, since LightningSim (and
    FIFOAdvisor) do not support streaming interfaces.

    Example:

        kernel_lightning.cpp

------------------------------------------------------------------------

### `testbenches/`

Three types of testbenches are provided:

1.  **Full streaming testbench (nn2FPGA original)**
    -   Streams both inputs and weights
    -   Matches the original nn2FPGA interface
2.  **Streaming testbench without weight stream**
    -   Used for **II measurement in RTL simulation**
    -   Reduces simulation time significantly
3.  **Memory-based interface testbench**
    -   Uses memory instead of streams
    -   Required for **LightningSim**

------------------------------------------------------------------------

### `STE/` (Self-Timed Execution)

Contains the source code implementing **Self-Timed Execution (STE)** of
the network and the script to launch STE simulations.

------------------------------------------------------------------------

## nn2FPGA Components

The `nn2FPGA/` directory contains the operators used by the benchmarks.\
These components are shared across all models.

------------------------------------------------------------------------

## How to Replicate Results

1.  Select a benchmark (e.g., `ResNet20`)

2.  Choose:

    -   A kernel variant (algorithm + interface type)
    -   A corresponding testbench

3.  Run HLS synthesis and simulation:

    -   Use `csynth_design` and `export_design` to retrieve resource
        usage
    -   Use `csynth_design` and `cosim_design` to measure latency and II

4.  Optionally run STE:

        cd STE
        vitis_hls -f run_ste.tcl