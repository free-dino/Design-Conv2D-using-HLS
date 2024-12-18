// ==============================================================
// File generated on Wed Dec 18 21:05:07 +0700 2024
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================

`timescale 1 ns / 1 ps

module AESL_axi_slave_conv_io (
    clk,
    reset,
    TRAN_s_axi_conv_io_AWADDR,
    TRAN_s_axi_conv_io_AWVALID,
    TRAN_s_axi_conv_io_AWREADY,
    TRAN_s_axi_conv_io_WVALID,
    TRAN_s_axi_conv_io_WREADY,
    TRAN_s_axi_conv_io_WDATA,
    TRAN_s_axi_conv_io_WSTRB,
    TRAN_s_axi_conv_io_ARADDR,
    TRAN_s_axi_conv_io_ARVALID,
    TRAN_s_axi_conv_io_ARREADY,
    TRAN_s_axi_conv_io_RVALID,
    TRAN_s_axi_conv_io_RREADY,
    TRAN_s_axi_conv_io_RDATA,
    TRAN_s_axi_conv_io_RRESP,
    TRAN_s_axi_conv_io_BVALID,
    TRAN_s_axi_conv_io_BREADY,
    TRAN_s_axi_conv_io_BRESP,
    TRAN_conv_io_write_data_finish,
    TRAN_conv_io_read_data_finish,
    TRAN_conv_io_start_in,
    TRAN_conv_io_idle_out,
    TRAN_conv_io_ready_out,
    TRAN_conv_io_ready_in,
    TRAN_conv_io_done_out,
    TRAN_conv_io_write_start_in   ,
    TRAN_conv_io_write_start_finish,
    TRAN_conv_io_interrupt,
    TRAN_conv_io_transaction_done_in
    );

//------------------------Parameter----------------------
`define TV_IN_input_0 "./c.convolution2D.autotvin_input_0.dat"
`define TV_IN_input_1 "./c.convolution2D.autotvin_input_1.dat"
`define TV_IN_input_2 "./c.convolution2D.autotvin_input_2.dat"
`define TV_IN_kernel_0_0 "./c.convolution2D.autotvin_kernel_0_0.dat"
`define TV_IN_kernel_0_1 "./c.convolution2D.autotvin_kernel_0_1.dat"
`define TV_IN_kernel_0_2 "./c.convolution2D.autotvin_kernel_0_2.dat"
`define TV_IN_kernel_1_0 "./c.convolution2D.autotvin_kernel_1_0.dat"
`define TV_IN_kernel_1_1 "./c.convolution2D.autotvin_kernel_1_1.dat"
`define TV_IN_kernel_1_2 "./c.convolution2D.autotvin_kernel_1_2.dat"
`define TV_IN_kernel_2_0 "./c.convolution2D.autotvin_kernel_2_0.dat"
`define TV_IN_kernel_2_1 "./c.convolution2D.autotvin_kernel_2_1.dat"
`define TV_IN_kernel_2_2 "./c.convolution2D.autotvin_kernel_2_2.dat"
`define TV_OUT_output_r "./rtl.convolution2D.autotvout_output_r.dat"
parameter ADDR_WIDTH = 9;
parameter DATA_WIDTH = 32;
parameter input_0_DEPTH = 10;
reg [31 : 0] input_0_OPERATE_DEPTH = 0;
parameter input_0_c_bitwidth = 32;
parameter input_1_DEPTH = 10;
reg [31 : 0] input_1_OPERATE_DEPTH = 0;
parameter input_1_c_bitwidth = 32;
parameter input_2_DEPTH = 5;
reg [31 : 0] input_2_OPERATE_DEPTH = 0;
parameter input_2_c_bitwidth = 32;
parameter kernel_0_0_DEPTH = 1;
reg [31 : 0] kernel_0_0_OPERATE_DEPTH = 0;
parameter kernel_0_0_c_bitwidth = 32;
parameter kernel_0_1_DEPTH = 1;
reg [31 : 0] kernel_0_1_OPERATE_DEPTH = 0;
parameter kernel_0_1_c_bitwidth = 32;
parameter kernel_0_2_DEPTH = 1;
reg [31 : 0] kernel_0_2_OPERATE_DEPTH = 0;
parameter kernel_0_2_c_bitwidth = 32;
parameter kernel_1_0_DEPTH = 1;
reg [31 : 0] kernel_1_0_OPERATE_DEPTH = 0;
parameter kernel_1_0_c_bitwidth = 32;
parameter kernel_1_1_DEPTH = 1;
reg [31 : 0] kernel_1_1_OPERATE_DEPTH = 0;
parameter kernel_1_1_c_bitwidth = 32;
parameter kernel_1_2_DEPTH = 1;
reg [31 : 0] kernel_1_2_OPERATE_DEPTH = 0;
parameter kernel_1_2_c_bitwidth = 32;
parameter kernel_2_0_DEPTH = 1;
reg [31 : 0] kernel_2_0_OPERATE_DEPTH = 0;
parameter kernel_2_0_c_bitwidth = 32;
parameter kernel_2_1_DEPTH = 1;
reg [31 : 0] kernel_2_1_OPERATE_DEPTH = 0;
parameter kernel_2_1_c_bitwidth = 32;
parameter kernel_2_2_DEPTH = 1;
reg [31 : 0] kernel_2_2_OPERATE_DEPTH = 0;
parameter kernel_2_2_c_bitwidth = 32;
parameter output_r_DEPTH = 9;
reg [31 : 0] output_r_OPERATE_DEPTH = 0;
parameter output_r_c_bitwidth = 32;
parameter START_ADDR = 0;
parameter convolution2D_continue_addr = 0;
parameter convolution2D_auto_start_addr = 0;
parameter input_0_data_in_addr = 64;
parameter input_1_data_in_addr = 128;
parameter input_2_data_in_addr = 192;
parameter kernel_0_0_data_in_addr = 224;
parameter kernel_0_1_data_in_addr = 232;
parameter kernel_0_2_data_in_addr = 240;
parameter kernel_1_0_data_in_addr = 248;
parameter kernel_1_1_data_in_addr = 256;
parameter kernel_1_2_data_in_addr = 264;
parameter kernel_2_0_data_in_addr = 272;
parameter kernel_2_1_data_in_addr = 280;
parameter kernel_2_2_data_in_addr = 288;
parameter output_r_data_out_addr = 320;
parameter STATUS_ADDR = 0;

output [ADDR_WIDTH - 1 : 0] TRAN_s_axi_conv_io_AWADDR;
output  TRAN_s_axi_conv_io_AWVALID;
input  TRAN_s_axi_conv_io_AWREADY;
output  TRAN_s_axi_conv_io_WVALID;
input  TRAN_s_axi_conv_io_WREADY;
output [DATA_WIDTH - 1 : 0] TRAN_s_axi_conv_io_WDATA;
output [DATA_WIDTH/8 - 1 : 0] TRAN_s_axi_conv_io_WSTRB;
output [ADDR_WIDTH - 1 : 0] TRAN_s_axi_conv_io_ARADDR;
output  TRAN_s_axi_conv_io_ARVALID;
input  TRAN_s_axi_conv_io_ARREADY;
input  TRAN_s_axi_conv_io_RVALID;
output  TRAN_s_axi_conv_io_RREADY;
input [DATA_WIDTH - 1 : 0] TRAN_s_axi_conv_io_RDATA;
input [2 - 1 : 0] TRAN_s_axi_conv_io_RRESP;
input  TRAN_s_axi_conv_io_BVALID;
output  TRAN_s_axi_conv_io_BREADY;
input [2 - 1 : 0] TRAN_s_axi_conv_io_BRESP;
output TRAN_conv_io_write_data_finish;
output TRAN_conv_io_read_data_finish;
input     clk;
input     reset;
input     TRAN_conv_io_start_in;
output    TRAN_conv_io_done_out;
output    TRAN_conv_io_ready_out;
input     TRAN_conv_io_ready_in;
output    TRAN_conv_io_idle_out;
input  TRAN_conv_io_write_start_in   ;
output TRAN_conv_io_write_start_finish;
input     TRAN_conv_io_interrupt;
input     TRAN_conv_io_transaction_done_in;

reg [ADDR_WIDTH - 1 : 0] AWADDR_reg = 0;
reg  AWVALID_reg = 0;
reg  WVALID_reg = 0;
reg [DATA_WIDTH - 1 : 0] WDATA_reg = 0;
reg [DATA_WIDTH/8 - 1 : 0] WSTRB_reg = 0;
reg [ADDR_WIDTH - 1 : 0] ARADDR_reg = 0;
reg  ARVALID_reg = 0;
reg  RREADY_reg = 0;
reg [DATA_WIDTH - 1 : 0] RDATA_reg = 0;
reg  BREADY_reg = 0;
reg [DATA_WIDTH - 1 : 0] mem_input_0 [input_0_DEPTH - 1 : 0];
reg input_0_write_data_finish;
reg [DATA_WIDTH - 1 : 0] mem_input_1 [input_1_DEPTH - 1 : 0];
reg input_1_write_data_finish;
reg [DATA_WIDTH - 1 : 0] mem_input_2 [input_2_DEPTH - 1 : 0];
reg input_2_write_data_finish;
reg [DATA_WIDTH - 1 : 0] mem_kernel_0_0 [kernel_0_0_DEPTH - 1 : 0];
reg kernel_0_0_write_data_finish;
reg [DATA_WIDTH - 1 : 0] mem_kernel_0_1 [kernel_0_1_DEPTH - 1 : 0];
reg kernel_0_1_write_data_finish;
reg [DATA_WIDTH - 1 : 0] mem_kernel_0_2 [kernel_0_2_DEPTH - 1 : 0];
reg kernel_0_2_write_data_finish;
reg [DATA_WIDTH - 1 : 0] mem_kernel_1_0 [kernel_1_0_DEPTH - 1 : 0];
reg kernel_1_0_write_data_finish;
reg [DATA_WIDTH - 1 : 0] mem_kernel_1_1 [kernel_1_1_DEPTH - 1 : 0];
reg kernel_1_1_write_data_finish;
reg [DATA_WIDTH - 1 : 0] mem_kernel_1_2 [kernel_1_2_DEPTH - 1 : 0];
reg kernel_1_2_write_data_finish;
reg [DATA_WIDTH - 1 : 0] mem_kernel_2_0 [kernel_2_0_DEPTH - 1 : 0];
reg kernel_2_0_write_data_finish;
reg [DATA_WIDTH - 1 : 0] mem_kernel_2_1 [kernel_2_1_DEPTH - 1 : 0];
reg kernel_2_1_write_data_finish;
reg [DATA_WIDTH - 1 : 0] mem_kernel_2_2 [kernel_2_2_DEPTH - 1 : 0];
reg kernel_2_2_write_data_finish;
reg [DATA_WIDTH - 1 : 0] mem_output_r [output_r_DEPTH - 1 : 0];
reg output_r_read_data_finish;
reg AESL_ready_out_index_reg = 0;
reg AESL_write_start_finish = 0;
reg AESL_ready_reg;
reg ready_initial;
reg AESL_done_index_reg = 0;
reg AESL_idle_index_reg = 0;
reg AESL_auto_restart_index_reg;
reg process_0_finish = 0;
reg process_1_finish = 0;
reg process_2_finish = 0;
reg process_3_finish = 0;
reg process_4_finish = 0;
reg process_5_finish = 0;
reg process_6_finish = 0;
reg process_7_finish = 0;
reg process_8_finish = 0;
reg process_9_finish = 0;
reg process_10_finish = 0;
reg process_11_finish = 0;
reg process_12_finish = 0;
reg process_13_finish = 0;
reg process_14_finish = 0;
//write input_0 reg
reg [31 : 0] write_input_0_count = 0;
reg write_input_0_run_flag = 0;
reg write_one_input_0_data_done = 0;
//write input_1 reg
reg [31 : 0] write_input_1_count = 0;
reg write_input_1_run_flag = 0;
reg write_one_input_1_data_done = 0;
//write input_2 reg
reg [31 : 0] write_input_2_count = 0;
reg write_input_2_run_flag = 0;
reg write_one_input_2_data_done = 0;
//write kernel_0_0 reg
reg [31 : 0] write_kernel_0_0_count = 0;
reg write_kernel_0_0_run_flag = 0;
reg write_one_kernel_0_0_data_done = 0;
//write kernel_0_1 reg
reg [31 : 0] write_kernel_0_1_count = 0;
reg write_kernel_0_1_run_flag = 0;
reg write_one_kernel_0_1_data_done = 0;
//write kernel_0_2 reg
reg [31 : 0] write_kernel_0_2_count = 0;
reg write_kernel_0_2_run_flag = 0;
reg write_one_kernel_0_2_data_done = 0;
//write kernel_1_0 reg
reg [31 : 0] write_kernel_1_0_count = 0;
reg write_kernel_1_0_run_flag = 0;
reg write_one_kernel_1_0_data_done = 0;
//write kernel_1_1 reg
reg [31 : 0] write_kernel_1_1_count = 0;
reg write_kernel_1_1_run_flag = 0;
reg write_one_kernel_1_1_data_done = 0;
//write kernel_1_2 reg
reg [31 : 0] write_kernel_1_2_count = 0;
reg write_kernel_1_2_run_flag = 0;
reg write_one_kernel_1_2_data_done = 0;
//write kernel_2_0 reg
reg [31 : 0] write_kernel_2_0_count = 0;
reg write_kernel_2_0_run_flag = 0;
reg write_one_kernel_2_0_data_done = 0;
//write kernel_2_1 reg
reg [31 : 0] write_kernel_2_1_count = 0;
reg write_kernel_2_1_run_flag = 0;
reg write_one_kernel_2_1_data_done = 0;
//write kernel_2_2 reg
reg [31 : 0] write_kernel_2_2_count = 0;
reg write_kernel_2_2_run_flag = 0;
reg write_one_kernel_2_2_data_done = 0;
//read output_r reg
reg [31 : 0] read_output_r_count = 0;
reg read_output_r_run_flag = 0;
reg read_one_output_r_data_done = 0;
reg [31 : 0] write_start_count = 0;
reg write_start_run_flag = 0;

