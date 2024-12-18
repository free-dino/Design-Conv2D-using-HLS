-- Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2018.3 (lin64) Build 2405991 Thu Dec  6 23:36:41 MST 2018
-- Date        : Wed Dec 18 21:34:45 2024
-- Host        : freedino-Inspiron-3542 running 64-bit Ubuntu 24.04.1 LTS
-- Command     : write_vhdl -force -mode synth_stub
--               /home/freedino/Design-Conv2D-using-HLS/Convolution2D/Convolution2D/project_1/project_1.srcs/sources_1/bd/design_1/ip/design_1_convolution2D_0_0/design_1_convolution2D_0_0_stub.vhdl
-- Design      : design_1_convolution2D_0_0
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xc7z020clg484-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity design_1_convolution2D_0_0 is
  Port ( 
    s_axi_conv_io_AWADDR : in STD_LOGIC_VECTOR ( 8 downto 0 );
    s_axi_conv_io_AWVALID : in STD_LOGIC;
    s_axi_conv_io_AWREADY : out STD_LOGIC;
    s_axi_conv_io_WDATA : in STD_LOGIC_VECTOR ( 31 downto 0 );
    s_axi_conv_io_WSTRB : in STD_LOGIC_VECTOR ( 3 downto 0 );
    s_axi_conv_io_WVALID : in STD_LOGIC;
    s_axi_conv_io_WREADY : out STD_LOGIC;
    s_axi_conv_io_BRESP : out STD_LOGIC_VECTOR ( 1 downto 0 );
    s_axi_conv_io_BVALID : out STD_LOGIC;
    s_axi_conv_io_BREADY : in STD_LOGIC;
    s_axi_conv_io_ARADDR : in STD_LOGIC_VECTOR ( 8 downto 0 );
    s_axi_conv_io_ARVALID : in STD_LOGIC;
    s_axi_conv_io_ARREADY : out STD_LOGIC;
    s_axi_conv_io_RDATA : out STD_LOGIC_VECTOR ( 31 downto 0 );
    s_axi_conv_io_RRESP : out STD_LOGIC_VECTOR ( 1 downto 0 );
    s_axi_conv_io_RVALID : out STD_LOGIC;
    s_axi_conv_io_RREADY : in STD_LOGIC;
    ap_clk : in STD_LOGIC;
    ap_rst_n : in STD_LOGIC;
    interrupt : out STD_LOGIC
  );

end design_1_convolution2D_0_0;

architecture stub of design_1_convolution2D_0_0 is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "s_axi_conv_io_AWADDR[8:0],s_axi_conv_io_AWVALID,s_axi_conv_io_AWREADY,s_axi_conv_io_WDATA[31:0],s_axi_conv_io_WSTRB[3:0],s_axi_conv_io_WVALID,s_axi_conv_io_WREADY,s_axi_conv_io_BRESP[1:0],s_axi_conv_io_BVALID,s_axi_conv_io_BREADY,s_axi_conv_io_ARADDR[8:0],s_axi_conv_io_ARVALID,s_axi_conv_io_ARREADY,s_axi_conv_io_RDATA[31:0],s_axi_conv_io_RRESP[1:0],s_axi_conv_io_RVALID,s_axi_conv_io_RREADY,ap_clk,ap_rst_n,interrupt";
attribute x_core_info : string;
attribute x_core_info of stub : architecture is "convolution2D,Vivado 2018.3";
begin
end;
