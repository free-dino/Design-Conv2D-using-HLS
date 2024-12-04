# ==============================================================
# File generated on Wed Dec 04 15:48:44 +0700 2024
# Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
# SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
# IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
# Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
# ==============================================================
add_files -tb ../testbench.c -cflags { -Wno-unknown-pragmas}
add_files Convolution2D/convolution2D.h
add_files Convolution2D/convolution2D.c
set_part xc7z020clg484-1
create_clock -name default -period 10
