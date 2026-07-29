#!/usr/bin/env bash
set -euo pipefail

if [[ "$#" -ne 1 ]]; then
  printf 'Usage: %s <benchmark>\n' "$0"
  printf 'Valid benchmarks: ResNet8 ResNet20 MobileNetV2 YOLOv5nu YOLOv10n\n'
  exit 2
fi

benchmark="$1"
repo_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

case "$benchmark" in
  ResNet8|ResNet20|MobileNetV2|YOLOv5nu|YOLOv10n) ;;
  *)
    printf 'Unknown benchmark: %s\n' "$benchmark"
    printf 'Valid benchmarks: ResNet8 ResNet20 MobileNetV2 YOLOv5nu YOLOv10n\n'
    exit 2
    ;;
esac

if ! command -v vitis_hls >/dev/null 2>&1; then
  printf 'vitis_hls not found on PATH. Source AMD Vitis HLS 2023.2 before running this script.\n'
  exit 1
fi

ste_dir="$repo_root/$benchmark/STE"
if [[ ! -f "$ste_dir/run_ste.tcl" ]]; then
  printf 'Missing STE script: %s\n' "$ste_dir/run_ste.tcl"
  exit 1
fi

printf 'Running STE for %s...\n' "$benchmark"
rm -f "$ste_dir/fifo_depth.json"
(
  cd "$ste_dir"
  vitis_hls -f run_ste.tcl
)

if [[ -f "$ste_dir/fifo_depth.json" ]]; then
  printf 'STE completed. Output: %s\n' "$ste_dir/fifo_depth.json"
else
  printf 'STE command finished, but fifo_depth.json was not produced. Check Vitis HLS logs in %s.\n' "$ste_dir"
  exit 1
fi
