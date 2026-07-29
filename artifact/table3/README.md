# Table III Reproduction

`run_table3.py` has the same reviewer-facing style as the Table I script:

- run HLS plus FIFOAdvisor and print Table III rows
- parse existing reports with `--parse-only`

Generated TCL scripts and HLS projects are written under `artifact/table3/generated/`.
Observed-depth reports and normalized summaries are written under `artifact/table3/results/`.

Before running the script, activate the FIFOAdvisor environment:

```bash
source artifact/fifoadvisor/setup_env.sh
```

From the repository root:

```bash
artifact/table3/run_table3.py
```

To run one benchmark:

```bash
artifact/table3/run_table3.py --benchmark ResNet8
```

To print the table from existing observed-depth reports without rerunning HLS or FIFOAdvisor:

```bash
artifact/table3/run_table3.py --parse-only
```

The script reads `observed_memory_bytes` directly from each benchmark's observed-depth JSON report.
