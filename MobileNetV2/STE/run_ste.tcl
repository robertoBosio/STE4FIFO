open_project -reset "hls_proj_ste"
open_solution -reset "solution0"
add_files STE.cpp -cflags "-O2 -I../../nn2FPGA/include"
add_files -tb testbench.cpp -cflags "-I../../nn2FPGA/include"
set_top "resnet20"
set_part xck26-sfvc784-2LV-c
create_clock -period 5.00ns
csim_design
exit