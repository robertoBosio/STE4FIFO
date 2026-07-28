#!/usr/bin/env bash
set -eu

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/../../.." && pwd)"
VITIS_MOUNT="${VITIS_MOUNT:-/tools/Xilinx}"
VITIS_HLS_SETTINGS="${VITIS_HLS_SETTINGS:-/tools/Xilinx/Vitis_HLS/2023.2/.settings64-Vitis_HLS.sh}"
CONTAINER_USER="$(id -un)"
CONTAINER_HOME="${SCRIPT_DIR}/.home"

mkdir -p "${CONTAINER_HOME}"

docker_args=(
  --rm
  -it
  -e "HOME=/home/${CONTAINER_USER}"
  -e "VITIS_HLS_SETTINGS=${VITIS_HLS_SETTINGS}"
  -e "XILINXD_LICENSE_FILE=${XILINXD_LICENSE_FILE:-}"
  -v "${CONTAINER_HOME}:/home/${CONTAINER_USER}"
  -v "${REPO_ROOT}:/workspace/STE4FIFO"
  -v "${VITIS_MOUNT}:/tools/Xilinx:ro"
  -w /workspace/STE4FIFO
)

if [ -n "${FIFO_ADVISOR_DIR:-}" ]; then
  docker_args+=(
    -e "FIFO_ADVISOR_DIR=/workspace/fifo-advisor"
    -v "${FIFO_ADVISOR_DIR}:/workspace/fifo-advisor"
  )
fi

docker run "${docker_args[@]}" ste4fifo-ubuntu22-vitis "$@"
