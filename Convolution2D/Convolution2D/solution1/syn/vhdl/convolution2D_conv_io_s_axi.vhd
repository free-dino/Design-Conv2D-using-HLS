-- ==============================================================
-- File generated on Wed Dec 18 21:02:53 +0700 2024
-- Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
-- SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
-- IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
-- Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
-- ==============================================================
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.NUMERIC_STD.all;

entity convolution2D_conv_io_s_axi is
generic (
    C_S_AXI_ADDR_WIDTH    : INTEGER := 9;
    C_S_AXI_DATA_WIDTH    : INTEGER := 32);
port (
    -- axi4 lite slave signals
    ACLK                  :in   STD_LOGIC;
    ARESET                :in   STD_LOGIC;
    ACLK_EN               :in   STD_LOGIC;
    AWADDR                :in   STD_LOGIC_VECTOR(C_S_AXI_ADDR_WIDTH-1 downto 0);
    AWVALID               :in   STD_LOGIC;
    AWREADY               :out  STD_LOGIC;
    WDATA                 :in   STD_LOGIC_VECTOR(C_S_AXI_DATA_WIDTH-1 downto 0);
    WSTRB                 :in   STD_LOGIC_VECTOR(C_S_AXI_DATA_WIDTH/8-1 downto 0);
    WVALID                :in   STD_LOGIC;
    WREADY                :out  STD_LOGIC;
    BRESP                 :out  STD_LOGIC_VECTOR(1 downto 0);
    BVALID                :out  STD_LOGIC;
    BREADY                :in   STD_LOGIC;
    ARADDR                :in   STD_LOGIC_VECTOR(C_S_AXI_ADDR_WIDTH-1 downto 0);
    ARVALID               :in   STD_LOGIC;
    ARREADY               :out  STD_LOGIC;
    RDATA                 :out  STD_LOGIC_VECTOR(C_S_AXI_DATA_WIDTH-1 downto 0);
    RRESP                 :out  STD_LOGIC_VECTOR(1 downto 0);
    RVALID                :out  STD_LOGIC;
    RREADY                :in   STD_LOGIC;
    interrupt             :out  STD_LOGIC;
    -- user signals
    ap_start              :out  STD_LOGIC;
    ap_done               :in   STD_LOGIC;
    ap_ready              :in   STD_LOGIC;
    ap_idle               :in   STD_LOGIC;
    input_0_address0      :in   STD_LOGIC_VECTOR(3 downto 0);
    input_0_ce0           :in   STD_LOGIC;
    input_0_q0            :out  STD_LOGIC_VECTOR(31 downto 0);
    input_1_address0      :in   STD_LOGIC_VECTOR(3 downto 0);
    input_1_ce0           :in   STD_LOGIC;
    input_1_q0            :out  STD_LOGIC_VECTOR(31 downto 0);
    input_2_address0      :in   STD_LOGIC_VECTOR(2 downto 0);
    input_2_ce0           :in   STD_LOGIC;
    input_2_q0            :out  STD_LOGIC_VECTOR(31 downto 0);
    kernel_0_0            :out  STD_LOGIC_VECTOR(31 downto 0);
    kernel_0_1            :out  STD_LOGIC_VECTOR(31 downto 0);
    kernel_0_2            :out  STD_LOGIC_VECTOR(31 downto 0);
    kernel_1_0            :out  STD_LOGIC_VECTOR(31 downto 0);
    kernel_1_1            :out  STD_LOGIC_VECTOR(31 downto 0);
    kernel_1_2            :out  STD_LOGIC_VECTOR(31 downto 0);
    kernel_2_0            :out  STD_LOGIC_VECTOR(31 downto 0);
    kernel_2_1            :out  STD_LOGIC_VECTOR(31 downto 0);
    kernel_2_2            :out  STD_LOGIC_VECTOR(31 downto 0);
    output_r_address0     :in   STD_LOGIC_VECTOR(3 downto 0);
    output_r_ce0          :in   STD_LOGIC;
    output_r_we0          :in   STD_LOGIC;
    output_r_d0           :in   STD_LOGIC_VECTOR(31 downto 0)
);
end entity convolution2D_conv_io_s_axi;

