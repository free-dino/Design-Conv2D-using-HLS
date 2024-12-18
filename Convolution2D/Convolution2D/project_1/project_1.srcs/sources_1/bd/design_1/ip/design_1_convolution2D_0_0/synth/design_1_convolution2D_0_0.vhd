-- (c) Copyright 1995-2024 Xilinx, Inc. All rights reserved.
-- 
-- This file contains confidential and proprietary information
-- of Xilinx, Inc. and is protected under U.S. and
-- international copyright and other intellectual property
-- laws.
-- 
-- DISCLAIMER
-- This disclaimer is not a license and does not grant any
-- rights to the materials distributed herewith. Except as
-- otherwise provided in a valid license issued to you by
-- Xilinx, and to the maximum extent permitted by applicable
-- law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
-- WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
-- AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
-- BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
-- INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
-- (2) Xilinx shall not be liable (whether in contract or tort,
-- including negligence, or under any other theory of
-- liability) for any loss or damage of any kind or nature
-- related to, arising under or in connection with these
-- materials, including for any direct, or any indirect,
-- special, incidental, or consequential loss or damage
-- (including loss of data, profits, goodwill, or any type of
-- loss or damage suffered as a result of any action brought
-- by a third party) even if such damage or loss was
-- reasonably foreseeable or Xilinx had been advised of the
-- possibility of the same.
-- 
-- CRITICAL APPLICATIONS
-- Xilinx products are not designed or intended to be fail-
-- safe, or for use in any application requiring fail-safe
-- performance, such as life-support or safety devices or
-- systems, Class III medical devices, nuclear facilities,
-- applications related to the deployment of airbags, or any
-- other applications that could lead to death, personal
-- injury, or severe property or environmental damage
-- (individually and collectively, "Critical
-- Applications"). Customer assumes the sole risk and
-- liability of any use of Xilinx products in Critical
-- Applications, subject only to applicable laws and
-- regulations governing limitations on product liability.
-- 
-- THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
-- PART OF THIS FILE AT ALL TIMES.
-- 
-- DO NOT MODIFY THIS FILE.

-- IP VLNV: xilinx.com:hls:convolution2D:0.0
-- IP Revision: 0

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;

ENTITY design_1_convolution2D_0_0 IS
  PORT (
    s_axi_conv_io_AWADDR : IN STD_LOGIC_VECTOR(8 DOWNTO 0);
    s_axi_conv_io_AWVALID : IN STD_LOGIC;
    s_axi_conv_io_AWREADY : OUT STD_LOGIC;
    s_axi_conv_io_WDATA : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
    s_axi_conv_io_WSTRB : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
    s_axi_conv_io_WVALID : IN STD_LOGIC;
    s_axi_conv_io_WREADY : OUT STD_LOGIC;
    s_axi_conv_io_BRESP : OUT STD_LOGIC_VECTOR(1 DOWNTO 0);
    s_axi_conv_io_BVALID : OUT STD_LOGIC;
    s_axi_conv_io_BREADY : IN STD_LOGIC;
    s_axi_conv_io_ARADDR : IN STD_LOGIC_VECTOR(8 DOWNTO 0);
    s_axi_conv_io_ARVALID : IN STD_LOGIC;
    s_axi_conv_io_ARREADY : OUT STD_LOGIC;
    s_axi_conv_io_RDATA : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
    s_axi_conv_io_RRESP : OUT STD_LOGIC_VECTOR(1 DOWNTO 0);
    s_axi_conv_io_RVALID : OUT STD_LOGIC;
    s_axi_conv_io_RREADY : IN STD_LOGIC;
    ap_clk : IN STD_LOGIC;
    ap_rst_n : IN STD_LOGIC;
    interrupt : OUT STD_LOGIC
  );
END design_1_convolution2D_0_0;

ARCHITECTURE design_1_convolution2D_0_0_arch OF design_1_convolution2D_0_0 IS
  ATTRIBUTE DowngradeIPIdentifiedWarnings : STRING;
  ATTRIBUTE DowngradeIPIdentifiedWarnings OF design_1_convolution2D_0_0_arch: ARCHITECTURE IS "yes";
  COMPONENT convolution2D IS
    GENERIC (
      C_S_AXI_CONV_IO_ADDR_WIDTH : INTEGER;
      C_S_AXI_CONV_IO_DATA_WIDTH : INTEGER
    );
    PORT (
      s_axi_conv_io_AWADDR : IN STD_LOGIC_VECTOR(8 DOWNTO 0);
      s_axi_conv_io_AWVALID : IN STD_LOGIC;
      s_axi_conv_io_AWREADY : OUT STD_LOGIC;
      s_axi_conv_io_WDATA : IN STD_LOGIC_VECTOR(31 DOWNTO 0);
      s_axi_conv_io_WSTRB : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
      s_axi_conv_io_WVALID : IN STD_LOGIC;
      s_axi_conv_io_WREADY : OUT STD_LOGIC;
      s_axi_conv_io_BRESP : OUT STD_LOGIC_VECTOR(1 DOWNTO 0);
      s_axi_conv_io_BVALID : OUT STD_LOGIC;
      s_axi_conv_io_BREADY : IN STD_LOGIC;
      s_axi_conv_io_ARADDR : IN STD_LOGIC_VECTOR(8 DOWNTO 0);
      s_axi_conv_io_ARVALID : IN STD_LOGIC;
      s_axi_conv_io_ARREADY : OUT STD_LOGIC;
      s_axi_conv_io_RDATA : OUT STD_LOGIC_VECTOR(31 DOWNTO 0);
      s_axi_conv_io_RRESP : OUT STD_LOGIC_VECTOR(1 DOWNTO 0);
      s_axi_conv_io_RVALID : OUT STD_LOGIC;
      s_axi_conv_io_RREADY : IN STD_LOGIC;
      ap_clk : IN STD_LOGIC;
      ap_rst_n : IN STD_LOGIC;
      interrupt : OUT STD_LOGIC
    );
  END COMPONENT convolution2D;
  ATTRIBUTE X_CORE_INFO : STRING;
  ATTRIBUTE X_CORE_INFO OF design_1_convolution2D_0_0_arch: ARCHITECTURE IS "convolution2D,Vivado 2018.3";
  ATTRIBUTE CHECK_LICENSE_TYPE : STRING;
  ATTRIBUTE CHECK_LICENSE_TYPE OF design_1_convolution2D_0_0_arch : ARCHITECTURE IS "design_1_convolution2D_0_0,convolution2D,{}";
  ATTRIBUTE CORE_GENERATION_INFO : STRING;
  ATTRIBUTE CORE_GENERATION_INFO OF design_1_convolution2D_0_0_arch: ARCHITECTURE IS "design_1_convolution2D_0_0,convolution2D,{x_ipProduct=Vivado 2018.3,x_ipVendor=xilinx.com,x_ipLibrary=hls,x_ipName=convolution2D,x_ipVersion=0.0,x_ipCoreRevision=0,x_ipLanguage=VHDL,x_ipSimLanguage=VHDL,C_S_AXI_CONV_IO_ADDR_WIDTH=9,C_S_AXI_CONV_IO_DATA_WIDTH=32}";
  ATTRIBUTE IP_DEFINITION_SOURCE : STRING;
  ATTRIBUTE IP_DEFINITION_SOURCE OF design_1_convolution2D_0_0_arch: ARCHITECTURE IS "HLS";
  ATTRIBUTE X_INTERFACE_INFO : STRING;
  ATTRIBUTE X_INTERFACE_PARAMETER : STRING;
  ATTRIBUTE X_INTERFACE_PARAMETER OF interrupt: SIGNAL IS "XIL_INTERFACENAME interrupt, SENSITIVITY LEVEL_HIGH, LAYERED_METADATA xilinx.com:interface:datatypes:1.0 {INTERRUPT {datatype {name {attribs {resolve_type immediate dependency {} format string minimum {} maximum {}} value {}} bitwidth {attribs {resolve_type immediate dependency {} format long minimum {} maximum {}} value 1} bitoffset {attribs {resolve_type immediate dependency {} format long minimum {} maximum {}} value 0}}}}, PortWidth 1";
  ATTRIBUTE X_INTERFACE_INFO OF interrupt: SIGNAL IS "xilinx.com:signal:interrupt:1.0 interrupt INTERRUPT";
  ATTRIBUTE X_INTERFACE_PARAMETER OF ap_rst_n: SIGNAL IS "XIL_INTERFACENAME ap_rst_n, POLARITY ACTIVE_LOW, LAYERED_METADATA xilinx.com:interface:datatypes:1.0 {RST {datatype {name {attribs {resolve_type immediate dependency {} format string minimum {} maximum {}} value {}} bitwidth {attribs {resolve_type immediate dependency {} format long minimum {} maximum {}} value 1} bitoffset {attribs {resolve_type immediate dependency {} format long minimum {} maximum {}} value 0}}}}, INSERT_VIP 0";
  ATTRIBUTE X_INTERFACE_INFO OF ap_rst_n: SIGNAL IS "xilinx.com:signal:reset:1.0 ap_rst_n RST";
  ATTRIBUTE X_INTERFACE_PARAMETER OF ap_clk: SIGNAL IS "XIL_INTERFACENAME ap_clk, ASSOCIATED_BUSIF s_axi_conv_io, ASSOCIATED_RESET ap_rst_n, LAYERED_METADATA xilinx.com:interface:datatypes:1.0 {CLK {datatype {name {attribs {resolve_type immediate dependency {} format string minimum {} maximum {}} value {}} bitwidth {attribs {resolve_type immediate dependency {} format long minimum {} maximum {}} value 1} bitoffset {attribs {resolve_type immediate dependency {} format long minimum {} maximum {}} value 0}}}}, FREQ_HZ 100000000, PHASE 0.000, CLK_DOMAIN " & 
"design_1_processing_system7_0_0_FCLK_CLK0, INSERT_VIP 0";
  ATTRIBUTE X_INTERFACE_INFO OF ap_clk: SIGNAL IS "xilinx.com:signal:clock:1.0 ap_clk CLK";
  ATTRIBUTE X_INTERFACE_INFO OF s_axi_conv_io_RREADY: SIGNAL IS "xilinx.com:interface:aximm:1.0 s_axi_conv_io RREADY";
  ATTRIBUTE X_INTERFACE_INFO OF s_axi_conv_io_RVALID: SIGNAL IS "xilinx.com:interface:aximm:1.0 s_axi_conv_io RVALID";
  ATTRIBUTE X_INTERFACE_INFO OF s_axi_conv_io_RRESP: SIGNAL IS "xilinx.com:interface:aximm:1.0 s_axi_conv_io RRESP";
  ATTRIBUTE X_INTERFACE_INFO OF s_axi_conv_io_RDATA: SIGNAL IS "xilinx.com:interface:aximm:1.0 s_axi_conv_io RDATA";
  ATTRIBUTE X_INTERFACE_INFO OF s_axi_conv_io_ARREADY: SIGNAL IS "xilinx.com:interface:aximm:1.0 s_axi_conv_io ARREADY";
  ATTRIBUTE X_INTERFACE_INFO OF s_axi_conv_io_ARVALID: SIGNAL IS "xilinx.com:interface:aximm:1.0 s_axi_conv_io ARVALID";
  ATTRIBUTE X_INTERFACE_INFO OF s_axi_conv_io_ARADDR: SIGNAL IS "xilinx.com:interface:aximm:1.0 s_axi_conv_io ARADDR";
  ATTRIBUTE X_INTERFACE_INFO OF s_axi_conv_io_BREADY: SIGNAL IS "xilinx.com:interface:aximm:1.0 s_axi_conv_io BREADY";
  ATTRIBUTE X_INTERFACE_INFO OF s_axi_conv_io_BVALID: SIGNAL IS "xilinx.com:interface:aximm:1.0 s_axi_conv_io BVALID";
  ATTRIBUTE X_INTERFACE_INFO OF s_axi_conv_io_BRESP: SIGNAL IS "xilinx.com:interface:aximm:1.0 s_axi_conv_io BRESP";
  ATTRIBUTE X_INTERFACE_INFO OF s_axi_conv_io_WREADY: SIGNAL IS "xilinx.com:interface:aximm:1.0 s_axi_conv_io WREADY";
  ATTRIBUTE X_INTERFACE_INFO OF s_axi_conv_io_WVALID: SIGNAL IS "xilinx.com:interface:aximm:1.0 s_axi_conv_io WVALID";
  ATTRIBUTE X_INTERFACE_INFO OF s_axi_conv_io_WSTRB: SIGNAL IS "xilinx.com:interface:aximm:1.0 s_axi_conv_io WSTRB";
  ATTRIBUTE X_INTERFACE_INFO OF s_axi_conv_io_WDATA: SIGNAL IS "xilinx.com:interface:aximm:1.0 s_axi_conv_io WDATA";
  ATTRIBUTE X_INTERFACE_INFO OF s_axi_conv_io_AWREADY: SIGNAL IS "xilinx.com:interface:aximm:1.0 s_axi_conv_io AWREADY";
  ATTRIBUTE X_INTERFACE_INFO OF s_axi_conv_io_AWVALID: SIGNAL IS "xilinx.com:interface:aximm:1.0 s_axi_conv_io AWVALID";
  ATTRIBUTE X_INTERFACE_PARAMETER OF s_axi_conv_io_AWADDR: SIGNAL IS "XIL_INTERFACENAME s_axi_conv_io, ADDR_WIDTH 9, DATA_WIDTH 32, PROTOCOL AXI4LITE, READ_WRITE_MODE READ_WRITE, LAYERED_METADATA xilinx.com:interface:datatypes:1.0 {CLK {datatype {name {attribs {resolve_type immediate dependency {} format string minimum {} maximum {}} value {}} bitwidth {attribs {resolve_type immediate dependency {} format long minimum {} maximum {}} value 1} bitoffset {attribs {resolve_type immediate dependency {} format long minimum {} maximum {}} value 0}}}}, FREQ_HZ 100000000, " & 
"ID_WIDTH 0, AWUSER_WIDTH 0, ARUSER_WIDTH 0, WUSER_WIDTH 0, RUSER_WIDTH 0, BUSER_WIDTH 0, HAS_BURST 0, HAS_LOCK 0, HAS_PROT 0, HAS_CACHE 0, HAS_QOS 0, HAS_REGION 0, HAS_WSTRB 1, HAS_BRESP 1, HAS_RRESP 1, SUPPORTS_NARROW_BURST 0, NUM_READ_OUTSTANDING 1, NUM_WRITE_OUTSTANDING 1, MAX_BURST_LENGTH 1, PHASE 0.000, CLK_DOMAIN design_1_processing_system7_0_0_FCLK_CLK0, NUM_READ_THREADS 1, NUM_WRITE_THREADS 1, RUSER_BITS_PER_BYTE 0, WUSER_BITS_PER_BYTE 0, INSERT_VIP 0";
  ATTRIBUTE X_INTERFACE_INFO OF s_axi_conv_io_AWADDR: SIGNAL IS "xilinx.com:interface:aximm:1.0 s_axi_conv_io AWADDR";
BEGIN
  U0 : convolution2D
    GENERIC MAP (
      C_S_AXI_CONV_IO_ADDR_WIDTH => 9,
      C_S_AXI_CONV_IO_DATA_WIDTH => 32
    )
    PORT MAP (
      s_axi_conv_io_AWADDR => s_axi_conv_io_AWADDR,
      s_axi_conv_io_AWVALID => s_axi_conv_io_AWVALID,
      s_axi_conv_io_AWREADY => s_axi_conv_io_AWREADY,
      s_axi_conv_io_WDATA => s_axi_conv_io_WDATA,
      s_axi_conv_io_WSTRB => s_axi_conv_io_WSTRB,
      s_axi_conv_io_WVALID => s_axi_conv_io_WVALID,
      s_axi_conv_io_WREADY => s_axi_conv_io_WREADY,
      s_axi_conv_io_BRESP => s_axi_conv_io_BRESP,
      s_axi_conv_io_BVALID => s_axi_conv_io_BVALID,
      s_axi_conv_io_BREADY => s_axi_conv_io_BREADY,
      s_axi_conv_io_ARADDR => s_axi_conv_io_ARADDR,
      s_axi_conv_io_ARVALID => s_axi_conv_io_ARVALID,
      s_axi_conv_io_ARREADY => s_axi_conv_io_ARREADY,
      s_axi_conv_io_RDATA => s_axi_conv_io_RDATA,
      s_axi_conv_io_RRESP => s_axi_conv_io_RRESP,
      s_axi_conv_io_RVALID => s_axi_conv_io_RVALID,
      s_axi_conv_io_RREADY => s_axi_conv_io_RREADY,
      ap_clk => ap_clk,
      ap_rst_n => ap_rst_n,
      interrupt => interrupt
    );
END design_1_convolution2D_0_0_arch;
