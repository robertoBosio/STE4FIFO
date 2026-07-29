open_project -reset "hls_proj_ste"
open_solution -reset "solution0"
set script_dir [file dirname [file normalize [info script]]]
set ::env(STE_FIFO_DEPTH_JSON) [file normalize [file join $script_dir fifo_depth.json]]
add_files STE.cpp -cflags "-O2 -I../../nn2FPGA/include"
add_files -tb testbench.cpp -cflags "-I../../nn2FPGA/include"
set_top "mobilenet_v2"
set_part xck26-sfvc784-2LV-c
create_clock -period 5.00ns
csim_design -O
exit
