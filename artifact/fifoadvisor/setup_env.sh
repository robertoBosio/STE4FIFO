#!/usr/bin/env bash
set -eu

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/../.." && pwd)"
ENV_FILE="${REPO_ROOT}/artifact/fifoadvisor/environment.yml"

MINIFORGE_DIR="${MINIFORGE_DIR:-${HOME}/miniforge3}"
ENV_NAME="${ENV_NAME:-fifo-advisor-ste4fifo}"
FIFO_ADVISOR_URL="${FIFO_ADVISOR_URL:-https://github.com/robertoBosio/fifo-advisor.git}"

if command -v conda >/dev/null 2>&1; then
  CONDA_BASE="$(conda info --base)"
elif [ -f "${MINIFORGE_DIR}/etc/profile.d/conda.sh" ]; then
  CONDA_BASE="${MINIFORGE_DIR}"
else
  installer=/tmp/Miniforge3-Linux-x86_64.sh
  if command -v wget >/dev/null 2>&1; then
    wget -O "${installer}" \
      https://github.com/conda-forge/miniforge/releases/latest/download/Miniforge3-Linux-x86_64.sh
  elif command -v curl >/dev/null 2>&1; then
    curl -fsSL \
      https://github.com/conda-forge/miniforge/releases/latest/download/Miniforge3-Linux-x86_64.sh \
      -o "${installer}"
  else
    echo "Neither conda, wget, nor curl is available. Install conda manually first." >&2
    return 1 2>/dev/null || exit 1
  fi
  bash "${installer}" -b -p "${MINIFORGE_DIR}"
  rm -f "${installer}"
  CONDA_BASE="${MINIFORGE_DIR}"
fi

# shellcheck disable=SC1090
source "${CONDA_BASE}/etc/profile.d/conda.sh"

if ! conda env list | awk '{print $1}' | grep -qx "${ENV_NAME}"; then
  conda env create -f "${ENV_FILE}"
fi

conda activate "${ENV_NAME}"

if [ -n "${FIFO_ADVISOR_DIR:-}" ] && [ -d "${FIFO_ADVISOR_DIR}" ]; then
  python -m pip install --no-deps -e "${FIFO_ADVISOR_DIR}"
elif ! python -c "import fifo_advisor" >/dev/null 2>&1; then
  python -m pip install --no-deps "git+${FIFO_ADVISOR_URL}"
fi

echo "Activated ${ENV_NAME}."
echo "Python: $(command -v python)"
