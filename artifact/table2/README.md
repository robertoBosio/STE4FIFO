# Table II Size/Time Flow

This directory contains the size/time-only reproduction flow for Table II.
Resource columns are intentionally excluded because they require `export_design`
and Vivado implementation runs.

## What Is Regenerated

- `Our method`: runs the included STE model for timing and reads the total FIFO
  size from the `kernel_original.cpp` C synthesis report.
- FIFOAdvisor methods: runs FIFOAdvisor on an HLS solution built from
  `kernels/kernel_lightning.cpp`.
- The collector reports naive size, final time, final size, and size delta.

## Usage

Generate the FIFOAdvisor HLS solution and observed-depth report for one benchmark:

```bash
artifact/table2/run_table2_fifoadvisor.py --benchmark ResNet8 --observed-depths-only
```

Run all FIFOAdvisor Table II solvers for one benchmark:

```bash
artifact/table2/run_table2_fifoadvisor.py --benchmark ResNet8
```

Run and normalize the STE result for one benchmark:

```bash
artifact/table2/run_table2_ste.py --benchmark ResNet8
```

Collect available normalized results:

```bash
artifact/table2/collect_table2.py
```

Outputs are written under `artifact/table2/results/`.

## Rerun Policy

The runner scripts rerun their tool steps by default. Existing raw FIFOAdvisor
JSON files are removed before a solver is rerun. Use `--parse-only` with the STE
script only when you explicitly want to normalize an existing `fifo_depth.json`.

## Notes

- `Our method` keeps STE as the timing source, but derives FIFO memory size from
  the `Total` row of `solution_0/syn/report/<top>_csynth.rpt` for
  `kernels/kernel_original.cpp`.
- The csynth report stores the total FIFO size in bits. This flow converts that
  value to bytes with round-up division.
- MobileNetV2 and YOLO runs can be long. Validate changes on ResNet8 first.