//===================process control=================
reg [31 : 0] ongoing_process_number = 0;
//process number depends on how much processes needed.
reg process_busy = 0;

//=================== signal connection ==============
assign TRAN_s_axi_conv_io_AWADDR = AWADDR_reg;
assign TRAN_s_axi_conv_io_AWVALID = AWVALID_reg;
assign TRAN_s_axi_conv_io_WVALID = WVALID_reg;
assign TRAN_s_axi_conv_io_WDATA = WDATA_reg;
assign TRAN_s_axi_conv_io_WSTRB = WSTRB_reg;
assign TRAN_s_axi_conv_io_ARADDR = ARADDR_reg;
assign TRAN_s_axi_conv_io_ARVALID = ARVALID_reg;
assign TRAN_s_axi_conv_io_RREADY = RREADY_reg;
assign TRAN_s_axi_conv_io_BREADY = BREADY_reg;
assign TRAN_conv_io_write_start_finish = AESL_write_start_finish;
assign TRAN_conv_io_done_out = AESL_done_index_reg;
assign TRAN_conv_io_ready_out = AESL_ready_out_index_reg;
assign TRAN_conv_io_idle_out = AESL_idle_index_reg;
assign TRAN_conv_io_read_data_finish = 1 & output_r_read_data_finish;
assign TRAN_conv_io_write_data_finish = 1 & input_0_write_data_finish & input_1_write_data_finish & input_2_write_data_finish & kernel_0_0_write_data_finish & kernel_0_1_write_data_finish & kernel_0_2_write_data_finish & kernel_1_0_write_data_finish & kernel_1_1_write_data_finish & kernel_1_2_write_data_finish & kernel_2_0_write_data_finish & kernel_2_1_write_data_finish & kernel_2_2_write_data_finish;
always @(TRAN_conv_io_ready_in or ready_initial) 
begin
    AESL_ready_reg <= TRAN_conv_io_ready_in | ready_initial;
end

always @(reset or process_0_finish or process_1_finish or process_2_finish or process_3_finish or process_4_finish or process_5_finish or process_6_finish or process_7_finish or process_8_finish or process_9_finish or process_10_finish or process_11_finish or process_12_finish or process_13_finish or process_14_finish ) begin
    if (reset == 0) begin
        ongoing_process_number <= 0;
    end
    else if (ongoing_process_number == 0 && process_0_finish == 1) begin
            ongoing_process_number <= ongoing_process_number + 1;
    end
    else if (ongoing_process_number == 1 && process_1_finish == 1) begin
            ongoing_process_number <= ongoing_process_number + 1;
    end
    else if (ongoing_process_number == 2 && process_2_finish == 1) begin
            ongoing_process_number <= ongoing_process_number + 1;
    end
    else if (ongoing_process_number == 3 && process_3_finish == 1) begin
            ongoing_process_number <= ongoing_process_number + 1;
    end
    else if (ongoing_process_number == 4 && process_4_finish == 1) begin
            ongoing_process_number <= ongoing_process_number + 1;
    end
    else if (ongoing_process_number == 5 && process_5_finish == 1) begin
            ongoing_process_number <= ongoing_process_number + 1;
    end
    else if (ongoing_process_number == 6 && process_6_finish == 1) begin
            ongoing_process_number <= ongoing_process_number + 1;
    end
    else if (ongoing_process_number == 7 && process_7_finish == 1) begin
            ongoing_process_number <= ongoing_process_number + 1;
    end
    else if (ongoing_process_number == 8 && process_8_finish == 1) begin
            ongoing_process_number <= ongoing_process_number + 1;
    end
    else if (ongoing_process_number == 9 && process_9_finish == 1) begin
            ongoing_process_number <= ongoing_process_number + 1;
    end
    else if (ongoing_process_number == 10 && process_10_finish == 1) begin
            ongoing_process_number <= ongoing_process_number + 1;
    end
    else if (ongoing_process_number == 11 && process_11_finish == 1) begin
            ongoing_process_number <= ongoing_process_number + 1;
    end
    else if (ongoing_process_number == 12 && process_12_finish == 1) begin
            ongoing_process_number <= ongoing_process_number + 1;
    end
    else if (ongoing_process_number == 13 && process_13_finish == 1) begin
            ongoing_process_number <= ongoing_process_number + 1;
    end
    else if (ongoing_process_number == 14 && process_14_finish == 1) begin
            ongoing_process_number <= 0;
    end
end

task count_c_data_four_byte_num_by_bitwidth;
input  integer bitwidth;
output integer num;
integer factor;
integer i;
begin
    factor = 32;
    for (i = 1; i <= 32; i = i + 1) begin
        if (bitwidth <= factor && bitwidth > factor - 32) begin
            num = i;
        end
        factor = factor + 32;
    end
end    
endtask

task count_seperate_factor_by_bitwidth;
input  integer bitwidth;
output integer factor;
begin
    if (bitwidth <= 8 ) begin
        factor=4;
    end
    if (bitwidth <= 16 & bitwidth > 8 ) begin
        factor=2;
    end
    if (bitwidth <= 32 & bitwidth > 16 ) begin
        factor=1;
    end
    if (bitwidth <= 1024 & bitwidth > 32 ) begin
        factor=1;
    end
end    
endtask

task count_operate_depth_by_bitwidth_and_depth;
input  integer bitwidth;
input  integer depth;
output integer operate_depth;
integer factor;
integer remain;
begin
    count_seperate_factor_by_bitwidth (bitwidth , factor);
    operate_depth = depth / factor;
    remain = depth % factor;
    if (remain > 0) begin
        operate_depth = operate_depth + 1;
    end
end    
endtask

task write; /*{{{*/
    input  reg [ADDR_WIDTH - 1:0] waddr;   // write address
    input  reg [DATA_WIDTH - 1:0] wdata;   // write data
    output reg wresp;
    reg aw_flag;
    reg w_flag;
    reg [DATA_WIDTH/8 - 1:0] wstrb_reg;
    integer i;
begin 
    wresp = 0;
    aw_flag = 0;
    w_flag = 0;