-- ------------------------Address Info-------------------
-- 0x000 : Control signals
--         bit 0  - ap_start (Read/Write/COH)
--         bit 1  - ap_done (Read/COR)
--         bit 2  - ap_idle (Read)
--         bit 3  - ap_ready (Read)
--         bit 7  - auto_restart (Read/Write)
--         others - reserved
-- 0x004 : Global Interrupt Enable Register
--         bit 0  - Global Interrupt Enable (Read/Write)
--         others - reserved
-- 0x008 : IP Interrupt Enable Register (Read/Write)
--         bit 0  - Channel 0 (ap_done)
--         bit 1  - Channel 1 (ap_ready)
--         others - reserved
-- 0x00c : IP Interrupt Status Register (Read/TOW)
--         bit 0  - Channel 0 (ap_done)
--         bit 1  - Channel 1 (ap_ready)
--         others - reserved
-- 0x0e0 : Data signal of kernel_0_0
--         bit 31~0 - kernel_0_0[31:0] (Read/Write)
-- 0x0e4 : reserved
-- 0x0e8 : Data signal of kernel_0_1
--         bit 31~0 - kernel_0_1[31:0] (Read/Write)
-- 0x0ec : reserved
-- 0x0f0 : Data signal of kernel_0_2
--         bit 31~0 - kernel_0_2[31:0] (Read/Write)
-- 0x0f4 : reserved
-- 0x0f8 : Data signal of kernel_1_0
--         bit 31~0 - kernel_1_0[31:0] (Read/Write)
-- 0x0fc : reserved
-- 0x100 : Data signal of kernel_1_1
--         bit 31~0 - kernel_1_1[31:0] (Read/Write)
-- 0x104 : reserved
-- 0x108 : Data signal of kernel_1_2
--         bit 31~0 - kernel_1_2[31:0] (Read/Write)
-- 0x10c : reserved
-- 0x110 : Data signal of kernel_2_0
--         bit 31~0 - kernel_2_0[31:0] (Read/Write)
-- 0x114 : reserved
-- 0x118 : Data signal of kernel_2_1
--         bit 31~0 - kernel_2_1[31:0] (Read/Write)
-- 0x11c : reserved
-- 0x120 : Data signal of kernel_2_2
--         bit 31~0 - kernel_2_2[31:0] (Read/Write)
-- 0x124 : reserved
-- 0x040 ~
-- 0x07f : Memory 'input_0' (10 * 32b)
--         Word n : bit [31:0] - input_0[n]
-- 0x080 ~
-- 0x0bf : Memory 'input_1' (10 * 32b)
--         Word n : bit [31:0] - input_1[n]
-- 0x0c0 ~
-- 0x0df : Memory 'input_2' (5 * 32b)
--         Word n : bit [31:0] - input_2[n]
-- 0x140 ~
-- 0x17f : Memory 'output_r' (9 * 32b)
--         Word n : bit [31:0] - output_r[n]
-- (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

architecture behave of convolution2D_conv_io_s_axi is
    type states is (wridle, wrdata, wrresp, wrreset, rdidle, rddata, rdreset);  -- read and write fsm states
    signal wstate  : states := wrreset;
    signal rstate  : states := rdreset;
    signal wnext, rnext: states;
    constant ADDR_AP_CTRL           : INTEGER := 16#000#;
    constant ADDR_GIE               : INTEGER := 16#004#;
    constant ADDR_IER               : INTEGER := 16#008#;
    constant ADDR_ISR               : INTEGER := 16#00c#;
    constant ADDR_KERNEL_0_0_DATA_0 : INTEGER := 16#0e0#;
    constant ADDR_KERNEL_0_0_CTRL   : INTEGER := 16#0e4#;
    constant ADDR_KERNEL_0_1_DATA_0 : INTEGER := 16#0e8#;
    constant ADDR_KERNEL_0_1_CTRL   : INTEGER := 16#0ec#;
    constant ADDR_KERNEL_0_2_DATA_0 : INTEGER := 16#0f0#;
    constant ADDR_KERNEL_0_2_CTRL   : INTEGER := 16#0f4#;
    constant ADDR_KERNEL_1_0_DATA_0 : INTEGER := 16#0f8#;
    constant ADDR_KERNEL_1_0_CTRL   : INTEGER := 16#0fc#;
    constant ADDR_KERNEL_1_1_DATA_0 : INTEGER := 16#100#;
    constant ADDR_KERNEL_1_1_CTRL   : INTEGER := 16#104#;
    constant ADDR_KERNEL_1_2_DATA_0 : INTEGER := 16#108#;
    constant ADDR_KERNEL_1_2_CTRL   : INTEGER := 16#10c#;
    constant ADDR_KERNEL_2_0_DATA_0 : INTEGER := 16#110#;
    constant ADDR_KERNEL_2_0_CTRL   : INTEGER := 16#114#;
    constant ADDR_KERNEL_2_1_DATA_0 : INTEGER := 16#118#;
    constant ADDR_KERNEL_2_1_CTRL   : INTEGER := 16#11c#;
    constant ADDR_KERNEL_2_2_DATA_0 : INTEGER := 16#120#;
    constant ADDR_KERNEL_2_2_CTRL   : INTEGER := 16#124#;
    constant ADDR_INPUT_0_BASE      : INTEGER := 16#040#;
    constant ADDR_INPUT_0_HIGH      : INTEGER := 16#07f#;
    constant ADDR_INPUT_1_BASE      : INTEGER := 16#080#;
    constant ADDR_INPUT_1_HIGH      : INTEGER := 16#0bf#;
    constant ADDR_INPUT_2_BASE      : INTEGER := 16#0c0#;
    constant ADDR_INPUT_2_HIGH      : INTEGER := 16#0df#;
    constant ADDR_OUTPUT_R_BASE     : INTEGER := 16#140#;
    constant ADDR_OUTPUT_R_HIGH     : INTEGER := 16#17f#;
    constant ADDR_BITS         : INTEGER := 9;

    signal waddr               : UNSIGNED(ADDR_BITS-1 downto 0);
    signal wmask               : UNSIGNED(31 downto 0);
    signal aw_hs               : STD_LOGIC;
    signal w_hs                : STD_LOGIC;
    signal rdata_data          : UNSIGNED(31 downto 0);
    signal ar_hs               : STD_LOGIC;
    signal raddr               : UNSIGNED(ADDR_BITS-1 downto 0);
    signal AWREADY_t           : STD_LOGIC;
    signal WREADY_t            : STD_LOGIC;
    signal ARREADY_t           : STD_LOGIC;
    signal RVALID_t            : STD_LOGIC;
    -- internal registers
    signal int_ap_idle         : STD_LOGIC;
    signal int_ap_ready        : STD_LOGIC;
    signal int_ap_done         : STD_LOGIC := '0';
    signal int_ap_start        : STD_LOGIC := '0';
    signal int_auto_restart    : STD_LOGIC := '0';
    signal int_gie             : STD_LOGIC := '0';
    signal int_ier             : UNSIGNED(1 downto 0) := (others => '0');
    signal int_isr             : UNSIGNED(1 downto 0) := (others => '0');
    signal int_kernel_0_0      : UNSIGNED(31 downto 0) := (others => '0');
    signal int_kernel_0_1      : UNSIGNED(31 downto 0) := (others => '0');
    signal int_kernel_0_2      : UNSIGNED(31 downto 0) := (others => '0');
    signal int_kernel_1_0      : UNSIGNED(31 downto 0) := (others => '0');
    signal int_kernel_1_1      : UNSIGNED(31 downto 0) := (others => '0');
    signal int_kernel_1_2      : UNSIGNED(31 downto 0) := (others => '0');
    signal int_kernel_2_0      : UNSIGNED(31 downto 0) := (others => '0');
    signal int_kernel_2_1      : UNSIGNED(31 downto 0) := (others => '0');
    signal int_kernel_2_2      : UNSIGNED(31 downto 0) := (others => '0');
    -- memory signals
    signal int_input_0_address0 : UNSIGNED(3 downto 0);
    signal int_input_0_ce0     : STD_LOGIC;
    signal int_input_0_we0     : STD_LOGIC;
    signal int_input_0_be0     : UNSIGNED(3 downto 0);
    signal int_input_0_d0      : UNSIGNED(31 downto 0);
    signal int_input_0_q0      : UNSIGNED(31 downto 0);
    signal int_input_0_address1 : UNSIGNED(3 downto 0);
    signal int_input_0_ce1     : STD_LOGIC;
    signal int_input_0_we1     : STD_LOGIC;
    signal int_input_0_be1     : UNSIGNED(3 downto 0);
    signal int_input_0_d1      : UNSIGNED(31 downto 0);
    signal int_input_0_q1      : UNSIGNED(31 downto 0);
    signal int_input_0_read    : STD_LOGIC;
    signal int_input_0_write   : STD_LOGIC;
    signal int_input_1_address0 : UNSIGNED(3 downto 0);
    signal int_input_1_ce0     : STD_LOGIC;
    signal int_input_1_we0     : STD_LOGIC;
    signal int_input_1_be0     : UNSIGNED(3 downto 0);
    signal int_input_1_d0      : UNSIGNED(31 downto 0);
    signal int_input_1_q0      : UNSIGNED(31 downto 0);
    signal int_input_1_address1 : UNSIGNED(3 downto 0);
    signal int_input_1_ce1     : STD_LOGIC;
    signal int_input_1_we1     : STD_LOGIC;
    signal int_input_1_be1     : UNSIGNED(3 downto 0);
    signal int_input_1_d1      : UNSIGNED(31 downto 0);
    signal int_input_1_q1      : UNSIGNED(31 downto 0);
    signal int_input_1_read    : STD_LOGIC;
    signal int_input_1_write   : STD_LOGIC;
    signal int_input_2_address0 : UNSIGNED(2 downto 0);
    signal int_input_2_ce0     : STD_LOGIC;
    signal int_input_2_we0     : STD_LOGIC;
    signal int_input_2_be0     : UNSIGNED(3 downto 0);
    signal int_input_2_d0      : UNSIGNED(31 downto 0);
    signal int_input_2_q0      : UNSIGNED(31 downto 0);
    signal int_input_2_address1 : UNSIGNED(2 downto 0);
    signal int_input_2_ce1     : STD_LOGIC;
    signal int_input_2_we1     : STD_LOGIC;
    signal int_input_2_be1     : UNSIGNED(3 downto 0);
    signal int_input_2_d1      : UNSIGNED(31 downto 0);
    signal int_input_2_q1      : UNSIGNED(31 downto 0);
    signal int_input_2_read    : STD_LOGIC;
    signal int_input_2_write   : STD_LOGIC;
    signal int_output_r_address0 : UNSIGNED(3 downto 0);
    signal int_output_r_ce0    : STD_LOGIC;
    signal int_output_r_we0    : STD_LOGIC;
    signal int_output_r_be0    : UNSIGNED(3 downto 0);
    signal int_output_r_d0     : UNSIGNED(31 downto 0);
    signal int_output_r_q0     : UNSIGNED(31 downto 0);
    signal int_output_r_address1 : UNSIGNED(3 downto 0);
    signal int_output_r_ce1    : STD_LOGIC;
    signal int_output_r_we1    : STD_LOGIC;
    signal int_output_r_be1    : UNSIGNED(3 downto 0);
    signal int_output_r_d1     : UNSIGNED(31 downto 0);
    signal int_output_r_q1     : UNSIGNED(31 downto 0);
    signal int_output_r_read   : STD_LOGIC;
    signal int_output_r_write  : STD_LOGIC;

    component convolution2D_conv_io_s_axi_ram is
        generic (
            BYTES   : INTEGER :=4;
            DEPTH   : INTEGER :=256;
            AWIDTH  : INTEGER :=8);
        port (
            clk0    : in  STD_LOGIC;
            address0: in  UNSIGNED(AWIDTH-1 downto 0);
            ce0     : in  STD_LOGIC;
            we0     : in  STD_LOGIC;
            be0     : in  UNSIGNED(BYTES-1 downto 0);
            d0      : in  UNSIGNED(BYTES*8-1 downto 0);
            q0      : out UNSIGNED(BYTES*8-1 downto 0);
            clk1    : in  STD_LOGIC;
            address1: in  UNSIGNED(AWIDTH-1 downto 0);
            ce1     : in  STD_LOGIC;
            we1     : in  STD_LOGIC;
            be1     : in  UNSIGNED(BYTES-1 downto 0);
            d1      : in  UNSIGNED(BYTES*8-1 downto 0);
            q1      : out UNSIGNED(BYTES*8-1 downto 0));
    end component convolution2D_conv_io_s_axi_ram;

    function log2 (x : INTEGER) return INTEGER is
        variable n, m : INTEGER;
    begin
        n := 1;
        m := 2;
        while m < x loop
            n := n + 1;
            m := m * 2;
        end loop;
        return n;
    end function log2;

begin
-- ----------------------- Instantiation------------------
-- int_input_0
int_input_0 : convolution2D_conv_io_s_axi_ram
generic map (
     BYTES    => 4,
     DEPTH    => 10,
     AWIDTH   => log2(10))
port map (
     clk0     => ACLK,
     address0 => int_input_0_address0,
     ce0      => int_input_0_ce0,
     we0      => int_input_0_we0,
     be0      => int_input_0_be0,
     d0       => int_input_0_d0,
     q0       => int_input_0_q0,
     clk1     => ACLK,
     address1 => int_input_0_address1,
     ce1      => int_input_0_ce1,
     we1      => int_input_0_we1,
     be1      => int_input_0_be1,
     d1       => int_input_0_d1,
     q1       => int_input_0_q1);
-- int_input_1
int_input_1 : convolution2D_conv_io_s_axi_ram
generic map (
     BYTES    => 4,
     DEPTH    => 10,
     AWIDTH   => log2(10))
port map (
     clk0     => ACLK,
     address0 => int_input_1_address0,
     ce0      => int_input_1_ce0,
     we0      => int_input_1_we0,
     be0      => int_input_1_be0,
     d0       => int_input_1_d0,
     q0       => int_input_1_q0,
     clk1     => ACLK,
     address1 => int_input_1_address1,
     ce1      => int_input_1_ce1,
     we1      => int_input_1_we1,
     be1      => int_input_1_be1,
     d1       => int_input_1_d1,
     q1       => int_input_1_q1);
-- int_input_2
int_input_2 : convolution2D_conv_io_s_axi_ram
generic map (
     BYTES    => 4,
     DEPTH    => 5,
     AWIDTH   => log2(5))
port map (
     clk0     => ACLK,
     address0 => int_input_2_address0,
     ce0      => int_input_2_ce0,
     we0      => int_input_2_we0,
     be0      => int_input_2_be0,
     d0       => int_input_2_d0,
     q0       => int_input_2_q0,
     clk1     => ACLK,
     address1 => int_input_2_address1,
     ce1      => int_input_2_ce1,
     we1      => int_input_2_we1,
     be1      => int_input_2_be1,
     d1       => int_input_2_d1,
     q1       => int_input_2_q1);
-- int_output_r
int_output_r : convolution2D_conv_io_s_axi_ram
generic map (
     BYTES    => 4,
     DEPTH    => 9,
     AWIDTH   => log2(9))
port map (
     clk0     => ACLK,
     address0 => int_output_r_address0,
     ce0      => int_output_r_ce0,
     we0      => int_output_r_we0,
     be0      => int_output_r_be0,
     d0       => int_output_r_d0,
     q0       => int_output_r_q0,
     clk1     => ACLK,
     address1 => int_output_r_address1,
     ce1      => int_output_r_ce1,
     we1      => int_output_r_we1,
     be1      => int_output_r_be1,
     d1       => int_output_r_d1,
     q1       => int_output_r_q1);

-- ----------------------- AXI WRITE ---------------------
    AWREADY_t <=  '1' when wstate = wridle else '0';
    AWREADY   <=  AWREADY_t;
    WREADY_t  <=  '1' when wstate = wrdata else '0';
    WREADY    <=  WREADY_t;
    BRESP     <=  "00";  -- OKAY
    BVALID    <=  '1' when wstate = wrresp else '0';
    wmask     <=  (31 downto 24 => WSTRB(3), 23 downto 16 => WSTRB(2), 15 downto 8 => WSTRB(1), 7 downto 0 => WSTRB(0));
    aw_hs     <=  AWVALID and AWREADY_t;
    w_hs      <=  WVALID and WREADY_t;

    -- write FSM
    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                wstate <= wrreset;
            elsif (ACLK_EN = '1') then
                wstate <= wnext;
            end if;
        end if;
    end process;

    process (wstate, AWVALID, WVALID, BREADY)
    begin
        case (wstate) is
        when wridle =>
            if (AWVALID = '1') then
                wnext <= wrdata;
            else
                wnext <= wridle;
            end if;
        when wrdata =>
            if (WVALID = '1') then
                wnext <= wrresp;
            else
                wnext <= wrdata;
            end if;
        when wrresp =>
            if (BREADY = '1') then
                wnext <= wridle;
            else
                wnext <= wrresp;
            end if;
        when others =>
            wnext <= wridle;
        end case;
    end process;

    waddr_proc : process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (aw_hs = '1') then
                    waddr <= UNSIGNED(AWADDR(ADDR_BITS-1 downto 0));
                end if;
            end if;
        end if;
    end process;

-- ----------------------- AXI READ ----------------------
    ARREADY_t <= '1' when (rstate = rdidle) else '0';
    ARREADY <= ARREADY_t;
    RDATA   <= STD_LOGIC_VECTOR(rdata_data);
    RRESP   <= "00";  -- OKAY
    RVALID_t  <= '1' when (rstate = rddata) and (int_input_0_read = '0') and (int_input_1_read = '0') and (int_input_2_read = '0') and (int_output_r_read = '0') else '0';
    RVALID    <= RVALID_t;
    ar_hs   <= ARVALID and ARREADY_t;
    raddr   <= UNSIGNED(ARADDR(ADDR_BITS-1 downto 0));

    -- read FSM
    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                rstate <= rdreset;
            elsif (ACLK_EN = '1') then
                rstate <= rnext;
            end if;
        end if;
    end process;

    process (rstate, ARVALID, RREADY, RVALID_t)
    begin
        case (rstate) is
        when rdidle =>
            if (ARVALID = '1') then
                rnext <= rddata;
            else
                rnext <= rdidle;
            end if;
        when rddata =>
            if (RREADY = '1' and RVALID_t = '1') then
                rnext <= rdidle;
            else
                rnext <= rddata;
            end if;
        when others =>
            rnext <= rdidle;
        end case;
    end process;

    rdata_proc : process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (ar_hs = '1') then
                    case (TO_INTEGER(raddr)) is
                    when ADDR_AP_CTRL =>
                        rdata_data <= (7 => int_auto_restart, 3 => int_ap_ready, 2 => int_ap_idle, 1 => int_ap_done, 0 => int_ap_start, others => '0');
                    when ADDR_GIE =>
                        rdata_data <= (0 => int_gie, others => '0');
                    when ADDR_IER =>
                        rdata_data <= (1 => int_ier(1), 0 => int_ier(0), others => '0');
                    when ADDR_ISR =>
                        rdata_data <= (1 => int_isr(1), 0 => int_isr(0), others => '0');
                    when ADDR_KERNEL_0_0_DATA_0 =>
                        rdata_data <= RESIZE(int_kernel_0_0(31 downto 0), 32);
                    when ADDR_KERNEL_0_1_DATA_0 =>
                        rdata_data <= RESIZE(int_kernel_0_1(31 downto 0), 32);
                    when ADDR_KERNEL_0_2_DATA_0 =>
                        rdata_data <= RESIZE(int_kernel_0_2(31 downto 0), 32);
                    when ADDR_KERNEL_1_0_DATA_0 =>
                        rdata_data <= RESIZE(int_kernel_1_0(31 downto 0), 32);
                    when ADDR_KERNEL_1_1_DATA_0 =>
                        rdata_data <= RESIZE(int_kernel_1_1(31 downto 0), 32);
                    when ADDR_KERNEL_1_2_DATA_0 =>
                        rdata_data <= RESIZE(int_kernel_1_2(31 downto 0), 32);
                    when ADDR_KERNEL_2_0_DATA_0 =>
                        rdata_data <= RESIZE(int_kernel_2_0(31 downto 0), 32);
                    when ADDR_KERNEL_2_1_DATA_0 =>
                        rdata_data <= RESIZE(int_kernel_2_1(31 downto 0), 32);
                    when ADDR_KERNEL_2_2_DATA_0 =>
                        rdata_data <= RESIZE(int_kernel_2_2(31 downto 0), 32);
                    when others =>
                        rdata_data <= (others => '0');
                    end case;
                elsif (int_input_0_read = '1') then
                    rdata_data <= int_input_0_q1;
                elsif (int_input_1_read = '1') then
                    rdata_data <= int_input_1_q1;
                elsif (int_input_2_read = '1') then
                    rdata_data <= int_input_2_q1;
                elsif (int_output_r_read = '1') then
                    rdata_data <= int_output_r_q1;
                end if;
            end if;
        end if;
    end process;

-- ----------------------- Register logic ----------------
    interrupt            <= int_gie and (int_isr(0) or int_isr(1));
    ap_start             <= int_ap_start;
    kernel_0_0           <= STD_LOGIC_VECTOR(int_kernel_0_0);
    kernel_0_1           <= STD_LOGIC_VECTOR(int_kernel_0_1);
    kernel_0_2           <= STD_LOGIC_VECTOR(int_kernel_0_2);
    kernel_1_0           <= STD_LOGIC_VECTOR(int_kernel_1_0);
    kernel_1_1           <= STD_LOGIC_VECTOR(int_kernel_1_1);
    kernel_1_2           <= STD_LOGIC_VECTOR(int_kernel_1_2);
    kernel_2_0           <= STD_LOGIC_VECTOR(int_kernel_2_0);
    kernel_2_1           <= STD_LOGIC_VECTOR(int_kernel_2_1);
    kernel_2_2           <= STD_LOGIC_VECTOR(int_kernel_2_2);

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_ap_start <= '0';
            elsif (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_AP_CTRL and WSTRB(0) = '1' and WDATA(0) = '1') then
                    int_ap_start <= '1';
                elsif (ap_ready = '1') then
                    int_ap_start <= int_auto_restart; -- clear on handshake/auto restart
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_ap_done <= '0';
            elsif (ACLK_EN = '1') then
                if (ap_done = '1') then
                    int_ap_done <= '1';
                elsif (ar_hs = '1' and raddr = ADDR_AP_CTRL) then
                    int_ap_done <= '0'; -- clear on read
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_ap_idle <= '0';
            elsif (ACLK_EN = '1') then
                if (true) then
                    int_ap_idle <= ap_idle;
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_ap_ready <= '0';
            elsif (ACLK_EN = '1') then
                if (true) then
                    int_ap_ready <= ap_ready;
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_auto_restart <= '0';
            elsif (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_AP_CTRL and WSTRB(0) = '1') then
                    int_auto_restart <= WDATA(7);
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_gie <= '0';
            elsif (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_GIE and WSTRB(0) = '1') then
                    int_gie <= WDATA(0);
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_ier <= "00";
            elsif (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_IER and WSTRB(0) = '1') then
                    int_ier <= UNSIGNED(WDATA(1 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_isr(0) <= '0';
            elsif (ACLK_EN = '1') then
                if (int_ier(0) = '1' and ap_done = '1') then
                    int_isr(0) <= '1';
                elsif (w_hs = '1' and waddr = ADDR_ISR and WSTRB(0) = '1') then
                    int_isr(0) <= int_isr(0) xor WDATA(0); -- toggle on write
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_isr(1) <= '0';
            elsif (ACLK_EN = '1') then
                if (int_ier(1) = '1' and ap_ready = '1') then
                    int_isr(1) <= '1';
                elsif (w_hs = '1' and waddr = ADDR_ISR and WSTRB(0) = '1') then
                    int_isr(1) <= int_isr(1) xor WDATA(1); -- toggle on write
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_KERNEL_0_0_DATA_0) then
                    int_kernel_0_0(31 downto 0) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_kernel_0_0(31 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_KERNEL_0_1_DATA_0) then
                    int_kernel_0_1(31 downto 0) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_kernel_0_1(31 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_KERNEL_0_2_DATA_0) then
                    int_kernel_0_2(31 downto 0) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_kernel_0_2(31 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_KERNEL_1_0_DATA_0) then
                    int_kernel_1_0(31 downto 0) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_kernel_1_0(31 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_KERNEL_1_1_DATA_0) then
                    int_kernel_1_1(31 downto 0) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_kernel_1_1(31 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_KERNEL_1_2_DATA_0) then
                    int_kernel_1_2(31 downto 0) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_kernel_1_2(31 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_KERNEL_2_0_DATA_0) then
                    int_kernel_2_0(31 downto 0) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_kernel_2_0(31 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_KERNEL_2_1_DATA_0) then
                    int_kernel_2_1(31 downto 0) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_kernel_2_1(31 downto 0));
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ACLK_EN = '1') then
                if (w_hs = '1' and waddr = ADDR_KERNEL_2_2_DATA_0) then
                    int_kernel_2_2(31 downto 0) <= (UNSIGNED(WDATA(31 downto 0)) and wmask(31 downto 0)) or ((not wmask(31 downto 0)) and int_kernel_2_2(31 downto 0));
                end if;
            end if;
        end if;
    end process;


