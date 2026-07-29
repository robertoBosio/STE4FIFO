# Table I Reproduction

`run_table1.py` has a reviewer-facing interface with two modes:

- run HLS/cosim and print Table I rows
- parse existing reports with `--parse-only`

Generated TCL scripts are written under `artifact/table1/generated/`.

From the repository root:

```bash
artifact/table1/run_table1.py
```

To run one benchmark:

```bash
artifact/table1/run_table1.py ResNet8
```

MobileNetV2 and the YOLO benchmarks can take days to complete in HLS/cosim,
depending on the machine and Vitis installation.

To print a table from existing reports without rerunning HLS:

```bash
artifact/table1/run_table1.py --parse-only
```