//=======================one single write operate======================
    AWADDR_reg <= waddr;
    AWVALID_reg <= 1;
    WDATA_reg <= wdata;
    WVALID_reg <= 1;
    for (i = 0; i < DATA_WIDTH/8; i = i + 1) begin
        wstrb_reg [i] = 1;
    end    
    WSTRB_reg <= wstrb_reg;
    while (!(aw_flag && w_flag)) begin
        @(posedge clk);
        if (aw_flag != 1)
            aw_flag = TRAN_s_axi_conv_io_AWREADY & AWVALID_reg;
        if (w_flag != 1)
            w_flag = TRAN_s_axi_conv_io_WREADY & WVALID_reg;
        AWVALID_reg <= !aw_flag;
        WVALID_reg <= !w_flag;
    end

    BREADY_reg <= 1;
    while (TRAN_s_axi_conv_io_BVALID != 1) begin
        //wait for response 
        @(posedge clk);
    end
    @(posedge clk);
    BREADY_reg <= 0;
    if (TRAN_s_axi_conv_io_BRESP === 2'b00) begin
        wresp = 1;
        //input success. in fact BRESP is always 2'b00
    end   
//=======================one single write operate======================

end
endtask/*}}}*/

task read (/*{{{*/
    input  [ADDR_WIDTH - 1:0] raddr ,   // write address
    output [DATA_WIDTH - 1:0] RDATA_result ,
    output rresp
);
begin 
    rresp = 0;
//=======================one single read operate======================
    ARADDR_reg <= raddr;
    ARVALID_reg <= 1;
    while (TRAN_s_axi_conv_io_ARREADY !== 1) begin
        @(posedge clk);
    end
    @(posedge clk);
    ARVALID_reg <= 0;
    RREADY_reg <= 1;
    while (TRAN_s_axi_conv_io_RVALID !== 1) begin
        //wait for response 
        @(posedge clk);
    end
    @(posedge clk);
    RDATA_result  <= TRAN_s_axi_conv_io_RDATA;
    RREADY_reg <= 0;
    if (TRAN_s_axi_conv_io_RRESP === 2'b00 ) begin
        rresp <= 1;
        //output success. in fact RRESP is always 2'b00
    end  
    @(posedge clk);

//=======================one single read operate end======================

end
endtask/*}}}*/

initial begin : ready_initial_process
    ready_initial = 0;
    wait(reset === 1);
    @(posedge clk);
    ready_initial = 1;
    @(posedge clk);
    ready_initial = 0;
end

initial begin : update_status
    integer process_num ;
    integer read_status_resp;
    wait(reset === 1);
    @(posedge clk);
    process_num = 0;
    while (1) begin
        process_0_finish = 0;
        AESL_done_index_reg         <= 0;
        AESL_ready_out_index_reg        <= 0;
        if (ongoing_process_number === process_num && process_busy === 0) begin
            process_busy = 1;
            read (STATUS_ADDR, RDATA_reg, read_status_resp);
                AESL_done_index_reg         <= RDATA_reg[1 : 1];
                AESL_ready_out_index_reg    <= RDATA_reg[1 : 1];
                AESL_idle_index_reg         <= RDATA_reg[2 : 2];
            process_0_finish = 1;
            process_busy = 0;
        end 
        @(posedge clk);
    end
end

always @(reset or posedge clk) begin
    if (reset == 0) begin
        input_0_write_data_finish <= 0;
        write_input_0_run_flag <= 0; 
        write_input_0_count = 0;
        count_operate_depth_by_bitwidth_and_depth (input_0_c_bitwidth, input_0_DEPTH, input_0_OPERATE_DEPTH);
    end
    else begin
        if (TRAN_conv_io_start_in === 1) begin
            input_0_write_data_finish <= 0;
        end
        if (AESL_ready_reg === 1) begin
            write_input_0_run_flag <= 1; 
            write_input_0_count = 0;
        end
        if (write_one_input_0_data_done === 1) begin
            write_input_0_count = write_input_0_count + 1;
            if (write_input_0_count == input_0_OPERATE_DEPTH) begin
                write_input_0_run_flag <= 0; 
                input_0_write_data_finish <= 1;
            end
        end
    end
end

initial begin : write_input_0
    integer write_input_0_resp;
    integer process_num ;
    integer get_ack;
    integer four_byte_num;
    integer c_bitwidth;
    integer i;
    integer j;
    reg [31 : 0] input_0_data_tmp_reg;
    wait(reset === 1);
    @(posedge clk);
    c_bitwidth = input_0_c_bitwidth;
    process_num = 1;
    count_c_data_four_byte_num_by_bitwidth (c_bitwidth , four_byte_num) ;
    while (1) begin
        process_1_finish <= 0;

        if (ongoing_process_number === process_num && process_busy === 0 ) begin
            get_ack = 1;
            if (write_input_0_run_flag === 1 && get_ack === 1) begin
                process_busy = 1;
                //write input_0 data 
                for (i = 0 ; i < four_byte_num ; i = i+1) begin
                    if (input_0_c_bitwidth < 32) begin
                        input_0_data_tmp_reg = mem_input_0[write_input_0_count];
                    end
                    else begin
                        for (j=0 ; j<32 ; j = j + 1) begin
                            if (i*32 + j < input_0_c_bitwidth) begin
                                input_0_data_tmp_reg[j] = mem_input_0[write_input_0_count][i*32 + j];
                            end
                            else begin
                                input_0_data_tmp_reg[j] = 0;
                            end
                        end
                    end
                    write (input_0_data_in_addr + write_input_0_count * four_byte_num * 4 + i * 4, input_0_data_tmp_reg, write_input_0_resp);
                end
                process_busy = 0;
                write_one_input_0_data_done <= 1;
                @(posedge clk);
                write_one_input_0_data_done <= 0;
            end   
            process_1_finish <= 1;
        end
        @(posedge clk);
    end    
end
always @(reset or posedge clk) begin
    if (reset == 0) begin
        input_1_write_data_finish <= 0;
        write_input_1_run_flag <= 0; 
        write_input_1_count = 0;
        count_operate_depth_by_bitwidth_and_depth (input_1_c_bitwidth, input_1_DEPTH, input_1_OPERATE_DEPTH);
    end
    else begin
        if (TRAN_conv_io_start_in === 1) begin
            input_1_write_data_finish <= 0;
        end
        if (AESL_ready_reg === 1) begin
            write_input_1_run_flag <= 1; 
            write_input_1_count = 0;
        end
        if (write_one_input_1_data_done === 1) begin
            write_input_1_count = write_input_1_count + 1;
            if (write_input_1_count == input_1_OPERATE_DEPTH) begin
                write_input_1_run_flag <= 0; 
                input_1_write_data_finish <= 1;
            end
        end
    end
end

initial begin : write_input_1
    integer write_input_1_resp;
    integer process_num ;
    integer get_ack;
    integer four_byte_num;
    integer c_bitwidth;
    integer i;
    integer j;
    reg [31 : 0] input_1_data_tmp_reg;
    wait(reset === 1);
    @(posedge clk);
    c_bitwidth = input_1_c_bitwidth;
    process_num = 2;
    count_c_data_four_byte_num_by_bitwidth (c_bitwidth , four_byte_num) ;
    while (1) begin
        process_2_finish <= 0;

        if (ongoing_process_number === process_num && process_busy === 0 ) begin
            get_ack = 1;
            if (write_input_1_run_flag === 1 && get_ack === 1) begin
                process_busy = 1;
                //write input_1 data 
                for (i = 0 ; i < four_byte_num ; i = i+1) begin
                    if (input_1_c_bitwidth < 32) begin
                        input_1_data_tmp_reg = mem_input_1[write_input_1_count];
                    end
                    else begin
                        for (j=0 ; j<32 ; j = j + 1) begin
                            if (i*32 + j < input_1_c_bitwidth) begin
                                input_1_data_tmp_reg[j] = mem_input_1[write_input_1_count][i*32 + j];
                            end
                            else begin
                                input_1_data_tmp_reg[j] = 0;
                            end
                        end
                    end
                    write (input_1_data_in_addr + write_input_1_count * four_byte_num * 4 + i * 4, input_1_data_tmp_reg, write_input_1_resp);
                end
                process_busy = 0;
                write_one_input_1_data_done <= 1;
                @(posedge clk);
                write_one_input_1_data_done <= 0;
            end   
            process_2_finish <= 1;
        end
        @(posedge clk);
    end    
end
always @(reset or posedge clk) begin
    if (reset == 0) begin
        input_2_write_data_finish <= 0;
        write_input_2_run_flag <= 0; 
        write_input_2_count = 0;
        count_operate_depth_by_bitwidth_and_depth (input_2_c_bitwidth, input_2_DEPTH, input_2_OPERATE_DEPTH);
    end
    else begin
        if (TRAN_conv_io_start_in === 1) begin
            input_2_write_data_finish <= 0;
        end
        if (AESL_ready_reg === 1) begin
            write_input_2_run_flag <= 1; 
            write_input_2_count = 0;
        end
        if (write_one_input_2_data_done === 1) begin
            write_input_2_count = write_input_2_count + 1;
            if (write_input_2_count == input_2_OPERATE_DEPTH) begin
                write_input_2_run_flag <= 0; 
                input_2_write_data_finish <= 1;
            end
        end
    end
end

initial begin : write_input_2
    integer write_input_2_resp;
    integer process_num ;
    integer get_ack;
    integer four_byte_num;
    integer c_bitwidth;
    integer i;
    integer j;
    reg [31 : 0] input_2_data_tmp_reg;
    wait(reset === 1);
    @(posedge clk);
    c_bitwidth = input_2_c_bitwidth;
    process_num = 3;
    count_c_data_four_byte_num_by_bitwidth (c_bitwidth , four_byte_num) ;
    while (1) begin
        process_3_finish <= 0;

        if (ongoing_process_number === process_num && process_busy === 0 ) begin
            get_ack = 1;
            if (write_input_2_run_flag === 1 && get_ack === 1) begin
                process_busy = 1;
                //write input_2 data 
                for (i = 0 ; i < four_byte_num ; i = i+1) begin
                    if (input_2_c_bitwidth < 32) begin
                        input_2_data_tmp_reg = mem_input_2[write_input_2_count];
                    end
                    else begin
                        for (j=0 ; j<32 ; j = j + 1) begin
                            if (i*32 + j < input_2_c_bitwidth) begin
                                input_2_data_tmp_reg[j] = mem_input_2[write_input_2_count][i*32 + j];
                            end
                            else begin
                                input_2_data_tmp_reg[j] = 0;
                            end
                        end
                    end
                    write (input_2_data_in_addr + write_input_2_count * four_byte_num * 4 + i * 4, input_2_data_tmp_reg, write_input_2_resp);
                end
                process_busy = 0;
                write_one_input_2_data_done <= 1;
                @(posedge clk);
                write_one_input_2_data_done <= 0;
            end   
            process_3_finish <= 1;
        end
        @(posedge clk);
    end    
end
always @(reset or posedge clk) begin
    if (reset == 0) begin
        kernel_0_0_write_data_finish <= 0;
        write_kernel_0_0_run_flag <= 0; 
        write_kernel_0_0_count = 0;
        count_operate_depth_by_bitwidth_and_depth (kernel_0_0_c_bitwidth, kernel_0_0_DEPTH, kernel_0_0_OPERATE_DEPTH);
    end
    else begin
        if (TRAN_conv_io_start_in === 1) begin
            kernel_0_0_write_data_finish <= 0;
        end
        if (AESL_ready_reg === 1) begin
            write_kernel_0_0_run_flag <= 1; 
            write_kernel_0_0_count = 0;
        end
        if (write_one_kernel_0_0_data_done === 1) begin
            write_kernel_0_0_count = write_kernel_0_0_count + 1;
            if (write_kernel_0_0_count == kernel_0_0_OPERATE_DEPTH) begin
                write_kernel_0_0_run_flag <= 0; 
                kernel_0_0_write_data_finish <= 1;
            end
        end
    end
end

initial begin : write_kernel_0_0
    integer write_kernel_0_0_resp;
    integer process_num ;
    integer get_ack;
    integer four_byte_num;
    integer c_bitwidth;
    integer i;
    integer j;
    reg [31 : 0] kernel_0_0_data_tmp_reg;
    wait(reset === 1);
    @(posedge clk);
    c_bitwidth = kernel_0_0_c_bitwidth;
    process_num = 4;
    count_c_data_four_byte_num_by_bitwidth (c_bitwidth , four_byte_num) ;
    while (1) begin
        process_4_finish <= 0;

        if (ongoing_process_number === process_num && process_busy === 0 ) begin
            get_ack = 1;
            if (write_kernel_0_0_run_flag === 1 && get_ack === 1) begin
                process_busy = 1;
                //write kernel_0_0 data 
                for (i = 0 ; i < four_byte_num ; i = i+1) begin
                    if (kernel_0_0_c_bitwidth < 32) begin
                        kernel_0_0_data_tmp_reg = mem_kernel_0_0[write_kernel_0_0_count];
                    end
                    else begin
                        for (j=0 ; j<32 ; j = j + 1) begin
                            if (i*32 + j < kernel_0_0_c_bitwidth) begin
                                kernel_0_0_data_tmp_reg[j] = mem_kernel_0_0[write_kernel_0_0_count][i*32 + j];
                            end
                            else begin
                                kernel_0_0_data_tmp_reg[j] = 0;
                            end
                        end
                    end
                    write (kernel_0_0_data_in_addr + write_kernel_0_0_count * four_byte_num * 4 + i * 4, kernel_0_0_data_tmp_reg, write_kernel_0_0_resp);
                end
                process_busy = 0;
                write_one_kernel_0_0_data_done <= 1;
                @(posedge clk);
                write_one_kernel_0_0_data_done <= 0;
            end   
            process_4_finish <= 1;
        end
        @(posedge clk);
    end    
end
always @(reset or posedge clk) begin
    if (reset == 0) begin
        kernel_0_1_write_data_finish <= 0;
        write_kernel_0_1_run_flag <= 0; 
        write_kernel_0_1_count = 0;
        count_operate_depth_by_bitwidth_and_depth (kernel_0_1_c_bitwidth, kernel_0_1_DEPTH, kernel_0_1_OPERATE_DEPTH);
    end
    else begin
        if (TRAN_conv_io_start_in === 1) begin
            kernel_0_1_write_data_finish <= 0;
        end
        if (AESL_ready_reg === 1) begin
            write_kernel_0_1_run_flag <= 1; 
            write_kernel_0_1_count = 0;
        end
        if (write_one_kernel_0_1_data_done === 1) begin
            write_kernel_0_1_count = write_kernel_0_1_count + 1;
            if (write_kernel_0_1_count == kernel_0_1_OPERATE_DEPTH) begin
                write_kernel_0_1_run_flag <= 0; 
                kernel_0_1_write_data_finish <= 1;
            end
        end
    end
end

initial begin : write_kernel_0_1
    integer write_kernel_0_1_resp;
    integer process_num ;
    integer get_ack;
    integer four_byte_num;
    integer c_bitwidth;
    integer i;
    integer j;
    reg [31 : 0] kernel_0_1_data_tmp_reg;
    wait(reset === 1);
    @(posedge clk);
    c_bitwidth = kernel_0_1_c_bitwidth;
    process_num = 5;
    count_c_data_four_byte_num_by_bitwidth (c_bitwidth , four_byte_num) ;
    while (1) begin
        process_5_finish <= 0;

        if (ongoing_process_number === process_num && process_busy === 0 ) begin
            get_ack = 1;
            if (write_kernel_0_1_run_flag === 1 && get_ack === 1) begin
                process_busy = 1;
                //write kernel_0_1 data 
                for (i = 0 ; i < four_byte_num ; i = i+1) begin
                    if (kernel_0_1_c_bitwidth < 32) begin
                        kernel_0_1_data_tmp_reg = mem_kernel_0_1[write_kernel_0_1_count];
                    end
                    else begin
                        for (j=0 ; j<32 ; j = j + 1) begin
                            if (i*32 + j < kernel_0_1_c_bitwidth) begin
                                kernel_0_1_data_tmp_reg[j] = mem_kernel_0_1[write_kernel_0_1_count][i*32 + j];
                            end
                            else begin
                                kernel_0_1_data_tmp_reg[j] = 0;
                            end
                        end
                    end
                    write (kernel_0_1_data_in_addr + write_kernel_0_1_count * four_byte_num * 4 + i * 4, kernel_0_1_data_tmp_reg, write_kernel_0_1_resp);
                end
                process_busy = 0;
                write_one_kernel_0_1_data_done <= 1;
                @(posedge clk);
                write_one_kernel_0_1_data_done <= 0;
            end   
            process_5_finish <= 1;
        end
        @(posedge clk);
    end    
end
always @(reset or posedge clk) begin
    if (reset == 0) begin
        kernel_0_2_write_data_finish <= 0;
        write_kernel_0_2_run_flag <= 0; 
        write_kernel_0_2_count = 0;
        count_operate_depth_by_bitwidth_and_depth (kernel_0_2_c_bitwidth, kernel_0_2_DEPTH, kernel_0_2_OPERATE_DEPTH);
    end
    else begin
        if (TRAN_conv_io_start_in === 1) begin
            kernel_0_2_write_data_finish <= 0;
        end
        if (AESL_ready_reg === 1) begin
            write_kernel_0_2_run_flag <= 1; 
            write_kernel_0_2_count = 0;
        end
        if (write_one_kernel_0_2_data_done === 1) begin
            write_kernel_0_2_count = write_kernel_0_2_count + 1;
            if (write_kernel_0_2_count == kernel_0_2_OPERATE_DEPTH) begin
                write_kernel_0_2_run_flag <= 0; 
                kernel_0_2_write_data_finish <= 1;
            end
        end
    end
end

initial begin : write_kernel_0_2
    integer write_kernel_0_2_resp;
    integer process_num ;
    integer get_ack;
    integer four_byte_num;
    integer c_bitwidth;
    integer i;
    integer j;
    reg [31 : 0] kernel_0_2_data_tmp_reg;
    wait(reset === 1);
    @(posedge clk);
    c_bitwidth = kernel_0_2_c_bitwidth;
    process_num = 6;
    count_c_data_four_byte_num_by_bitwidth (c_bitwidth , four_byte_num) ;
    while (1) begin
        process_6_finish <= 0;

        if (ongoing_process_number === process_num && process_busy === 0 ) begin
            get_ack = 1;
            if (write_kernel_0_2_run_flag === 1 && get_ack === 1) begin
                process_busy = 1;
                //write kernel_0_2 data 
                for (i = 0 ; i < four_byte_num ; i = i+1) begin
                    if (kernel_0_2_c_bitwidth < 32) begin
                        kernel_0_2_data_tmp_reg = mem_kernel_0_2[write_kernel_0_2_count];
                    end
                    else begin
                        for (j=0 ; j<32 ; j = j + 1) begin
                            if (i*32 + j < kernel_0_2_c_bitwidth) begin
                                kernel_0_2_data_tmp_reg[j] = mem_kernel_0_2[write_kernel_0_2_count][i*32 + j];
                            end
                            else begin
                                kernel_0_2_data_tmp_reg[j] = 0;
                            end
                        end
                    end
                    write (kernel_0_2_data_in_addr + write_kernel_0_2_count * four_byte_num * 4 + i * 4, kernel_0_2_data_tmp_reg, write_kernel_0_2_resp);
                end
                process_busy = 0;
                write_one_kernel_0_2_data_done <= 1;
                @(posedge clk);
                write_one_kernel_0_2_data_done <= 0;
            end   
            process_6_finish <= 1;
        end
        @(posedge clk);
    end    
end
always @(reset or posedge clk) begin
    if (reset == 0) begin
        kernel_1_0_write_data_finish <= 0;
        write_kernel_1_0_run_flag <= 0; 
        write_kernel_1_0_count = 0;
        count_operate_depth_by_bitwidth_and_depth (kernel_1_0_c_bitwidth, kernel_1_0_DEPTH, kernel_1_0_OPERATE_DEPTH);
    end
    else begin
        if (TRAN_conv_io_start_in === 1) begin
            kernel_1_0_write_data_finish <= 0;
        end
        if (AESL_ready_reg === 1) begin
            write_kernel_1_0_run_flag <= 1; 
            write_kernel_1_0_count = 0;
        end
        if (write_one_kernel_1_0_data_done === 1) begin
            write_kernel_1_0_count = write_kernel_1_0_count + 1;
            if (write_kernel_1_0_count == kernel_1_0_OPERATE_DEPTH) begin
                write_kernel_1_0_run_flag <= 0; 
                kernel_1_0_write_data_finish <= 1;
            end
        end
    end
end

initial begin : write_kernel_1_0
    integer write_kernel_1_0_resp;
    integer process_num ;
    integer get_ack;
    integer four_byte_num;
    integer c_bitwidth;
    integer i;
    integer j;
    reg [31 : 0] kernel_1_0_data_tmp_reg;
    wait(reset === 1);
    @(posedge clk);
    c_bitwidth = kernel_1_0_c_bitwidth;
    process_num = 7;
    count_c_data_four_byte_num_by_bitwidth (c_bitwidth , four_byte_num) ;
    while (1) begin
        process_7_finish <= 0;

        if (ongoing_process_number === process_num && process_busy === 0 ) begin
            get_ack = 1;
            if (write_kernel_1_0_run_flag === 1 && get_ack === 1) begin
                process_busy = 1;
                //write kernel_1_0 data 
                for (i = 0 ; i < four_byte_num ; i = i+1) begin
                    if (kernel_1_0_c_bitwidth < 32) begin
                        kernel_1_0_data_tmp_reg = mem_kernel_1_0[write_kernel_1_0_count];
                    end
                    else begin
                        for (j=0 ; j<32 ; j = j + 1) begin
                            if (i*32 + j < kernel_1_0_c_bitwidth) begin
                                kernel_1_0_data_tmp_reg[j] = mem_kernel_1_0[write_kernel_1_0_count][i*32 + j];
                            end
                            else begin
                                kernel_1_0_data_tmp_reg[j] = 0;
                            end
                        end
                    end
                    write (kernel_1_0_data_in_addr + write_kernel_1_0_count * four_byte_num * 4 + i * 4, kernel_1_0_data_tmp_reg, write_kernel_1_0_resp);
                end
                process_busy = 0;
                write_one_kernel_1_0_data_done <= 1;
                @(posedge clk);
                write_one_kernel_1_0_data_done <= 0;
            end   
            process_7_finish <= 1;
        end
        @(posedge clk);
    end    
end
always @(reset or posedge clk) begin
    if (reset == 0) begin
        kernel_1_1_write_data_finish <= 0;
        write_kernel_1_1_run_flag <= 0; 
        write_kernel_1_1_count = 0;
        count_operate_depth_by_bitwidth_and_depth (kernel_1_1_c_bitwidth, kernel_1_1_DEPTH, kernel_1_1_OPERATE_DEPTH);
    end
    else begin
        if (TRAN_conv_io_start_in === 1) begin
            kernel_1_1_write_data_finish <= 0;
        end
        if (AESL_ready_reg === 1) begin
            write_kernel_1_1_run_flag <= 1; 
            write_kernel_1_1_count = 0;
        end
        if (write_one_kernel_1_1_data_done === 1) begin
            write_kernel_1_1_count = write_kernel_1_1_count + 1;
            if (write_kernel_1_1_count == kernel_1_1_OPERATE_DEPTH) begin
                write_kernel_1_1_run_flag <= 0; 
                kernel_1_1_write_data_finish <= 1;
            end
        end
    end
end

initial begin : write_kernel_1_1
    integer write_kernel_1_1_resp;
    integer process_num ;
    integer get_ack;
    integer four_byte_num;
    integer c_bitwidth;
    integer i;
    integer j;
    reg [31 : 0] kernel_1_1_data_tmp_reg;
    wait(reset === 1);
    @(posedge clk);
    c_bitwidth = kernel_1_1_c_bitwidth;
    process_num = 8;
    count_c_data_four_byte_num_by_bitwidth (c_bitwidth , four_byte_num) ;
    while (1) begin
        process_8_finish <= 0;

        if (ongoing_process_number === process_num && process_busy === 0 ) begin
            get_ack = 1;
            if (write_kernel_1_1_run_flag === 1 && get_ack === 1) begin
                process_busy = 1;
                //write kernel_1_1 data 
                for (i = 0 ; i < four_byte_num ; i = i+1) begin
                    if (kernel_1_1_c_bitwidth < 32) begin
                        kernel_1_1_data_tmp_reg = mem_kernel_1_1[write_kernel_1_1_count];
                    end
                    else begin
                        for (j=0 ; j<32 ; j = j + 1) begin
                            if (i*32 + j < kernel_1_1_c_bitwidth) begin
                                kernel_1_1_data_tmp_reg[j] = mem_kernel_1_1[write_kernel_1_1_count][i*32 + j];
                            end
                            else begin
                                kernel_1_1_data_tmp_reg[j] = 0;
                            end
                        end
                    end
                    write (kernel_1_1_data_in_addr + write_kernel_1_1_count * four_byte_num * 4 + i * 4, kernel_1_1_data_tmp_reg, write_kernel_1_1_resp);
                end
                process_busy = 0;
                write_one_kernel_1_1_data_done <= 1;
                @(posedge clk);
                write_one_kernel_1_1_data_done <= 0;
            end   
            process_8_finish <= 1;
        end
        @(posedge clk);
    end    
end
always @(reset or posedge clk) begin
    if (reset == 0) begin
        kernel_1_2_write_data_finish <= 0;
        write_kernel_1_2_run_flag <= 0; 
        write_kernel_1_2_count = 0;
        count_operate_depth_by_bitwidth_and_depth (kernel_1_2_c_bitwidth, kernel_1_2_DEPTH, kernel_1_2_OPERATE_DEPTH);
    end
    else begin
        if (TRAN_conv_io_start_in === 1) begin
            kernel_1_2_write_data_finish <= 0;
        end
        if (AESL_ready_reg === 1) begin
            write_kernel_1_2_run_flag <= 1; 
            write_kernel_1_2_count = 0;
        end
        if (write_one_kernel_1_2_data_done === 1) begin
            write_kernel_1_2_count = write_kernel_1_2_count + 1;
            if (write_kernel_1_2_count == kernel_1_2_OPERATE_DEPTH) begin
                write_kernel_1_2_run_flag <= 0; 
                kernel_1_2_write_data_finish <= 1;
            end
        end
    end
end

initial begin : write_kernel_1_2
    integer write_kernel_1_2_resp;
    integer process_num ;
    integer get_ack;
    integer four_byte_num;
    integer c_bitwidth;
    integer i;
    integer j;
    reg [31 : 0] kernel_1_2_data_tmp_reg;
    wait(reset === 1);
    @(posedge clk);
    c_bitwidth = kernel_1_2_c_bitwidth;
    process_num = 9;
    count_c_data_four_byte_num_by_bitwidth (c_bitwidth , four_byte_num) ;
    while (1) begin
        process_9_finish <= 0;

        if (ongoing_process_number === process_num && process_busy === 0 ) begin
            get_ack = 1;
            if (write_kernel_1_2_run_flag === 1 && get_ack === 1) begin
                process_busy = 1;
                //write kernel_1_2 data 
                for (i = 0 ; i < four_byte_num ; i = i+1) begin
                    if (kernel_1_2_c_bitwidth < 32) begin
                        kernel_1_2_data_tmp_reg = mem_kernel_1_2[write_kernel_1_2_count];
                    end
                    else begin
                        for (j=0 ; j<32 ; j = j + 1) begin
                            if (i*32 + j < kernel_1_2_c_bitwidth) begin
                                kernel_1_2_data_tmp_reg[j] = mem_kernel_1_2[write_kernel_1_2_count][i*32 + j];
                            end
                            else begin
                                kernel_1_2_data_tmp_reg[j] = 0;
                            end
                        end
                    end
                    write (kernel_1_2_data_in_addr + write_kernel_1_2_count * four_byte_num * 4 + i * 4, kernel_1_2_data_tmp_reg, write_kernel_1_2_resp);
                end
                process_busy = 0;
                write_one_kernel_1_2_data_done <= 1;
                @(posedge clk);
                write_one_kernel_1_2_data_done <= 0;
            end   
            process_9_finish <= 1;
        end
        @(posedge clk);
    end    
end
always @(reset or posedge clk) begin
    if (reset == 0) begin
        kernel_2_0_write_data_finish <= 0;
        write_kernel_2_0_run_flag <= 0; 
        write_kernel_2_0_count = 0;
        count_operate_depth_by_bitwidth_and_depth (kernel_2_0_c_bitwidth, kernel_2_0_DEPTH, kernel_2_0_OPERATE_DEPTH);
    end
    else begin
        if (TRAN_conv_io_start_in === 1) begin
            kernel_2_0_write_data_finish <= 0;
        end
        if (AESL_ready_reg === 1) begin
            write_kernel_2_0_run_flag <= 1; 
            write_kernel_2_0_count = 0;
        end
        if (write_one_kernel_2_0_data_done === 1) begin
            write_kernel_2_0_count = write_kernel_2_0_count + 1;
            if (write_kernel_2_0_count == kernel_2_0_OPERATE_DEPTH) begin
                write_kernel_2_0_run_flag <= 0; 
                kernel_2_0_write_data_finish <= 1;
            end
        end
    end
end

initial begin : write_kernel_2_0
    integer write_kernel_2_0_resp;
    integer process_num ;
    integer get_ack;
    integer four_byte_num;
    integer c_bitwidth;
    integer i;
    integer j;
    reg [31 : 0] kernel_2_0_data_tmp_reg;
    wait(reset === 1);
    @(posedge clk);
    c_bitwidth = kernel_2_0_c_bitwidth;
    process_num = 10;
    count_c_data_four_byte_num_by_bitwidth (c_bitwidth , four_byte_num) ;
    while (1) begin
        process_10_finish <= 0;

        if (ongoing_process_number === process_num && process_busy === 0 ) begin
            get_ack = 1;
            if (write_kernel_2_0_run_flag === 1 && get_ack === 1) begin
                process_busy = 1;
                //write kernel_2_0 data 
                for (i = 0 ; i < four_byte_num ; i = i+1) begin
                    if (kernel_2_0_c_bitwidth < 32) begin
                        kernel_2_0_data_tmp_reg = mem_kernel_2_0[write_kernel_2_0_count];
                    end
                    else begin
                        for (j=0 ; j<32 ; j = j + 1) begin
                            if (i*32 + j < kernel_2_0_c_bitwidth) begin
                                kernel_2_0_data_tmp_reg[j] = mem_kernel_2_0[write_kernel_2_0_count][i*32 + j];
                            end
                            else begin
                                kernel_2_0_data_tmp_reg[j] = 0;
                            end
                        end
                    end
                    write (kernel_2_0_data_in_addr + write_kernel_2_0_count * four_byte_num * 4 + i * 4, kernel_2_0_data_tmp_reg, write_kernel_2_0_resp);
                end
                process_busy = 0;
                write_one_kernel_2_0_data_done <= 1;
                @(posedge clk);
                write_one_kernel_2_0_data_done <= 0;
            end   
            process_10_finish <= 1;
        end
        @(posedge clk);
    end    
end
always @(reset or posedge clk) begin
    if (reset == 0) begin
        kernel_2_1_write_data_finish <= 0;
        write_kernel_2_1_run_flag <= 0; 
        write_kernel_2_1_count = 0;
        count_operate_depth_by_bitwidth_and_depth (kernel_2_1_c_bitwidth, kernel_2_1_DEPTH, kernel_2_1_OPERATE_DEPTH);
    end
    else begin
        if (TRAN_conv_io_start_in === 1) begin
            kernel_2_1_write_data_finish <= 0;
        end
        if (AESL_ready_reg === 1) begin
            write_kernel_2_1_run_flag <= 1; 
            write_kernel_2_1_count = 0;
        end
        if (write_one_kernel_2_1_data_done === 1) begin
            write_kernel_2_1_count = write_kernel_2_1_count + 1;
            if (write_kernel_2_1_count == kernel_2_1_OPERATE_DEPTH) begin
                write_kernel_2_1_run_flag <= 0; 
                kernel_2_1_write_data_finish <= 1;
            end
        end
    end
end

initial begin : write_kernel_2_1
    integer write_kernel_2_1_resp;
    integer process_num ;
    integer get_ack;
    integer four_byte_num;
    integer c_bitwidth;
    integer i;
    integer j;
    reg [31 : 0] kernel_2_1_data_tmp_reg;
    wait(reset === 1);
    @(posedge clk);
    c_bitwidth = kernel_2_1_c_bitwidth;
    process_num = 11;
    count_c_data_four_byte_num_by_bitwidth (c_bitwidth , four_byte_num) ;
    while (1) begin
        process_11_finish <= 0;

        if (ongoing_process_number === process_num && process_busy === 0 ) begin
            get_ack = 1;
            if (write_kernel_2_1_run_flag === 1 && get_ack === 1) begin
                process_busy = 1;
                //write kernel_2_1 data 
                for (i = 0 ; i < four_byte_num ; i = i+1) begin
                    if (kernel_2_1_c_bitwidth < 32) begin
                        kernel_2_1_data_tmp_reg = mem_kernel_2_1[write_kernel_2_1_count];
                    end
                    else begin
                        for (j=0 ; j<32 ; j = j + 1) begin
                            if (i*32 + j < kernel_2_1_c_bitwidth) begin
                                kernel_2_1_data_tmp_reg[j] = mem_kernel_2_1[write_kernel_2_1_count][i*32 + j];
                            end
                            else begin
                                kernel_2_1_data_tmp_reg[j] = 0;
                            end
                        end
                    end
                    write (kernel_2_1_data_in_addr + write_kernel_2_1_count * four_byte_num * 4 + i * 4, kernel_2_1_data_tmp_reg, write_kernel_2_1_resp);
                end
                process_busy = 0;
                write_one_kernel_2_1_data_done <= 1;
                @(posedge clk);
                write_one_kernel_2_1_data_done <= 0;
            end   
            process_11_finish <= 1;
        end
        @(posedge clk);
    end    
end
always @(reset or posedge clk) begin
    if (reset == 0) begin
        kernel_2_2_write_data_finish <= 0;
        write_kernel_2_2_run_flag <= 0; 
        write_kernel_2_2_count = 0;
        count_operate_depth_by_bitwidth_and_depth (kernel_2_2_c_bitwidth, kernel_2_2_DEPTH, kernel_2_2_OPERATE_DEPTH);
    end
    else begin
        if (TRAN_conv_io_start_in === 1) begin
            kernel_2_2_write_data_finish <= 0;
        end
        if (AESL_ready_reg === 1) begin
            write_kernel_2_2_run_flag <= 1; 
            write_kernel_2_2_count = 0;
        end
        if (write_one_kernel_2_2_data_done === 1) begin
            write_kernel_2_2_count = write_kernel_2_2_count + 1;
            if (write_kernel_2_2_count == kernel_2_2_OPERATE_DEPTH) begin
                write_kernel_2_2_run_flag <= 0; 
                kernel_2_2_write_data_finish <= 1;
            end
        end
    end
end

initial begin : write_kernel_2_2
    integer write_kernel_2_2_resp;
    integer process_num ;
    integer get_ack;
    integer four_byte_num;
    integer c_bitwidth;
    integer i;
    integer j;
    reg [31 : 0] kernel_2_2_data_tmp_reg;
    wait(reset === 1);
    @(posedge clk);
    c_bitwidth = kernel_2_2_c_bitwidth;
    process_num = 12;
    count_c_data_four_byte_num_by_bitwidth (c_bitwidth , four_byte_num) ;
    while (1) begin
        process_12_finish <= 0;

        if (ongoing_process_number === process_num && process_busy === 0 ) begin
            get_ack = 1;
            if (write_kernel_2_2_run_flag === 1 && get_ack === 1) begin
                process_busy = 1;
                //write kernel_2_2 data 
                for (i = 0 ; i < four_byte_num ; i = i+1) begin
                    if (kernel_2_2_c_bitwidth < 32) begin
                        kernel_2_2_data_tmp_reg = mem_kernel_2_2[write_kernel_2_2_count];
                    end
                    else begin
                        for (j=0 ; j<32 ; j = j + 1) begin
                            if (i*32 + j < kernel_2_2_c_bitwidth) begin
                                kernel_2_2_data_tmp_reg[j] = mem_kernel_2_2[write_kernel_2_2_count][i*32 + j];
                            end
                            else begin
                                kernel_2_2_data_tmp_reg[j] = 0;
                            end
                        end
                    end
                    write (kernel_2_2_data_in_addr + write_kernel_2_2_count * four_byte_num * 4 + i * 4, kernel_2_2_data_tmp_reg, write_kernel_2_2_resp);
                end
                process_busy = 0;
                write_one_kernel_2_2_data_done <= 1;
                @(posedge clk);
                write_one_kernel_2_2_data_done <= 0;
            end   
            process_12_finish <= 1;
        end
        @(posedge clk);
    end    
end

always @(reset or posedge clk) begin
    if (reset == 0) begin
        write_start_run_flag <= 0; 
        write_start_count <= 0;
    end
    else begin
        if (write_start_count >= 5) begin
            write_start_run_flag <= 0; 
        end
        else if (TRAN_conv_io_write_start_in === 1) begin
            write_start_run_flag <= 1; 
        end
        if (AESL_write_start_finish === 1) begin
            write_start_count <= write_start_count + 1;
            write_start_run_flag <= 0; 
        end
    end
end

initial begin : write_start
    reg [DATA_WIDTH - 1 : 0] write_start_tmp;
    integer process_num;
    integer write_start_resp;
    wait(reset === 1);
    @(posedge clk);
    process_num = 13;
    while (1) begin
        process_13_finish = 0;
        if (ongoing_process_number === process_num && process_busy === 0 ) begin
            if (write_start_run_flag === 1) begin
                process_busy = 1;
                write_start_tmp=0;
                write_start_tmp[0 : 0] = 1;
                write (START_ADDR, write_start_tmp, write_start_resp);
                process_busy = 0;
                AESL_write_start_finish <= 1;
                @(posedge clk);
                AESL_write_start_finish <= 0;
            end
            process_13_finish <= 1;
        end 
        @(posedge clk);
    end
end

always @(reset or posedge clk) begin
    if (reset == 0) begin
        output_r_read_data_finish <= 0;
        read_output_r_run_flag <= 0; 
        read_output_r_count = 0;
        count_operate_depth_by_bitwidth_and_depth (output_r_c_bitwidth, output_r_DEPTH, output_r_OPERATE_DEPTH);
    end
    else begin
        if (AESL_done_index_reg === 1) begin
            read_output_r_run_flag = 1; 
        end
        if (TRAN_conv_io_transaction_done_in === 1) begin
            output_r_read_data_finish <= 0;
            read_output_r_count = 0; 
        end
        if (read_one_output_r_data_done === 1) begin
            read_output_r_count = read_output_r_count + 1;
            if (read_output_r_count == output_r_OPERATE_DEPTH) begin
                read_output_r_run_flag <= 0; 
                output_r_read_data_finish <= 1;
            end
        end
    end
end

initial begin : read_output_r
    integer read_output_r_resp;
    integer process_num;
    integer get_vld;
    integer four_byte_num;
    integer c_bitwidth;
    integer i;
    integer j;

    wait(reset === 1);
    @(posedge clk);
    c_bitwidth = output_r_c_bitwidth;
    process_num = 14;
    count_c_data_four_byte_num_by_bitwidth (c_bitwidth , four_byte_num) ;
    while (1) begin
        process_14_finish <= 0;
        if (ongoing_process_number === process_num && process_busy === 0 ) begin
            if (read_output_r_run_flag === 1) begin
                process_busy = 1;
                get_vld = 1;
                if (get_vld == 1) begin
                    //read output_r data 
                    for (i = 0 ; i < four_byte_num ; i = i+1) begin
                        read (output_r_data_out_addr + read_output_r_count * four_byte_num * 4 + i * 4, RDATA_reg, read_output_r_resp);
                        if (output_r_c_bitwidth < 32) begin
                            mem_output_r[read_output_r_count] <= RDATA_reg;
                        end
                        else begin
                            for (j=0 ; j < 32 ; j = j + 1) begin
                                if (i*32 + j < output_r_c_bitwidth) begin
                                    mem_output_r[read_output_r_count][i*32 + j] <= RDATA_reg[j];
                                end
                            end
                        end
                    end
                    
                    read_one_output_r_data_done <= 1;
                    @(posedge clk);
                    read_one_output_r_data_done <= 0;
                end    
                process_busy = 0;
            end    
            process_14_finish <= 1;
        end
        @(posedge clk);
    end    
end
//------------------------Task and function-------------- 
task read_token; 
    input integer fp; 
    output reg [127 : 0] token;
    integer ret;
    begin
        token = "";
        ret = 0;
        ret = $fscanf(fp,"%s",token);
    end 
endtask 
 
//------------------------Read file------------------------ 
 
// Read data from file 
initial begin : read_input_0_file_process 
  integer fp; 
  integer ret; 
  integer factor; 
  reg [127 : 0] token; 
  reg [127 : 0] token_tmp; 
  //reg [input_0_c_bitwidth - 1 : 0] token_tmp; 
  reg [DATA_WIDTH - 1 : 0] mem_tmp; 
  reg [ 8*5 : 1] str;
  integer transaction_idx; 
  integer i; 
  transaction_idx = 0; 
  mem_tmp [DATA_WIDTH - 1 : 0] = 0;
  count_seperate_factor_by_bitwidth (input_0_c_bitwidth , factor);
  fp = $fopen(`TV_IN_input_0 ,"r"); 
  if(fp == 0) begin                               // Failed to open file 
      $display("Failed to open file \"%s\"!", `TV_IN_input_0); 
      $finish; 
  end 
  read_token(fp, token); 
  if (token != "[[[runtime]]]") begin             // Illegal format 
      $display("ERROR: Simulation using HLS TB failed.");
      $finish; 
  end 
  read_token(fp, token); 
  while (token != "[[[/runtime]]]") begin 
      if (token != "[[transaction]]") begin 
          $display("ERROR: Simulation using HLS TB failed.");
          $finish; 
      end 
      read_token(fp, token);                        // skip transaction number 
      @(posedge clk);
      # 0.2;
      while(AESL_ready_reg !== 1) begin
          @(posedge clk); 
          # 0.2;
      end
      for(i = 0; i < input_0_DEPTH; i = i + 1) begin 
          read_token(fp, token); 
          ret = $sscanf(token, "0x%x", token_tmp); 
          if (factor == 4) begin
              if (i%factor == 0) begin
                  mem_tmp [7 : 0] = token_tmp;
              end
              if (i%factor == 1) begin
                  mem_tmp [15 : 8] = token_tmp;
              end
              if (i%factor == 2) begin
                  mem_tmp [23 : 16] = token_tmp;
              end
              if (i%factor == 3) begin
                  mem_tmp [31 : 24] = token_tmp;
                  mem_input_0 [i/factor] = mem_tmp;
                  mem_tmp [DATA_WIDTH - 1 : 0] = 0;
              end
          end
          if (factor == 2) begin
              if (i%factor == 0) begin
                  mem_tmp [15 : 0] = token_tmp;
              end
              if (i%factor == 1) begin
                  mem_tmp [31 : 16] = token_tmp;
                  mem_input_0 [i/factor] = mem_tmp;
                  mem_tmp [DATA_WIDTH - 1: 0] = 0;
              end
          end
          if (factor == 1) begin
              mem_input_0 [i] = token_tmp;
          end
      end 
      if (factor == 4) begin
          if (i%factor != 0) begin
              mem_input_0 [i/factor] = mem_tmp;
          end
      end
      if (factor == 2) begin
          if (i%factor != 0) begin
              mem_input_0 [i/factor] = mem_tmp;
          end
      end 
      read_token(fp, token); 
      if(token != "[[/transaction]]") begin 
          $display("ERROR: Simulation using HLS TB failed.");
          $finish; 
      end 
      read_token(fp, token); 
      transaction_idx = transaction_idx + 1; 
  end 
  $fclose(fp); 
end 
 
//------------------------Read file------------------------ 
 
// Read data from file 
initial begin : read_input_1_file_process 
  integer fp; 
  integer ret; 
  integer factor; 
  reg [127 : 0] token; 
  reg [127 : 0] token_tmp; 
  //reg [input_1_c_bitwidth - 1 : 0] token_tmp; 
  reg [DATA_WIDTH - 1 : 0] mem_tmp; 
  reg [ 8*5 : 1] str;
  integer transaction_idx; 
  integer i; 
  transaction_idx = 0; 
  mem_tmp [DATA_WIDTH - 1 : 0] = 0;
  count_seperate_factor_by_bitwidth (input_1_c_bitwidth , factor);
  fp = $fopen(`TV_IN_input_1 ,"r"); 
  if(fp == 0) begin                               // Failed to open file 
      $display("Failed to open file \"%s\"!", `TV_IN_input_1); 
      $finish; 
  end 
  read_token(fp, token); 
  if (token != "[[[runtime]]]") begin             // Illegal format 
      $display("ERROR: Simulation using HLS TB failed.");
      $finish; 
  end 
  read_token(fp, token); 
  while (token != "[[[/runtime]]]") begin 
      if (token != "[[transaction]]") begin 
          $display("ERROR: Simulation using HLS TB failed.");
          $finish; 
      end 
      read_token(fp, token);                        // skip transaction number 
      @(posedge clk);
      # 0.2;
      while(AESL_ready_reg !== 1) begin
          @(posedge clk); 
          # 0.2;
      end
      for(i = 0; i < input_1_DEPTH; i = i + 1) begin 
          read_token(fp, token); 
          ret = $sscanf(token, "0x%x", token_tmp); 
          if (factor == 4) begin
              if (i%factor == 0) begin
                  mem_tmp [7 : 0] = token_tmp;
              end
              if (i%factor == 1) begin
                  mem_tmp [15 : 8] = token_tmp;
              end
              if (i%factor == 2) begin
                  mem_tmp [23 : 16] = token_tmp;
              end
              if (i%factor == 3) begin
                  mem_tmp [31 : 24] = token_tmp;
                  mem_input_1 [i/factor] = mem_tmp;
                  mem_tmp [DATA_WIDTH - 1 : 0] = 0;
              end
          end
          if (factor == 2) begin
              if (i%factor == 0) begin
                  mem_tmp [15 : 0] = token_tmp;
              end
              if (i%factor == 1) begin
                  mem_tmp [31 : 16] = token_tmp;
                  mem_input_1 [i/factor] = mem_tmp;
                  mem_tmp [DATA_WIDTH - 1: 0] = 0;
              end
          end
          if (factor == 1) begin
              mem_input_1 [i] = token_tmp;
          end
      end 
      if (factor == 4) begin
          if (i%factor != 0) begin
              mem_input_1 [i/factor] = mem_tmp;
          end
      end
      if (factor == 2) begin
          if (i%factor != 0) begin
              mem_input_1 [i/factor] = mem_tmp;
          end
      end 
      read_token(fp, token); 
      if(token != "[[/transaction]]") begin 
          $display("ERROR: Simulation using HLS TB failed.");
          $finish; 
      end 
      read_token(fp, token); 
      transaction_idx = transaction_idx + 1; 
  end 
  $fclose(fp); 
end 
 
//------------------------Read file------------------------ 
 
// Read data from file 
initial begin : read_input_2_file_process 
  integer fp; 
  integer ret; 
  integer factor; 
  reg [127 : 0] token; 
  reg [127 : 0] token_tmp; 
  //reg [input_2_c_bitwidth - 1 : 0] token_tmp; 
  reg [DATA_WIDTH - 1 : 0] mem_tmp; 
  reg [ 8*5 : 1] str;
  integer transaction_idx; 
  integer i; 
  transaction_idx = 0; 
  mem_tmp [DATA_WIDTH - 1 : 0] = 0;
  count_seperate_factor_by_bitwidth (input_2_c_bitwidth , factor);
  fp = $fopen(`TV_IN_input_2 ,"r"); 
  if(fp == 0) begin                               // Failed to open file 
      $display("Failed to open file \"%s\"!", `TV_IN_input_2); 
      $finish; 
  end 
  read_token(fp, token); 
  if (token != "[[[runtime]]]") begin             // Illegal format 
      $display("ERROR: Simulation using HLS TB failed.");
      $finish; 
  end 
  read_token(fp, token); 
  while (token != "[[[/runtime]]]") begin 
      if (token != "[[transaction]]") begin 
          $display("ERROR: Simulation using HLS TB failed.");
          $finish; 
      end 
      read_token(fp, token);                        // skip transaction number 
      @(posedge clk);
      # 0.2;
      while(AESL_ready_reg !== 1) begin
          @(posedge clk); 
          # 0.2;
      end
      for(i = 0; i < input_2_DEPTH; i = i + 1) begin 
          read_token(fp, token); 
          ret = $sscanf(token, "0x%x", token_tmp); 
          if (factor == 4) begin
              if (i%factor == 0) begin
                  mem_tmp [7 : 0] = token_tmp;
              end
              if (i%factor == 1) begin
                  mem_tmp [15 : 8] = token_tmp;
              end
              if (i%factor == 2) begin
                  mem_tmp [23 : 16] = token_tmp;
              end
              if (i%factor == 3) begin
                  mem_tmp [31 : 24] = token_tmp;
                  mem_input_2 [i/factor] = mem_tmp;
                  mem_tmp [DATA_WIDTH - 1 : 0] = 0;
              end
          end
          if (factor == 2) begin
              if (i%factor == 0) begin
                  mem_tmp [15 : 0] = token_tmp;
              end
              if (i%factor == 1) begin
                  mem_tmp [31 : 16] = token_tmp;
                  mem_input_2 [i/factor] = mem_tmp;
                  mem_tmp [DATA_WIDTH - 1: 0] = 0;
              end
          end
          if (factor == 1) begin
              mem_input_2 [i] = token_tmp;
          end
      end 
      if (factor == 4) begin
          if (i%factor != 0) begin
              mem_input_2 [i/factor] = mem_tmp;
          end
      end
      if (factor == 2) begin
          if (i%factor != 0) begin
              mem_input_2 [i/factor] = mem_tmp;
          end
      end 
      read_token(fp, token); 
      if(token != "[[/transaction]]") begin 
          $display("ERROR: Simulation using HLS TB failed.");
          $finish; 
      end 
      read_token(fp, token); 
      transaction_idx = transaction_idx + 1; 
  end 
  $fclose(fp); 
end 
 
//------------------------Read file------------------------ 
 
// Read data from file 
initial begin : read_kernel_0_0_file_process 
  integer fp; 
  integer ret; 
  integer factor; 
  reg [127 : 0] token; 
  reg [127 : 0] token_tmp; 
  //reg [kernel_0_0_c_bitwidth - 1 : 0] token_tmp; 
  reg [DATA_WIDTH - 1 : 0] mem_tmp; 
  reg [ 8*5 : 1] str;
  integer transaction_idx; 
  integer i; 
  transaction_idx = 0; 
  mem_tmp [DATA_WIDTH - 1 : 0] = 0;
  count_seperate_factor_by_bitwidth (kernel_0_0_c_bitwidth , factor);
  fp = $fopen(`TV_IN_kernel_0_0 ,"r"); 
  if(fp == 0) begin                               // Failed to open file 
      $display("Failed to open file \"%s\"!", `TV_IN_kernel_0_0); 
      $finish; 
  end 
  read_token(fp, token); 
  if (token != "[[[runtime]]]") begin             // Illegal format 
      $display("ERROR: Simulation using HLS TB failed.");
      $finish; 
  end 
  read_token(fp, token); 
  while (token != "[[[/runtime]]]") begin 
      if (token != "[[transaction]]") begin 
          $display("ERROR: Simulation using HLS TB failed.");
          $finish; 
      end 
      read_token(fp, token);                        // skip transaction number 
      @(posedge clk);
      # 0.2;
      while(AESL_ready_reg !== 1) begin
          @(posedge clk); 
          # 0.2;
      end
      for(i = 0; i < kernel_0_0_DEPTH; i = i + 1) begin 
          read_token(fp, token); 
          ret = $sscanf(token, "0x%x", token_tmp); 
          if (factor == 4) begin
              if (i%factor == 0) begin
                  mem_tmp [7 : 0] = token_tmp;
              end
              if (i%factor == 1) begin
                  mem_tmp [15 : 8] = token_tmp;
              end
              if (i%factor == 2) begin
                  mem_tmp [23 : 16] = token_tmp;
              end
              if (i%factor == 3) begin
                  mem_tmp [31 : 24] = token_tmp;
                  mem_kernel_0_0 [i/factor] = mem_tmp;
                  mem_tmp [DATA_WIDTH - 1 : 0] = 0;
              end
          end
          if (factor == 2) begin
              if (i%factor == 0) begin
                  mem_tmp [15 : 0] = token_tmp;
              end
              if (i%factor == 1) begin
                  mem_tmp [31 : 16] = token_tmp;
                  mem_kernel_0_0 [i/factor] = mem_tmp;
                  mem_tmp [DATA_WIDTH - 1: 0] = 0;
              end
          end
          if (factor == 1) begin
              mem_kernel_0_0 [i] = token_tmp;
          end
      end 
      if (factor == 4) begin
          if (i%factor != 0) begin
              mem_kernel_0_0 [i/factor] = mem_tmp;
          end
      end
      if (factor == 2) begin
          if (i%factor != 0) begin
              mem_kernel_0_0 [i/factor] = mem_tmp;
          end
      end 
      read_token(fp, token); 
      if(token != "[[/transaction]]") begin 
          $display("ERROR: Simulation using HLS TB failed.");
          $finish; 
      end 
      read_token(fp, token); 
      transaction_idx = transaction_idx + 1; 
  end 
  $fclose(fp); 
end 
 
//------------------------Read file------------------------ 
 
// Read data from file 
initial begin : read_kernel_0_1_file_process 
  integer fp; 
  integer ret; 
  integer factor; 
  reg [127 : 0] token; 
  reg [127 : 0] token_tmp; 
  //reg [kernel_0_1_c_bitwidth - 1 : 0] token_tmp; 
  reg [DATA_WIDTH - 1 : 0] mem_tmp; 
  reg [ 8*5 : 1] str;
  integer transaction_idx; 
  integer i; 
  transaction_idx = 0; 
  mem_tmp [DATA_WIDTH - 1 : 0] = 0;
  count_seperate_factor_by_bitwidth (kernel_0_1_c_bitwidth , factor);
  fp = $fopen(`TV_IN_kernel_0_1 ,"r"); 
  if(fp == 0) begin                               // Failed to open file 
      $display("Failed to open file \"%s\"!", `TV_IN_kernel_0_1); 
      $finish; 
  end 
  read_token(fp, token); 
  if (token != "[[[runtime]]]") begin             // Illegal format 
      $display("ERROR: Simulation using HLS TB failed.");
      $finish; 
  end 
  read_token(fp, token); 
  while (token != "[[[/runtime]]]") begin 
      if (token != "[[transaction]]") begin 
          $display("ERROR: Simulation using HLS TB failed.");
          $finish; 
      end 
      read_token(fp, token);                        // skip transaction number 
      @(posedge clk);
      # 0.2;
      while(AESL_ready_reg !== 1) begin
          @(posedge clk); 
          # 0.2;
      end
      for(i = 0; i < kernel_0_1_DEPTH; i = i + 1) begin 
          read_token(fp, token); 
          ret = $sscanf(token, "0x%x", token_tmp); 
          if (factor == 4) begin
              if (i%factor == 0) begin
                  mem_tmp [7 : 0] = token_tmp;
              end
              if (i%factor == 1) begin
                  mem_tmp [15 : 8] = token_tmp;
              end
              if (i%factor == 2) begin
                  mem_tmp [23 : 16] = token_tmp;
              end
              if (i%factor == 3) begin
                  mem_tmp [31 : 24] = token_tmp;
                  mem_kernel_0_1 [i/factor] = mem_tmp;
                  mem_tmp [DATA_WIDTH - 1 : 0] = 0;
              end
          end
          if (factor == 2) begin
              if (i%factor == 0) begin
                  mem_tmp [15 : 0] = token_tmp;
              end
              if (i%factor == 1) begin
                  mem_tmp [31 : 16] = token_tmp;
                  mem_kernel_0_1 [i/factor] = mem_tmp;
                  mem_tmp [DATA_WIDTH - 1: 0] = 0;
              end
          end
          if (factor == 1) begin
              mem_kernel_0_1 [i] = token_tmp;
          end
      end 
      if (factor == 4) begin
          if (i%factor != 0) begin
              mem_kernel_0_1 [i/factor] = mem_tmp;
          end
      end
      if (factor == 2) begin
          if (i%factor != 0) begin
              mem_kernel_0_1 [i/factor] = mem_tmp;
          end
      end 
      read_token(fp, token); 
      if(token != "[[/transaction]]") begin 
          $display("ERROR: Simulation using HLS TB failed.");
          $finish; 
      end 
      read_token(fp, token); 
      transaction_idx = transaction_idx + 1; 
  end 
  $fclose(fp); 
end 
 
//------------------------Read file------------------------ 
 
// Read data from file 
initial begin : read_kernel_0_2_file_process 
  integer fp; 
  integer ret; 
  integer factor; 
  reg [127 : 0] token; 
  reg [127 : 0] token_tmp; 
  //reg [kernel_0_2_c_bitwidth - 1 : 0] token_tmp; 
  reg [DATA_WIDTH - 1 : 0] mem_tmp; 
  reg [ 8*5 : 1] str;
  integer transaction_idx; 
  integer i; 
  transaction_idx = 0; 
  mem_tmp [DATA_WIDTH - 1 : 0] = 0;
  count_seperate_factor_by_bitwidth (kernel_0_2_c_bitwidth , factor);
  fp = $fopen(`TV_IN_kernel_0_2 ,"r"); 
  if(fp == 0) begin                               // Failed to open file 
      $display("Failed to open file \"%s\"!", `TV_IN_kernel_0_2); 
      $finish; 
  end 
  read_token(fp, token); 
  if (token != "[[[runtime]]]") begin             // Illegal format 
      $display("ERROR: Simulation using HLS TB failed.");
      $finish; 
  end 
  read_token(fp, token); 
  while (token != "[[[/runtime]]]") begin 
      if (token != "[[transaction]]") begin 
          $display("ERROR: Simulation using HLS TB failed.");
          $finish; 
      end 
      read_token(fp, token);                        // skip transaction number 
      @(posedge clk);
      # 0.2;
      while(AESL_ready_reg !== 1) begin
          @(posedge clk); 
          # 0.2;
      end
      for(i = 0; i < kernel_0_2_DEPTH; i = i + 1) begin 
          read_token(fp, token); 
          ret = $sscanf(token, "0x%x", token_tmp); 
          if (factor == 4) begin
              if (i%factor == 0) begin
                  mem_tmp [7 : 0] = token_tmp;
              end
              if (i%factor == 1) begin
                  mem_tmp [15 : 8] = token_tmp;
              end
              if (i%factor == 2) begin
                  mem_tmp [23 : 16] = token_tmp;
              end
              if (i%factor == 3) begin
                  mem_tmp [31 : 24] = token_tmp;
                  mem_kernel_0_2 [i/factor] = mem_tmp;
                  mem_tmp [DATA_WIDTH - 1 : 0] = 0;
              end
          end
          if (factor == 2) begin
              if (i%factor == 0) begin
                  mem_tmp [15 : 0] = token_tmp;
              end
              if (i%factor == 1) begin
                  mem_tmp [31 : 16] = token_tmp;
                  mem_kernel_0_2 [i/factor] = mem_tmp;
                  mem_tmp [DATA_WIDTH - 1: 0] = 0;
              end
          end
          if (factor == 1) begin
              mem_kernel_0_2 [i] = token_tmp;
          end
      end 
      if (factor == 4) begin
          if (i%factor != 0) begin
              mem_kernel_0_2 [i/factor] = mem_tmp;
          end
      end
      if (factor == 2) begin
          if (i%factor != 0) begin
              mem_kernel_0_2 [i/factor] = mem_tmp;
          end
      end 
      read_token(fp, token); 
      if(token != "[[/transaction]]") begin 
          $display("ERROR: Simulation using HLS TB failed.");
          $finish; 
      end 
      read_token(fp, token); 
      transaction_idx = transaction_idx + 1; 
  end 
  $fclose(fp); 
end 
 
//------------------------Read file------------------------ 
 
// Read data from file 
initial begin : read_kernel_1_0_file_process 
  integer fp; 
  integer ret; 
  integer factor; 
  reg [127 : 0] token; 
  reg [127 : 0] token_tmp; 
  //reg [kernel_1_0_c_bitwidth - 1 : 0] token_tmp; 
  reg [DATA_WIDTH - 1 : 0] mem_tmp; 
  reg [ 8*5 : 1] str;
  integer transaction_idx; 
  integer i; 
  transaction_idx = 0; 
  mem_tmp [DATA_WIDTH - 1 : 0] = 0;
  count_seperate_factor_by_bitwidth (kernel_1_0_c_bitwidth , factor);
  fp = $fopen(`TV_IN_kernel_1_0 ,"r"); 
  if(fp == 0) begin                               // Failed to open file 
      $display("Failed to open file \"%s\"!", `TV_IN_kernel_1_0); 
      $finish; 
  end 
  read_token(fp, token); 
  if (token != "[[[runtime]]]") begin             // Illegal format 
      $display("ERROR: Simulation using HLS TB failed.");
      $finish; 
  end 
  read_token(fp, token); 
  while (token != "[[[/runtime]]]") begin 
      if (token != "[[transaction]]") begin 
          $display("ERROR: Simulation using HLS TB failed.");
          $finish; 
      end 
      read_token(fp, token);                        // skip transaction number 
      @(posedge clk);
      # 0.2;
      while(AESL_ready_reg !== 1) begin
          @(posedge clk); 
          # 0.2;
      end
      for(i = 0; i < kernel_1_0_DEPTH; i = i + 1) begin 
          read_token(fp, token); 
          ret = $sscanf(token, "0x%x", token_tmp); 
          if (factor == 4) begin
              if (i%factor == 0) begin
                  mem_tmp [7 : 0] = token_tmp;
              end
              if (i%factor == 1) begin
                  mem_tmp [15 : 8] = token_tmp;
              end
              if (i%factor == 2) begin
                  mem_tmp [23 : 16] = token_tmp;
              end
              if (i%factor == 3) begin
                  mem_tmp [31 : 24] = token_tmp;
                  mem_kernel_1_0 [i/factor] = mem_tmp;
                  mem_tmp [DATA_WIDTH - 1 : 0] = 0;
              end
          end
          if (factor == 2) begin
              if (i%factor == 0) begin
                  mem_tmp [15 : 0] = token_tmp;
              end
              if (i%factor == 1) begin
                  mem_tmp [31 : 16] = token_tmp;
                  mem_kernel_1_0 [i/factor] = mem_tmp;
                  mem_tmp [DATA_WIDTH - 1: 0] = 0;
              end
          end
          if (factor == 1) begin
              mem_kernel_1_0 [i] = token_tmp;
          end
      end 
      if (factor == 4) begin
          if (i%factor != 0) begin
              mem_kernel_1_0 [i/factor] = mem_tmp;
          end
      end
      if (factor == 2) begin
          if (i%factor != 0) begin
              mem_kernel_1_0 [i/factor] = mem_tmp;
          end
      end 
      read_token(fp, token); 
      if(token != "[[/transaction]]") begin 
          $display("ERROR: Simulation using HLS TB failed.");
          $finish; 
      end 
      read_token(fp, token); 
      transaction_idx = transaction_idx + 1; 
  end 
  $fclose(fp); 
end 
 
//------------------------Read file------------------------ 
 
// Read data from file 
initial begin : read_kernel_1_1_file_process 
  integer fp; 
  integer ret; 
  integer factor; 
  reg [127 : 0] token; 
  reg [127 : 0] token_tmp; 
  //reg [kernel_1_1_c_bitwidth - 1 : 0] token_tmp; 
  reg [DATA_WIDTH - 1 : 0] mem_tmp; 
  reg [ 8*5 : 1] str;
  integer transaction_idx; 
  integer i; 
  transaction_idx = 0; 
  mem_tmp [DATA_WIDTH - 1 : 0] = 0;
  count_seperate_factor_by_bitwidth (kernel_1_1_c_bitwidth , factor);
  fp = $fopen(`TV_IN_kernel_1_1 ,"r"); 
  if(fp == 0) begin                               // Failed to open file 
      $display("Failed to open file \"%s\"!", `TV_IN_kernel_1_1); 
      $finish; 
  end 
  read_token(fp, token); 
  if (token != "[[[runtime]]]") begin             // Illegal format 
      $display("ERROR: Simulation using HLS TB failed.");
      $finish; 
  end 
  read_token(fp, token); 
  while (token != "[[[/runtime]]]") begin 
      if (token != "[[transaction]]") begin 
          $display("ERROR: Simulation using HLS TB failed.");
          $finish; 
      end 
      read_token(fp, token);                        // skip transaction number 
      @(posedge clk);
      # 0.2;
      while(AESL_ready_reg !== 1) begin
          @(posedge clk); 
          # 0.2;
      end
      for(i = 0; i < kernel_1_1_DEPTH; i = i + 1) begin 
          read_token(fp, token); 
          ret = $sscanf(token, "0x%x", token_tmp); 
          if (factor == 4) begin
              if (i%factor == 0) begin
                  mem_tmp [7 : 0] = token_tmp;
              end
              if (i%factor == 1) begin
                  mem_tmp [15 : 8] = token_tmp;
              end
              if (i%factor == 2) begin
                  mem_tmp [23 : 16] = token_tmp;
              end
              if (i%factor == 3) begin
                  mem_tmp [31 : 24] = token_tmp;
                  mem_kernel_1_1 [i/factor] = mem_tmp;
                  mem_tmp [DATA_WIDTH - 1 : 0] = 0;
              end
          end
          if (factor == 2) begin
              if (i%factor == 0) begin
                  mem_tmp [15 : 0] = token_tmp;
              end
              if (i%factor == 1) begin
                  mem_tmp [31 : 16] = token_tmp;
                  mem_kernel_1_1 [i/factor] = mem_tmp;
                  mem_tmp [DATA_WIDTH - 1: 0] = 0;
              end
          end
          if (factor == 1) begin
              mem_kernel_1_1 [i] = token_tmp;
          end
      end 
      if (factor == 4) begin
          if (i%factor != 0) begin
              mem_kernel_1_1 [i/factor] = mem_tmp;
          end
      end
      if (factor == 2) begin
          if (i%factor != 0) begin
              mem_kernel_1_1 [i/factor] = mem_tmp;
          end
      end 
      read_token(fp, token); 
      if(token != "[[/transaction]]") begin 
          $display("ERROR: Simulation using HLS TB failed.");
          $finish; 
      end 
      read_token(fp, token); 
      transaction_idx = transaction_idx + 1; 
  end 
  $fclose(fp); 
end 
 
//------------------------Read file------------------------ 
 
// Read data from file 
initial begin : read_kernel_1_2_file_process 
  integer fp; 
  integer ret; 
  integer factor; 
  reg [127 : 0] token; 
  reg [127 : 0] token_tmp; 
  //reg [kernel_1_2_c_bitwidth - 1 : 0] token_tmp; 
  reg [DATA_WIDTH - 1 : 0] mem_tmp; 
  reg [ 8*5 : 1] str;
  integer transaction_idx; 
  integer i; 
  transaction_idx = 0; 
  mem_tmp [DATA_WIDTH - 1 : 0] = 0;
  count_seperate_factor_by_bitwidth (kernel_1_2_c_bitwidth , factor);
  fp = $fopen(`TV_IN_kernel_1_2 ,"r"); 
  if(fp == 0) begin                               // Failed to open file 
      $display("Failed to open file \"%s\"!", `TV_IN_kernel_1_2); 
      $finish; 
  end 
  read_token(fp, token); 
  if (token != "[[[runtime]]]") begin             // Illegal format 
      $display("ERROR: Simulation using HLS TB failed.");
      $finish; 
  end 
  read_token(fp, token); 
  while (token != "[[[/runtime]]]") begin 
      if (token != "[[transaction]]") begin 
          $display("ERROR: Simulation using HLS TB failed.");
          $finish; 
      end 
      read_token(fp, token);                        // skip transaction number 
      @(posedge clk);
      # 0.2;
      while(AESL_ready_reg !== 1) begin
          @(posedge clk); 
          # 0.2;
      end
      for(i = 0; i < kernel_1_2_DEPTH; i = i + 1) begin 
          read_token(fp, token); 
          ret = $sscanf(token, "0x%x", token_tmp); 
          if (factor == 4) begin
              if (i%factor == 0) begin
                  mem_tmp [7 : 0] = token_tmp;
              end
              if (i%factor == 1) begin
                  mem_tmp [15 : 8] = token_tmp;
              end
              if (i%factor == 2) begin
                  mem_tmp [23 : 16] = token_tmp;
              end
              if (i%factor == 3) begin
                  mem_tmp [31 : 24] = token_tmp;
                  mem_kernel_1_2 [i/factor] = mem_tmp;
                  mem_tmp [DATA_WIDTH - 1 : 0] = 0;
              end
          end
          if (factor == 2) begin
              if (i%factor == 0) begin
                  mem_tmp [15 : 0] = token_tmp;
              end
              if (i%factor == 1) begin
                  mem_tmp [31 : 16] = token_tmp;
                  mem_kernel_1_2 [i/factor] = mem_tmp;
                  mem_tmp [DATA_WIDTH - 1: 0] = 0;
              end
          end
          if (factor == 1) begin
              mem_kernel_1_2 [i] = token_tmp;
          end
      end 
      if (factor == 4) begin
          if (i%factor != 0) begin
              mem_kernel_1_2 [i/factor] = mem_tmp;
          end
      end
      if (factor == 2) begin
          if (i%factor != 0) begin
              mem_kernel_1_2 [i/factor] = mem_tmp;
          end
      end 
      read_token(fp, token); 
      if(token != "[[/transaction]]") begin 
          $display("ERROR: Simulation using HLS TB failed.");
          $finish; 
      end 
      read_token(fp, token); 
      transaction_idx = transaction_idx + 1; 
  end 
  $fclose(fp); 
end 
 
//------------------------Read file------------------------ 
 
// Read data from file 
initial begin : read_kernel_2_0_file_process 
  integer fp; 
  integer ret; 
  integer factor; 
  reg [127 : 0] token; 
  reg [127 : 0] token_tmp; 
  //reg [kernel_2_0_c_bitwidth - 1 : 0] token_tmp; 
  reg [DATA_WIDTH - 1 : 0] mem_tmp; 
  reg [ 8*5 : 1] str;
  integer transaction_idx; 
  integer i; 
  transaction_idx = 0; 
  mem_tmp [DATA_WIDTH - 1 : 0] = 0;
  count_seperate_factor_by_bitwidth (kernel_2_0_c_bitwidth , factor);
  fp = $fopen(`TV_IN_kernel_2_0 ,"r"); 
  if(fp == 0) begin                               // Failed to open file 
      $display("Failed to open file \"%s\"!", `TV_IN_kernel_2_0); 
      $finish; 
  end 
  read_token(fp, token); 
  if (token != "[[[runtime]]]") begin             // Illegal format 
      $display("ERROR: Simulation using HLS TB failed.");
      $finish; 
  end 
  read_token(fp, token); 
  while (token != "[[[/runtime]]]") begin 
      if (token != "[[transaction]]") begin 
          $display("ERROR: Simulation using HLS TB failed.");
          $finish; 
      end 
      read_token(fp, token);                        // skip transaction number 
      @(posedge clk);
      # 0.2;
      while(AESL_ready_reg !== 1) begin
          @(posedge clk); 
          # 0.2;
      end
      for(i = 0; i < kernel_2_0_DEPTH; i = i + 1) begin 
          read_token(fp, token); 
          ret = $sscanf(token, "0x%x", token_tmp); 
          if (factor == 4) begin
              if (i%factor == 0) begin
                  mem_tmp [7 : 0] = token_tmp;
              end
              if (i%factor == 1) begin
                  mem_tmp [15 : 8] = token_tmp;
              end
              if (i%factor == 2) begin
                  mem_tmp [23 : 16] = token_tmp;
              end
              if (i%factor == 3) begin
                  mem_tmp [31 : 24] = token_tmp;
                  mem_kernel_2_0 [i/factor] = mem_tmp;
                  mem_tmp [DATA_WIDTH - 1 : 0] = 0;
              end
          end
          if (factor == 2) begin
              if (i%factor == 0) begin
                  mem_tmp [15 : 0] = token_tmp;
              end
              if (i%factor == 1) begin
                  mem_tmp [31 : 16] = token_tmp;
                  mem_kernel_2_0 [i/factor] = mem_tmp;
                  mem_tmp [DATA_WIDTH - 1: 0] = 0;
              end
          end
          if (factor == 1) begin
              mem_kernel_2_0 [i] = token_tmp;
          end
      end 
      if (factor == 4) begin
          if (i%factor != 0) begin
              mem_kernel_2_0 [i/factor] = mem_tmp;
          end
      end
      if (factor == 2) begin
          if (i%factor != 0) begin
              mem_kernel_2_0 [i/factor] = mem_tmp;
          end
      end 
      read_token(fp, token); 
      if(token != "[[/transaction]]") begin 
          $display("ERROR: Simulation using HLS TB failed.");
          $finish; 
      end 
      read_token(fp, token); 
      transaction_idx = transaction_idx + 1; 
  end 
  $fclose(fp); 
end 
 
//------------------------Read file------------------------ 
 
// Read data from file 
initial begin : read_kernel_2_1_file_process 
  integer fp; 
  integer ret; 
  integer factor; 
  reg [127 : 0] token; 
  reg [127 : 0] token_tmp; 
  //reg [kernel_2_1_c_bitwidth - 1 : 0] token_tmp; 
  reg [DATA_WIDTH - 1 : 0] mem_tmp; 
  reg [ 8*5 : 1] str;
  integer transaction_idx; 
  integer i; 
  transaction_idx = 0; 
  mem_tmp [DATA_WIDTH - 1 : 0] = 0;
  count_seperate_factor_by_bitwidth (kernel_2_1_c_bitwidth , factor);
  fp = $fopen(`TV_IN_kernel_2_1 ,"r"); 
  if(fp == 0) begin                               // Failed to open file 
      $display("Failed to open file \"%s\"!", `TV_IN_kernel_2_1); 
      $finish; 
  end 
  read_token(fp, token); 
  if (token != "[[[runtime]]]") begin             // Illegal format 
      $display("ERROR: Simulation using HLS TB failed.");
      $finish; 
  end 
  read_token(fp, token); 
  while (token != "[[[/runtime]]]") begin 
      if (token != "[[transaction]]") begin 
          $display("ERROR: Simulation using HLS TB failed.");
          $finish; 
      end 
      read_token(fp, token);                        // skip transaction number 
      @(posedge clk);
      # 0.2;
      while(AESL_ready_reg !== 1) begin
          @(posedge clk); 
          # 0.2;
      end
      for(i = 0; i < kernel_2_1_DEPTH; i = i + 1) begin 
          read_token(fp, token); 
          ret = $sscanf(token, "0x%x", token_tmp); 
          if (factor == 4) begin
              if (i%factor == 0) begin
                  mem_tmp [7 : 0] = token_tmp;
              end
              if (i%factor == 1) begin
                  mem_tmp [15 : 8] = token_tmp;
              end
              if (i%factor == 2) begin
                  mem_tmp [23 : 16] = token_tmp;
              end
              if (i%factor == 3) begin
                  mem_tmp [31 : 24] = token_tmp;
                  mem_kernel_2_1 [i/factor] = mem_tmp;
                  mem_tmp [DATA_WIDTH - 1 : 0] = 0;
              end
          end
          if (factor == 2) begin
              if (i%factor == 0) begin
                  mem_tmp [15 : 0] = token_tmp;
              end
              if (i%factor == 1) begin
                  mem_tmp [31 : 16] = token_tmp;
                  mem_kernel_2_1 [i/factor] = mem_tmp;
                  mem_tmp [DATA_WIDTH - 1: 0] = 0;
              end
          end
          if (factor == 1) begin
              mem_kernel_2_1 [i] = token_tmp;
          end
      end 
      if (factor == 4) begin
          if (i%factor != 0) begin
              mem_kernel_2_1 [i/factor] = mem_tmp;
          end
      end
      if (factor == 2) begin
          if (i%factor != 0) begin
              mem_kernel_2_1 [i/factor] = mem_tmp;
          end
      end 
      read_token(fp, token); 
      if(token != "[[/transaction]]") begin 
          $display("ERROR: Simulation using HLS TB failed.");
          $finish; 
      end 
      read_token(fp, token); 
      transaction_idx = transaction_idx + 1; 
  end 
  $fclose(fp); 
end 
 
//------------------------Read file------------------------ 
 
// Read data from file 
initial begin : read_kernel_2_2_file_process 
  integer fp; 
  integer ret; 
  integer factor; 
  reg [127 : 0] token; 
  reg [127 : 0] token_tmp; 
  //reg [kernel_2_2_c_bitwidth - 1 : 0] token_tmp; 
  reg [DATA_WIDTH - 1 : 0] mem_tmp; 
  reg [ 8*5 : 1] str;
  integer transaction_idx; 
  integer i; 
  transaction_idx = 0; 
  mem_tmp [DATA_WIDTH - 1 : 0] = 0;
  count_seperate_factor_by_bitwidth (kernel_2_2_c_bitwidth , factor);
  fp = $fopen(`TV_IN_kernel_2_2 ,"r"); 
  if(fp == 0) begin                               // Failed to open file 
      $display("Failed to open file \"%s\"!", `TV_IN_kernel_2_2); 
      $finish; 
  end 
  read_token(fp, token); 
  if (token != "[[[runtime]]]") begin             // Illegal format 
      $display("ERROR: Simulation using HLS TB failed.");
      $finish; 
  end 
  read_token(fp, token); 
  while (token != "[[[/runtime]]]") begin 
      if (token != "[[transaction]]") begin 
          $display("ERROR: Simulation using HLS TB failed.");
          $finish; 
      end 
      read_token(fp, token);                        // skip transaction number 
      @(posedge clk);
      # 0.2;
      while(AESL_ready_reg !== 1) begin
          @(posedge clk); 
          # 0.2;
      end
      for(i = 0; i < kernel_2_2_DEPTH; i = i + 1) begin 
          read_token(fp, token); 
          ret = $sscanf(token, "0x%x", token_tmp); 
          if (factor == 4) begin
              if (i%factor == 0) begin
                  mem_tmp [7 : 0] = token_tmp;
              end
              if (i%factor == 1) begin
                  mem_tmp [15 : 8] = token_tmp;
              end
              if (i%factor == 2) begin
                  mem_tmp [23 : 16] = token_tmp;
              end
              if (i%factor == 3) begin
                  mem_tmp [31 : 24] = token_tmp;
                  mem_kernel_2_2 [i/factor] = mem_tmp;
                  mem_tmp [DATA_WIDTH - 1 : 0] = 0;
              end
          end
          if (factor == 2) begin
              if (i%factor == 0) begin
                  mem_tmp [15 : 0] = token_tmp;
              end
              if (i%factor == 1) begin
                  mem_tmp [31 : 16] = token_tmp;
                  mem_kernel_2_2 [i/factor] = mem_tmp;
                  mem_tmp [DATA_WIDTH - 1: 0] = 0;
              end
          end
          if (factor == 1) begin
              mem_kernel_2_2 [i] = token_tmp;
          end
      end 
      if (factor == 4) begin
          if (i%factor != 0) begin
              mem_kernel_2_2 [i/factor] = mem_tmp;
          end
      end
      if (factor == 2) begin
          if (i%factor != 0) begin
              mem_kernel_2_2 [i/factor] = mem_tmp;
          end
      end 
      read_token(fp, token); 
      if(token != "[[/transaction]]") begin 
          $display("ERROR: Simulation using HLS TB failed.");
          $finish; 
      end 
      read_token(fp, token); 
      transaction_idx = transaction_idx + 1; 
  end 
  $fclose(fp); 
end 
 
//------------------------Write file----------------------- 
 
// Write data to file 
 
initial begin : write_output_r_file_proc 
  integer fp; 
  integer factor; 
  integer transaction_idx; 
  reg [output_r_c_bitwidth - 1 : 0] mem_tmp; 
  reg [ 100*8 : 1] str;
  integer i; 
  transaction_idx = 0; 
  count_seperate_factor_by_bitwidth (output_r_c_bitwidth , factor);
  while(1) begin 
      @(posedge clk);
      while (output_r_read_data_finish !== 1) begin
          @(posedge clk);
      end
      # 0.1;
      fp = $fopen(`TV_OUT_output_r, "a"); 
      if(fp == 0) begin       // Failed to open file 
          $display("Failed to open file \"%s\"!", `TV_OUT_output_r); 
          $finish; 
      end 
      $fdisplay(fp, "[[transaction]] %d", transaction_idx);
      for (i = 0; i < (output_r_DEPTH - output_r_DEPTH % factor); i = i + 1) begin
          if (factor == 4) begin
              if (i%factor == 0) begin
                  mem_tmp = mem_output_r[i/factor][7:0];
              end
              if (i%factor == 1) begin
                  mem_tmp = mem_output_r[i/factor][15:8];
              end
              if (i%factor == 2) begin
                  mem_tmp = mem_output_r[i/factor][23:16];
              end
              if (i%factor == 3) begin
                  mem_tmp = mem_output_r[i/factor][31:24];
              end
              $fdisplay(fp,"0x%x",mem_tmp);
          end
          if (factor == 2) begin
              if (i%factor == 0) begin
                  mem_tmp = mem_output_r[i/factor][15:0];
              end
              if (i%factor == 1) begin
                  mem_tmp = mem_output_r[i/factor][31:16];
              end
              $fdisplay(fp,"0x%x",mem_tmp);
          end
          if (factor == 1) begin
              $fdisplay(fp,"0x%x",mem_output_r[i]);
          end
      end 
      if (factor == 4) begin
          if ((output_r_DEPTH - 1) % factor == 2) begin
              $fdisplay(fp,"0x%x",mem_output_r[output_r_DEPTH / factor][7:0]);
              $fdisplay(fp,"0x%x",mem_output_r[output_r_DEPTH / factor][15:8]);
              $fdisplay(fp,"0x%x",mem_output_r[output_r_DEPTH / factor][23:16]);
          end
          if ((output_r_DEPTH - 1) % factor == 1) begin
              $fdisplay(fp,"0x%x",mem_output_r[output_r_DEPTH / factor][7:0]);
              $fdisplay(fp,"0x%x",mem_output_r[output_r_DEPTH / factor][15:8]);
          end
          if ((output_r_DEPTH - 1) % factor == 0) begin
              $fdisplay(fp,"0x%x",mem_output_r[output_r_DEPTH / factor][7:0]);
          end
      end
      if (factor == 2) begin
          if ((output_r_DEPTH - 1) % factor == 0) begin
              $fdisplay(fp,"0x%x",mem_output_r[output_r_DEPTH / factor][15:0]);
          end
      end
      $fdisplay(fp, "[[/transaction]]");
      transaction_idx = transaction_idx + 1;
      $fclose(fp); 
      while (TRAN_conv_io_start_in !== 1) begin
          @(posedge clk);
      end
  end 
end 
 
endmodule
