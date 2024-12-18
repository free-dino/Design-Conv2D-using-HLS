// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2018.3 (lin64) Build 2405991 Thu Dec  6 23:36:41 MST 2018
// Date        : Wed Dec 18 21:34:45 2024
// Host        : freedino-Inspiron-3542 running 64-bit Ubuntu 24.04.1 LTS
// Command     : write_verilog -force -mode synth_stub
//               /home/freedino/Design-Conv2D-using-HLS/Convolution2D/Convolution2D/project_1/project_1.srcs/sources_1/bd/design_1/ip/design_1_convolution2D_0_0/design_1_convolution2D_0_0_stub.v
// Design      : design_1_convolution2D_0_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7z020clg484-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* x_core_info = "convolution2D,Vivado 2018.3" *)
module design_1_convolution2D_0_0(s_axi_conv_io_AWADDR, 
  s_axi_conv_io_AWVALID, s_axi_conv_io_AWREADY, s_axi_conv_io_WDATA, s_axi_conv_io_WSTRB, 
  s_axi_conv_io_WVALID, s_axi_conv_io_WREADY, s_axi_conv_io_BRESP, s_axi_conv_io_BVALID, 
  s_axi_conv_io_BREADY, s_axi_conv_io_ARADDR, s_axi_conv_io_ARVALID, 
  s_axi_conv_io_ARREADY, s_axi_conv_io_RDATA, s_axi_conv_io_RRESP, s_axi_conv_io_RVALID, 
  s_axi_conv_io_RREADY, ap_clk, ap_rst_n, interrupt)
/* synthesis syn_black_box black_box_pad_pin="s_axi_conv_io_AWADDR[8:0],s_axi_conv_io_AWVALID,s_axi_conv_io_AWREADY,s_axi_conv_io_WDATA[31:0],s_axi_conv_io_WSTRB[3:0],s_axi_conv_io_WVALID,s_axi_conv_io_WREADY,s_axi_conv_io_BRESP[1:0],s_axi_conv_io_BVALID,s_axi_conv_io_BREADY,s_axi_conv_io_ARADDR[8:0],s_axi_conv_io_ARVALID,s_axi_conv_io_ARREADY,s_axi_conv_io_RDATA[31:0],s_axi_conv_io_RRESP[1:0],s_axi_conv_io_RVALID,s_axi_conv_io_RREADY,ap_clk,ap_rst_n,interrupt" */;
  input [8:0]s_axi_conv_io_AWADDR;
  input s_axi_conv_io_AWVALID;
  output s_axi_conv_io_AWREADY;
  input [31:0]s_axi_conv_io_WDATA;
  input [3:0]s_axi_conv_io_WSTRB;
  input s_axi_conv_io_WVALID;
  output s_axi_conv_io_WREADY;
  output [1:0]s_axi_conv_io_BRESP;
  output s_axi_conv_io_BVALID;
  input s_axi_conv_io_BREADY;
  input [8:0]s_axi_conv_io_ARADDR;
  input s_axi_conv_io_ARVALID;
  output s_axi_conv_io_ARREADY;
  output [31:0]s_axi_conv_io_RDATA;
  output [1:0]s_axi_conv_io_RRESP;
  output s_axi_conv_io_RVALID;
  input s_axi_conv_io_RREADY;
  input ap_clk;
  input ap_rst_n;
  output interrupt;
endmodule
