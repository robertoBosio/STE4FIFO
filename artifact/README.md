# Artifact Review Notes

This directory contains helper scripts and notes for artifact evaluation.

Scripts:

- `check_environment.sh`: checks repository layout and Vitis HLS availability
- `table1/run_table1.py`: runs HLS/cosim on memory-interface kernels and prints Table I rows
- `table2/run_table2_ste.py`: runs the Table II proposed-method STE and csynth flow
- `table2/run_table2_fifoadvisor.py`: runs the Table II FIFOAdvisor comparison flow
- `table2/run_table2_resources.py`: runs the Table II resource flow
- `table3/run_table3.py`: runs the Table III observed-memory flow

Documentation:

- `table1/README.md`: Table I HLS/cosim reproduction flow

FIFOAdvisor-dependent flows are supported through
`artifact/fifoadvisor/setup_env.sh`.
