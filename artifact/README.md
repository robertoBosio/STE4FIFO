# Artifact Review Notes

This directory contains helper scripts and notes for artifact evaluation.

Scripts:

- `check_environment.sh`: checks repository layout and Vitis HLS availability
- `run_ste.sh`: runs the STE model for one benchmark
- `table1/run_table1.py`: runs HLS/cosim on memory-interface kernels and prints Table I rows

Documentation:

- `expected_ste_results.md`: expected proposed-method FIFO sizes from Table II
- `table1/README.md`: Table I HLS/cosim reproduction flow
- `table_coverage.md`: what paper results are supported by this artifact

The scripts intentionally avoid FIFOAdvisor and LightningSim because those flows
are not bundled with this artifact.
