#!/usr/bin/env bash
set -euo pipefail

repo_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

required_paths=(
  "README.md"
  "INSTALL"
  "REQUIREMENTS"
  "STATUS"
  "LICENSE"
  "ESWEEK_FIFO2026_MAIN_RESPONSE.pdf"
  "nn2FPGA/include"
  "ResNet8/STE/run_ste.tcl"
  "ResNet20/STE/run_ste.tcl"
  "MobileNetV2/STE/run_ste.tcl"
  "YOLOv5nu/STE/run_ste.tcl"
  "YOLOv10n/STE/run_ste.tcl"
)

missing=0
for path in "${required_paths[@]}"; do
  if [[ ! -e "$repo_root/$path" ]]; then
    printf 'missing: %s\n' "$path"
    missing=1
  fi
done

if [[ "$missing" -ne 0 ]]; then
  printf 'Repository layout check failed.\n'
  exit 1
fi

printf 'Repository layout check passed.\n'

if command -v vitis_hls >/dev/null 2>&1; then
  printf 'vitis_hls found: %s\n' "$(command -v vitis_hls)"
else
  printf 'vitis_hls not found on PATH. Install/source AMD Vitis HLS 2023.2 to run STE flows.\n'
fi
