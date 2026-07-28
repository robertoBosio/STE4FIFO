#!/usr/bin/env bash
set -eu

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/../../.." && pwd)"

docker build \
  --build-arg HOST_UID="$(id -u)" \
  --build-arg HOST_GID="$(id -g)" \
  --build-arg USERNAME="$(id -un)" \
  -t ste4fifo-ubuntu22-vitis \
  -f "${SCRIPT_DIR}/Dockerfile" \
  "${REPO_ROOT}"
