# Expected STE Results

The following values are the proposed-method FIFO memory sizes reported in
Table II of the paper. They are the primary numeric results targeted by the
included STE artifact.

| Benchmark | Expected proposed-method FIFO size |
| --- | ---: |
| ResNet8 | 39,809 B |
| ResNet20 | 57,952 B |
| MobileNetV2 | 341,344 B |
| YOLOv5nu | 1,465,118 B |
| YOLOv10n | 1,932,470 B |

Run an STE model with:

```bash
artifact/run_ste.sh ResNet8
```

The run emits a per-FIFO depth report at:

```text
<benchmark>/STE/fifo_depth.json
```

The table reports the aggregate FIFO memory footprint after applying the paper's
FIFO sizing methodology to the generated HLS design. The JSON file contains the
per-channel depths used to derive those aggregate sizes.
