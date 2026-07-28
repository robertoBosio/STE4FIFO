FROM ubuntu:22.04

ARG DEBIAN_FRONTEND=noninteractive
ARG HOST_UID=1000
ARG HOST_GID=1000
ARG USERNAME=ste4fifo

ENV DEBIAN_FRONTEND=${DEBIAN_FRONTEND}

RUN apt-get update && apt-get install -y --no-install-recommends \
    bash \
    bzip2 \
    ca-certificates \
    cmake \
    curl \
    git \
    gzip \
    libgtk2.0-0 \
    libnss3 \
    libtinfo5 \
    libxcursor1 \
    libxi6 \
    libxinerama1 \
    libxrandr2 \
    libxrender1 \
    libxtst6 \
    locales \
    make \
    pkg-config \
    python3 \
    unzip \
    wget \
    zip \
    build-essential \
    && rm -rf /var/lib/apt/lists/*

RUN sed -i 's/# *en_US.UTF-8 UTF-8/en_US.UTF-8 UTF-8/' /etc/locale.gen \
    && locale-gen \
    && update-locale LANG=en_US.UTF-8 LC_ALL=en_US.UTF-8

ENV LANG=en_US.UTF-8 \
    LC_ALL=en_US.UTF-8 \
    LANGUAGE=en_US:en

RUN groupadd --gid ${HOST_GID} ${USERNAME} \
    && useradd --uid ${HOST_UID} --gid ${HOST_GID} --create-home --shell /bin/bash ${USERNAME} \
    && mkdir -p /workspace \
    && chown -R ${HOST_UID}:${HOST_GID} /workspace

RUN cat > /usr/local/bin/ste4fifo-entrypoint <<'EOF'
#!/usr/bin/env bash
set -eu

if [ -n "${VITIS_HLS_SETTINGS:-}" ] && [ -f "${VITIS_HLS_SETTINGS}" ]; then
  # shellcheck disable=SC1090
  source "${VITIS_HLS_SETTINGS}"
fi

exec "$@"
EOF

RUN chmod +x /usr/local/bin/ste4fifo-entrypoint

USER ${USERNAME}
WORKDIR /workspace/STE4FIFO

ENTRYPOINT ["/usr/local/bin/ste4fifo-entrypoint"]
CMD ["bash"]