-- ----------------------- Memory logic ------------------
    -- input_0
    int_input_0_address0 <= UNSIGNED(input_0_address0);
    int_input_0_ce0      <= input_0_ce0;
    int_input_0_we0      <= '0';
    int_input_0_be0      <= (others => '0');
    int_input_0_d0       <= (others => '0');
    input_0_q0           <= STD_LOGIC_VECTOR(RESIZE(int_input_0_q0, 32));
    int_input_0_address1 <= raddr(5 downto 2) when ar_hs = '1' else waddr(5 downto 2);
    int_input_0_ce1      <= '1' when ar_hs = '1' or (int_input_0_write = '1' and WVALID  = '1') else '0';
    int_input_0_we1      <= '1' when int_input_0_write = '1' and WVALID = '1' else '0';
    int_input_0_be1      <= UNSIGNED(WSTRB);
    int_input_0_d1       <= UNSIGNED(WDATA);
    -- input_1
    int_input_1_address0 <= UNSIGNED(input_1_address0);
    int_input_1_ce0      <= input_1_ce0;
    int_input_1_we0      <= '0';
    int_input_1_be0      <= (others => '0');
    int_input_1_d0       <= (others => '0');
    input_1_q0           <= STD_LOGIC_VECTOR(RESIZE(int_input_1_q0, 32));
    int_input_1_address1 <= raddr(5 downto 2) when ar_hs = '1' else waddr(5 downto 2);
    int_input_1_ce1      <= '1' when ar_hs = '1' or (int_input_1_write = '1' and WVALID  = '1') else '0';
    int_input_1_we1      <= '1' when int_input_1_write = '1' and WVALID = '1' else '0';
    int_input_1_be1      <= UNSIGNED(WSTRB);
    int_input_1_d1       <= UNSIGNED(WDATA);
    -- input_2
    int_input_2_address0 <= UNSIGNED(input_2_address0);
    int_input_2_ce0      <= input_2_ce0;
    int_input_2_we0      <= '0';
    int_input_2_be0      <= (others => '0');
    int_input_2_d0       <= (others => '0');
    input_2_q0           <= STD_LOGIC_VECTOR(RESIZE(int_input_2_q0, 32));
    int_input_2_address1 <= raddr(4 downto 2) when ar_hs = '1' else waddr(4 downto 2);
    int_input_2_ce1      <= '1' when ar_hs = '1' or (int_input_2_write = '1' and WVALID  = '1') else '0';
    int_input_2_we1      <= '1' when int_input_2_write = '1' and WVALID = '1' else '0';
    int_input_2_be1      <= UNSIGNED(WSTRB);
    int_input_2_d1       <= UNSIGNED(WDATA);
    -- output_r
    int_output_r_address0 <= UNSIGNED(output_r_address0);
    int_output_r_ce0     <= output_r_ce0;
    int_output_r_we0     <= output_r_we0;
    int_output_r_be0     <= (others => output_r_we0);
    int_output_r_d0      <= RESIZE(UNSIGNED(output_r_d0), 32);
    int_output_r_address1 <= raddr(5 downto 2) when ar_hs = '1' else waddr(5 downto 2);
    int_output_r_ce1     <= '1' when ar_hs = '1' or (int_output_r_write = '1' and WVALID  = '1') else '0';
    int_output_r_we1     <= '1' when int_output_r_write = '1' and WVALID = '1' else '0';
    int_output_r_be1     <= UNSIGNED(WSTRB);
    int_output_r_d1      <= UNSIGNED(WDATA);

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_input_0_read <= '0';
            elsif (ACLK_EN = '1') then
                if (ar_hs = '1' and raddr >= ADDR_INPUT_0_BASE and raddr <= ADDR_INPUT_0_HIGH) then
                    int_input_0_read <= '1';
                else
                    int_input_0_read <= '0';
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_input_0_write <= '0';
            elsif (ACLK_EN = '1') then
                if (aw_hs = '1' and UNSIGNED(AWADDR(ADDR_BITS-1 downto 0)) >= ADDR_INPUT_0_BASE and UNSIGNED(AWADDR(ADDR_BITS-1 downto 0)) <= ADDR_INPUT_0_HIGH) then
                    int_input_0_write <= '1';
                elsif (WVALID = '1') then
                    int_input_0_write <= '0';
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_input_1_read <= '0';
            elsif (ACLK_EN = '1') then
                if (ar_hs = '1' and raddr >= ADDR_INPUT_1_BASE and raddr <= ADDR_INPUT_1_HIGH) then
                    int_input_1_read <= '1';
                else
                    int_input_1_read <= '0';
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_input_1_write <= '0';
            elsif (ACLK_EN = '1') then
                if (aw_hs = '1' and UNSIGNED(AWADDR(ADDR_BITS-1 downto 0)) >= ADDR_INPUT_1_BASE and UNSIGNED(AWADDR(ADDR_BITS-1 downto 0)) <= ADDR_INPUT_1_HIGH) then
                    int_input_1_write <= '1';
                elsif (WVALID = '1') then
                    int_input_1_write <= '0';
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_input_2_read <= '0';
            elsif (ACLK_EN = '1') then
                if (ar_hs = '1' and raddr >= ADDR_INPUT_2_BASE and raddr <= ADDR_INPUT_2_HIGH) then
                    int_input_2_read <= '1';
                else
                    int_input_2_read <= '0';
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_input_2_write <= '0';
            elsif (ACLK_EN = '1') then
                if (aw_hs = '1' and UNSIGNED(AWADDR(ADDR_BITS-1 downto 0)) >= ADDR_INPUT_2_BASE and UNSIGNED(AWADDR(ADDR_BITS-1 downto 0)) <= ADDR_INPUT_2_HIGH) then
                    int_input_2_write <= '1';
                elsif (WVALID = '1') then
                    int_input_2_write <= '0';
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_output_r_read <= '0';
            elsif (ACLK_EN = '1') then
                if (ar_hs = '1' and raddr >= ADDR_OUTPUT_R_BASE and raddr <= ADDR_OUTPUT_R_HIGH) then
                    int_output_r_read <= '1';
                else
                    int_output_r_read <= '0';
                end if;
            end if;
        end if;
    end process;

    process (ACLK)
    begin
        if (ACLK'event and ACLK = '1') then
            if (ARESET = '1') then
                int_output_r_write <= '0';
            elsif (ACLK_EN = '1') then
                if (aw_hs = '1' and UNSIGNED(AWADDR(ADDR_BITS-1 downto 0)) >= ADDR_OUTPUT_R_BASE and UNSIGNED(AWADDR(ADDR_BITS-1 downto 0)) <= ADDR_OUTPUT_R_HIGH) then
                    int_output_r_write <= '1';
                elsif (WVALID = '1') then
                    int_output_r_write <= '0';
                end if;
            end if;
        end if;
    end process;


end architecture behave;

library IEEE;
USE IEEE.std_logic_1164.all;
USE IEEE.numeric_std.all;

entity convolution2D_conv_io_s_axi_ram is
    generic (
        BYTES   : INTEGER :=4;
        DEPTH   : INTEGER :=256;
        AWIDTH  : INTEGER :=8);
    port (
        clk0    : in  STD_LOGIC;
        address0: in  UNSIGNED(AWIDTH-1 downto 0);
        ce0     : in  STD_LOGIC;
        we0     : in  STD_LOGIC;
        be0     : in  UNSIGNED(BYTES-1 downto 0);
        d0      : in  UNSIGNED(BYTES*8-1 downto 0);
        q0      : out UNSIGNED(BYTES*8-1 downto 0);
        clk1    : in  STD_LOGIC;
        address1: in  UNSIGNED(AWIDTH-1 downto 0);
        ce1     : in  STD_LOGIC;
        we1     : in  STD_LOGIC;
        be1     : in  UNSIGNED(BYTES-1 downto 0);
        d1      : in  UNSIGNED(BYTES*8-1 downto 0);
        q1      : out UNSIGNED(BYTES*8-1 downto 0));

end entity convolution2D_conv_io_s_axi_ram;

architecture behave of convolution2D_conv_io_s_axi_ram is
    signal address0_tmp : UNSIGNED(AWIDTH-1 downto 0);
    signal address1_tmp : UNSIGNED(AWIDTH-1 downto 0);
    type RAM_T is array (0 to DEPTH - 1) of UNSIGNED(BYTES*8 - 1 downto 0);
    shared variable mem : RAM_T := (others => (others => '0'));
begin

    process (address0)
    begin
    address0_tmp <= address0;
    --synthesis translate_off
          if (address0 > DEPTH-1) then
              address0_tmp <= (others => '0');
          else
              address0_tmp <= address0;
          end if;
    --synthesis translate_on
    end process;

    process (address1)
    begin
    address1_tmp <= address1;
    --synthesis translate_off
          if (address1 > DEPTH-1) then
              address1_tmp <= (others => '0');
          else
              address1_tmp <= address1;
          end if;
    --synthesis translate_on
    end process;

    --read port 0
    process (clk0) begin
        if (clk0'event and clk0 = '1') then
            if (ce0 = '1') then
                q0 <= mem(to_integer(address0_tmp));
            end if;
        end if;
    end process;

    --read port 1
    process (clk1) begin
        if (clk1'event and clk1 = '1') then
            if (ce1 = '1') then
                q1 <= mem(to_integer(address1_tmp));
            end if;
        end if;
    end process;

    gen_write : for i in 0 to BYTES - 1 generate
    begin
        --write port 0
        process (clk0)
        begin
            if (clk0'event and clk0 = '1') then
                if (ce0 = '1' and we0 = '1' and be0(i) = '1') then
                    mem(to_integer(address0_tmp))(8*i+7 downto 8*i) := d0(8*i+7 downto 8*i);
                end if;
            end if;
        end process;

        --write port 1
        process (clk1)
        begin
            if (clk1'event and clk1 = '1') then
                if (ce1 = '1' and we1 = '1' and be1(i) = '1') then
                    mem(to_integer(address1_tmp))(8*i+7 downto 8*i) := d1(8*i+7 downto 8*i);
                end if;
            end if;
        end process;

    end generate;

end architecture behave;

