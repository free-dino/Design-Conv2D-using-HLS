// ==============================================================
// File generated on Wed Dec 18 21:02:53 +0700 2024
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
// conv_io
// 0x000 : Control signals
//         bit 0  - ap_start (Read/Write/COH)
//         bit 1  - ap_done (Read/COR)
//         bit 2  - ap_idle (Read)
//         bit 3  - ap_ready (Read)
//         bit 7  - auto_restart (Read/Write)
//         others - reserved
// 0x004 : Global Interrupt Enable Register
//         bit 0  - Global Interrupt Enable (Read/Write)
//         others - reserved
// 0x008 : IP Interrupt Enable Register (Read/Write)
//         bit 0  - Channel 0 (ap_done)
//         bit 1  - Channel 1 (ap_ready)
//         others - reserved
// 0x00c : IP Interrupt Status Register (Read/TOW)
//         bit 0  - Channel 0 (ap_done)
//         bit 1  - Channel 1 (ap_ready)
//         others - reserved
// 0x0e0 : Data signal of kernel_0_0
//         bit 31~0 - kernel_0_0[31:0] (Read/Write)
// 0x0e4 : reserved
// 0x0e8 : Data signal of kernel_0_1
//         bit 31~0 - kernel_0_1[31:0] (Read/Write)
// 0x0ec : reserved
// 0x0f0 : Data signal of kernel_0_2
//         bit 31~0 - kernel_0_2[31:0] (Read/Write)
// 0x0f4 : reserved
// 0x0f8 : Data signal of kernel_1_0
//         bit 31~0 - kernel_1_0[31:0] (Read/Write)
// 0x0fc : reserved
// 0x100 : Data signal of kernel_1_1
//         bit 31~0 - kernel_1_1[31:0] (Read/Write)
// 0x104 : reserved
// 0x108 : Data signal of kernel_1_2
//         bit 31~0 - kernel_1_2[31:0] (Read/Write)
// 0x10c : reserved
// 0x110 : Data signal of kernel_2_0
//         bit 31~0 - kernel_2_0[31:0] (Read/Write)
// 0x114 : reserved
// 0x118 : Data signal of kernel_2_1
//         bit 31~0 - kernel_2_1[31:0] (Read/Write)
// 0x11c : reserved
// 0x120 : Data signal of kernel_2_2
//         bit 31~0 - kernel_2_2[31:0] (Read/Write)
// 0x124 : reserved
// 0x040 ~
// 0x07f : Memory 'input_0' (10 * 32b)
//         Word n : bit [31:0] - input_0[n]
// 0x080 ~
// 0x0bf : Memory 'input_1' (10 * 32b)
//         Word n : bit [31:0] - input_1[n]
// 0x0c0 ~
// 0x0df : Memory 'input_2' (5 * 32b)
//         Word n : bit [31:0] - input_2[n]
// 0x140 ~
// 0x17f : Memory 'output_r' (9 * 32b)
//         Word n : bit [31:0] - output_r[n]
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XCONVOLUTION2D_CONV_IO_ADDR_AP_CTRL         0x000
#define XCONVOLUTION2D_CONV_IO_ADDR_GIE             0x004
#define XCONVOLUTION2D_CONV_IO_ADDR_IER             0x008
#define XCONVOLUTION2D_CONV_IO_ADDR_ISR             0x00c
#define XCONVOLUTION2D_CONV_IO_ADDR_KERNEL_0_0_DATA 0x0e0
#define XCONVOLUTION2D_CONV_IO_BITS_KERNEL_0_0_DATA 32
#define XCONVOLUTION2D_CONV_IO_ADDR_KERNEL_0_1_DATA 0x0e8
#define XCONVOLUTION2D_CONV_IO_BITS_KERNEL_0_1_DATA 32
#define XCONVOLUTION2D_CONV_IO_ADDR_KERNEL_0_2_DATA 0x0f0
#define XCONVOLUTION2D_CONV_IO_BITS_KERNEL_0_2_DATA 32
#define XCONVOLUTION2D_CONV_IO_ADDR_KERNEL_1_0_DATA 0x0f8
#define XCONVOLUTION2D_CONV_IO_BITS_KERNEL_1_0_DATA 32
#define XCONVOLUTION2D_CONV_IO_ADDR_KERNEL_1_1_DATA 0x100
#define XCONVOLUTION2D_CONV_IO_BITS_KERNEL_1_1_DATA 32
#define XCONVOLUTION2D_CONV_IO_ADDR_KERNEL_1_2_DATA 0x108
#define XCONVOLUTION2D_CONV_IO_BITS_KERNEL_1_2_DATA 32
#define XCONVOLUTION2D_CONV_IO_ADDR_KERNEL_2_0_DATA 0x110
#define XCONVOLUTION2D_CONV_IO_BITS_KERNEL_2_0_DATA 32
#define XCONVOLUTION2D_CONV_IO_ADDR_KERNEL_2_1_DATA 0x118
#define XCONVOLUTION2D_CONV_IO_BITS_KERNEL_2_1_DATA 32
#define XCONVOLUTION2D_CONV_IO_ADDR_KERNEL_2_2_DATA 0x120
#define XCONVOLUTION2D_CONV_IO_BITS_KERNEL_2_2_DATA 32
#define XCONVOLUTION2D_CONV_IO_ADDR_INPUT_0_BASE    0x040
#define XCONVOLUTION2D_CONV_IO_ADDR_INPUT_0_HIGH    0x07f
#define XCONVOLUTION2D_CONV_IO_WIDTH_INPUT_0        32
#define XCONVOLUTION2D_CONV_IO_DEPTH_INPUT_0        10
#define XCONVOLUTION2D_CONV_IO_ADDR_INPUT_1_BASE    0x080
#define XCONVOLUTION2D_CONV_IO_ADDR_INPUT_1_HIGH    0x0bf
#define XCONVOLUTION2D_CONV_IO_WIDTH_INPUT_1        32
#define XCONVOLUTION2D_CONV_IO_DEPTH_INPUT_1        10
#define XCONVOLUTION2D_CONV_IO_ADDR_INPUT_2_BASE    0x0c0
#define XCONVOLUTION2D_CONV_IO_ADDR_INPUT_2_HIGH    0x0df
#define XCONVOLUTION2D_CONV_IO_WIDTH_INPUT_2        32
#define XCONVOLUTION2D_CONV_IO_DEPTH_INPUT_2        5
#define XCONVOLUTION2D_CONV_IO_ADDR_OUTPUT_R_BASE   0x140
#define XCONVOLUTION2D_CONV_IO_ADDR_OUTPUT_R_HIGH   0x17f
#define XCONVOLUTION2D_CONV_IO_WIDTH_OUTPUT_R       32
#define XCONVOLUTION2D_CONV_IO_DEPTH_OUTPUT_R       9

