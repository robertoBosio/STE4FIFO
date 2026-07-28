# Ubuntu 22.04 Docker Environment

This optional container provides an Ubuntu 22.04 userspace with basic build tools. It does not include Vitis HLS, Vivado, Xilinx licenses, STE4FIFO source, FIFOAdvisor source, or conda.

Build the image from the STE4FIFO repository root:

```bash
artifact/docker/ubuntu22-vitis/build.sh
```

Start the container:

```bash
artifact/docker/ubuntu22-vitis/run.sh
```

The run script mounts the current STE4FIFO checkout at `/workspace/STE4FIFO` and mounts `/tools/Xilinx` read-only at `/tools/Xilinx`. If your Xilinx installation is elsewhere, set `VITIS_MOUNT`:

```bash
VITIS_MOUNT=/path/to/Xilinx artifact/docker/ubuntu22-vitis/run.sh
```

The run script mounts `artifact/docker/ubuntu22-vitis/.home` as the container home directory, so Miniforge and conda environments persist across container restarts.

Inside or outside the container, use the same setup script:

```bash
source artifact/fifoadvisor/setup_env.sh
```

The script installs Miniforge into the mounted home directory if needed, creates `fifo-advisor-ste4fifo` if needed, activates it, and installs the patched FIFOAdvisor fork if needed.

On later container restarts, run:

```bash
source artifact/fifoadvisor/setup_env.sh
```

The image is built with the current host UID/GID, so files created in the mounted repository are owned by the current user.
