############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project Convolution2D
set_top convolution2D
add_files Convolution2D/convolution2D.c
add_files Convolution2D/convolution2D.h
add_files -tb Convolution2D/testbench.c -cflags "-Wno-unknown-pragmas"
open_solution "solution1"
set_part {xc7z020clg484-1} -tool vivado
create_clock -period 10 -name default
config_export -display_name convolution2D -format ip_catalog -rtl vhdl -version 0.0.0
#source "./Convolution2D/solution1/directives.tcl"
csim_design
csynth_design
cosim_design -trace_level all -rtl vhdl
export_design -rtl vhdl -format ip_catalog -version "0.0.0" -display_name "convolution2D"
