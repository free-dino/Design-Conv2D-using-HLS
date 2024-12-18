// ==============================================================
// File generated on Wed Dec 18 17:07:37 +0700 2024
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:38:27 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================

#include <systemc>
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <stdint.h>
#include "SysCFileHandler.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include <complex>
#include <stdbool.h>
#include "autopilot_cbe.h"
#include "hls_stream.h"
#include "hls_half.h"
#include "hls_signal_handler.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;


// [dump_struct_tree [build_nameSpaceTree] dumpedStructList] ---------->


// [dump_enumeration [get_enumeration_list]] ---------->


// wrapc file define: "input_0"
#define AUTOTB_TVIN_input_0  "../tv/cdatafile/c.convolution2D.autotvin_input_0.dat"
// wrapc file define: "input_1"
#define AUTOTB_TVIN_input_1  "../tv/cdatafile/c.convolution2D.autotvin_input_1.dat"
// wrapc file define: "input_2"
#define AUTOTB_TVIN_input_2  "../tv/cdatafile/c.convolution2D.autotvin_input_2.dat"
// wrapc file define: "kernel_0_0"
#define AUTOTB_TVIN_kernel_0_0  "../tv/cdatafile/c.convolution2D.autotvin_kernel_0_0.dat"
// wrapc file define: "kernel_0_1"
#define AUTOTB_TVIN_kernel_0_1  "../tv/cdatafile/c.convolution2D.autotvin_kernel_0_1.dat"
// wrapc file define: "kernel_0_2"
#define AUTOTB_TVIN_kernel_0_2  "../tv/cdatafile/c.convolution2D.autotvin_kernel_0_2.dat"
// wrapc file define: "kernel_1_0"
#define AUTOTB_TVIN_kernel_1_0  "../tv/cdatafile/c.convolution2D.autotvin_kernel_1_0.dat"
// wrapc file define: "kernel_1_1"
#define AUTOTB_TVIN_kernel_1_1  "../tv/cdatafile/c.convolution2D.autotvin_kernel_1_1.dat"
// wrapc file define: "kernel_1_2"
#define AUTOTB_TVIN_kernel_1_2  "../tv/cdatafile/c.convolution2D.autotvin_kernel_1_2.dat"
// wrapc file define: "kernel_2_0"
#define AUTOTB_TVIN_kernel_2_0  "../tv/cdatafile/c.convolution2D.autotvin_kernel_2_0.dat"
// wrapc file define: "kernel_2_1"
#define AUTOTB_TVIN_kernel_2_1  "../tv/cdatafile/c.convolution2D.autotvin_kernel_2_1.dat"
// wrapc file define: "kernel_2_2"
#define AUTOTB_TVIN_kernel_2_2  "../tv/cdatafile/c.convolution2D.autotvin_kernel_2_2.dat"
// wrapc file define: "output_r"
#define AUTOTB_TVOUT_output_r  "../tv/cdatafile/c.convolution2D.autotvout_output_r.dat"
#define AUTOTB_TVIN_output_r  "../tv/cdatafile/c.convolution2D.autotvin_output_r.dat"

#define INTER_TCL  "../tv/cdatafile/ref.tcl"

// tvout file define: "output_r"
#define AUTOTB_TVOUT_PC_output_r  "../tv/rtldatafile/rtl.convolution2D.autotvout_output_r.dat"

class INTER_TCL_FILE {
	public:
		INTER_TCL_FILE(const char* name) {
			mName = name;
			input_0_depth = 0;
			input_1_depth = 0;
			input_2_depth = 0;
			kernel_0_0_depth = 0;
			kernel_0_1_depth = 0;
			kernel_0_2_depth = 0;
			kernel_1_0_depth = 0;
			kernel_1_1_depth = 0;
			kernel_1_2_depth = 0;
			kernel_2_0_depth = 0;
			kernel_2_1_depth = 0;
			kernel_2_2_depth = 0;
			output_r_depth = 0;
			trans_num =0;
		}

		~INTER_TCL_FILE() {
			mFile.open(mName);
			if (!mFile.good()) {
				cout << "Failed to open file ref.tcl" << endl;
				exit (1);
			}
			string total_list = get_depth_list();
			mFile << "set depth_list {\n";
			mFile << total_list;
			mFile << "}\n";
			mFile << "set trans_num "<<trans_num<<endl;
			mFile.close();
		}

		string get_depth_list () {
			stringstream total_list;
			total_list << "{input_0 " << input_0_depth << "}\n";
			total_list << "{input_1 " << input_1_depth << "}\n";
			total_list << "{input_2 " << input_2_depth << "}\n";
			total_list << "{kernel_0_0 " << kernel_0_0_depth << "}\n";
			total_list << "{kernel_0_1 " << kernel_0_1_depth << "}\n";
			total_list << "{kernel_0_2 " << kernel_0_2_depth << "}\n";
			total_list << "{kernel_1_0 " << kernel_1_0_depth << "}\n";
			total_list << "{kernel_1_1 " << kernel_1_1_depth << "}\n";
			total_list << "{kernel_1_2 " << kernel_1_2_depth << "}\n";
			total_list << "{kernel_2_0 " << kernel_2_0_depth << "}\n";
			total_list << "{kernel_2_1 " << kernel_2_1_depth << "}\n";
			total_list << "{kernel_2_2 " << kernel_2_2_depth << "}\n";
			total_list << "{output_r " << output_r_depth << "}\n";
			return total_list.str();
		}

		void set_num (int num , int* class_num) {
			(*class_num) = (*class_num) > num ? (*class_num) : num;
		}
	public:
		int input_0_depth;
		int input_1_depth;
		int input_2_depth;
		int kernel_0_0_depth;
		int kernel_0_1_depth;
		int kernel_0_2_depth;
		int kernel_1_0_depth;
		int kernel_1_1_depth;
		int kernel_1_2_depth;
		int kernel_2_0_depth;
		int kernel_2_1_depth;
		int kernel_2_2_depth;
		int output_r_depth;
		int trans_num;

	private:
		ofstream mFile;
		const char* mName;
};

extern "C" void convolution2D (
int input[5][5],
int kernel[3][3],
int output[3][3]);

extern "C" void AESL_WRAP_convolution2D (
int input[5][5],
int kernel[3][3],
int output[3][3])
{
	refine_signal_handler();
	fstream wrapc_switch_file_token;
	wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
	int AESL_i;
	if (wrapc_switch_file_token.good())
	{
		CodeState = ENTER_WRAPC_PC;
		static unsigned AESL_transaction_pc = 0;
		string AESL_token;
		string AESL_num;
		static AESL_FILE_HANDLER aesl_fh;


		// output port post check: "output_r"
		aesl_fh.read(AUTOTB_TVOUT_PC_output_r, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_output_r, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_output_r, AESL_token); // data

			sc_bv<32> *output_r_pc_buffer = new sc_bv<32>[9];
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'output_r', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'output_r', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					output_r_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_output_r, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_output_r))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: output_r
				{
					// bitslice(31, 0)
					// {
						// celement: output(31, 0)
						// {
							sc_lv<32>* output_lv0_0_2_1_lv1_0_2_1 = new sc_lv<32>[9];
						// }
					// }

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
						// celement: output(31, 0)
						{
							// carray: (0) => (2) @ (1)
							for (int i_0 = 0; i_0 <= 2; i_0 += 1)
							{
								// carray: (0) => (2) @ (1)
								for (int i_1 = 0; i_1 <= 2; i_1 += 1)
								{
									if (&(output[0][0]) != NULL) // check the null address if the c port is array or others
									{
										output_lv0_0_2_1_lv1_0_2_1[hls_map_index].range(31, 0) = sc_bv<32>(output_r_pc_buffer[hls_map_index].range(31, 0));
										hls_map_index++;
									}
								}
							}
						}
					}

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
						// celement: output(31, 0)
						{
							// carray: (0) => (2) @ (1)
							for (int i_0 = 0; i_0 <= 2; i_0 += 1)
							{
								// carray: (0) => (2) @ (1)
								for (int i_1 = 0; i_1 <= 2; i_1 += 1)
								{
									// sub                    : i_0 i_1
									// ori_name               : output[i_0][i_1]
									// sub_1st_elem           : 0 0
									// ori_name_1st_elem      : output[0][0]
									// output_left_conversion : output[i_0][i_1]
									// output_type_conversion : (output_lv0_0_2_1_lv1_0_2_1[hls_map_index]).to_uint64()
									if (&(output[0][0]) != NULL) // check the null address if the c port is array or others
									{
										output[i_0][i_1] = (output_lv0_0_2_1_lv1_0_2_1[hls_map_index]).to_uint64();
										hls_map_index++;
									}
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] output_r_pc_buffer;
		}

		AESL_transaction_pc++;
	}
	else
	{
		CodeState = ENTER_WRAPC;
		static unsigned AESL_transaction;

		static AESL_FILE_HANDLER aesl_fh;

		// "input_0"
		char* tvin_input_0 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_input_0);

		// "input_1"
		char* tvin_input_1 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_input_1);

		// "input_2"
		char* tvin_input_2 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_input_2);

		// "kernel_0_0"
		char* tvin_kernel_0_0 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_kernel_0_0);

		// "kernel_0_1"
		char* tvin_kernel_0_1 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_kernel_0_1);

		// "kernel_0_2"
		char* tvin_kernel_0_2 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_kernel_0_2);

		// "kernel_1_0"
		char* tvin_kernel_1_0 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_kernel_1_0);

		// "kernel_1_1"
		char* tvin_kernel_1_1 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_kernel_1_1);

		// "kernel_1_2"
		char* tvin_kernel_1_2 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_kernel_1_2);

		// "kernel_2_0"
		char* tvin_kernel_2_0 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_kernel_2_0);

		// "kernel_2_1"
		char* tvin_kernel_2_1 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_kernel_2_1);

		// "kernel_2_2"
		char* tvin_kernel_2_2 = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_kernel_2_2);

		// "output_r"
		char* tvin_output_r = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_output_r);
		char* tvout_output_r = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_output_r);

		CodeState = DUMP_INPUTS;
		static INTER_TCL_FILE tcl_file(INTER_TCL);
		int leading_zero;

		// [[transaction]]
		sprintf(tvin_input_0, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_input_0, tvin_input_0);

		sc_bv<32>* input_0_tvin_wrapc_buffer = new sc_bv<32>[10];

		// RTL Name: input_0
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: input(31, 0)
				{
					// carray: (0) => (4) @ (1)
					for (int i_0 = 0; i_0 <= 4; i_0 += 1)
					{
						// carray: (0) => (1) @ (1)
						for (int i_1 = 0; i_1 <= 1; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : input[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : input[0][0]
							// regulate_c_name       : input
							// input_type_conversion : input[i_0][i_1]
							if (&(input[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> input_tmp_mem;
								input_tmp_mem = input[i_0][i_1];
								input_0_tvin_wrapc_buffer[hls_map_index].range(31, 0) = input_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 10; i++)
		{
			sprintf(tvin_input_0, "%s\n", (input_0_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_input_0, tvin_input_0);
		}

		tcl_file.set_num(10, &tcl_file.input_0_depth);
		sprintf(tvin_input_0, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_input_0, tvin_input_0);

		// release memory allocation
		delete [] input_0_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_input_1, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_input_1, tvin_input_1);

		sc_bv<32>* input_1_tvin_wrapc_buffer = new sc_bv<32>[10];

		// RTL Name: input_1
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: input(31, 0)
				{
					// carray: (0) => (4) @ (1)
					for (int i_0 = 0; i_0 <= 4; i_0 += 1)
					{
						// carray: (2) => (3) @ (1)
						for (int i_1 = 2; i_1 <= 3; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : input[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : input[0][0]
							// regulate_c_name       : input
							// input_type_conversion : input[i_0][i_1]
							if (&(input[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> input_tmp_mem;
								input_tmp_mem = input[i_0][i_1];
								input_1_tvin_wrapc_buffer[hls_map_index].range(31, 0) = input_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 10; i++)
		{
			sprintf(tvin_input_1, "%s\n", (input_1_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_input_1, tvin_input_1);
		}

		tcl_file.set_num(10, &tcl_file.input_1_depth);
		sprintf(tvin_input_1, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_input_1, tvin_input_1);

		// release memory allocation
		delete [] input_1_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_input_2, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_input_2, tvin_input_2);

		sc_bv<32>* input_2_tvin_wrapc_buffer = new sc_bv<32>[5];

		// RTL Name: input_2
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: input(31, 0)
				{
					// carray: (0) => (4) @ (1)
					for (int i_0 = 0; i_0 <= 4; i_0 += 1)
					{
						// carray: (4) => (4) @ (1)
						for (int i_1 = 4; i_1 <= 4; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : input[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : input[0][0]
							// regulate_c_name       : input
							// input_type_conversion : input[i_0][i_1]
							if (&(input[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> input_tmp_mem;
								input_tmp_mem = input[i_0][i_1];
								input_2_tvin_wrapc_buffer[hls_map_index].range(31, 0) = input_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 5; i++)
		{
			sprintf(tvin_input_2, "%s\n", (input_2_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_input_2, tvin_input_2);
		}

		tcl_file.set_num(5, &tcl_file.input_2_depth);
		sprintf(tvin_input_2, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_input_2, tvin_input_2);

		// release memory allocation
		delete [] input_2_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_kernel_0_0, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_kernel_0_0, tvin_kernel_0_0);

		sc_bv<32>* kernel_0_0_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: kernel_0_0
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: kernel(31, 0)
				{
					// carray: (0) => (0) @ (2)
					for (int i_0 = 0; i_0 <= 0; i_0 += 2)
					{
						// carray: (0) => (0) @ (2)
						for (int i_1 = 0; i_1 <= 0; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : kernel[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : kernel[0][0]
							// regulate_c_name       : kernel
							// input_type_conversion : kernel[i_0][i_1]
							if (&(kernel[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> kernel_tmp_mem;
								kernel_tmp_mem = kernel[i_0][i_1];
								kernel_0_0_tvin_wrapc_buffer[hls_map_index].range(31, 0) = kernel_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_kernel_0_0, "%s\n", (kernel_0_0_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_kernel_0_0, tvin_kernel_0_0);
		}

		tcl_file.set_num(1, &tcl_file.kernel_0_0_depth);
		sprintf(tvin_kernel_0_0, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_kernel_0_0, tvin_kernel_0_0);

		// release memory allocation
		delete [] kernel_0_0_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_kernel_0_1, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_kernel_0_1, tvin_kernel_0_1);

		sc_bv<32>* kernel_0_1_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: kernel_0_1
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: kernel(31, 0)
				{
					// carray: (0) => (0) @ (2)
					for (int i_0 = 0; i_0 <= 0; i_0 += 2)
					{
						// carray: (1) => (1) @ (2)
						for (int i_1 = 1; i_1 <= 1; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : kernel[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : kernel[0][0]
							// regulate_c_name       : kernel
							// input_type_conversion : kernel[i_0][i_1]
							if (&(kernel[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> kernel_tmp_mem;
								kernel_tmp_mem = kernel[i_0][i_1];
								kernel_0_1_tvin_wrapc_buffer[hls_map_index].range(31, 0) = kernel_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_kernel_0_1, "%s\n", (kernel_0_1_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_kernel_0_1, tvin_kernel_0_1);
		}

		tcl_file.set_num(1, &tcl_file.kernel_0_1_depth);
		sprintf(tvin_kernel_0_1, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_kernel_0_1, tvin_kernel_0_1);

		// release memory allocation
		delete [] kernel_0_1_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_kernel_0_2, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_kernel_0_2, tvin_kernel_0_2);

		sc_bv<32>* kernel_0_2_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: kernel_0_2
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: kernel(31, 0)
				{
					// carray: (0) => (0) @ (2)
					for (int i_0 = 0; i_0 <= 0; i_0 += 2)
					{
						// carray: (2) => (2) @ (2)
						for (int i_1 = 2; i_1 <= 2; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : kernel[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : kernel[0][0]
							// regulate_c_name       : kernel
							// input_type_conversion : kernel[i_0][i_1]
							if (&(kernel[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> kernel_tmp_mem;
								kernel_tmp_mem = kernel[i_0][i_1];
								kernel_0_2_tvin_wrapc_buffer[hls_map_index].range(31, 0) = kernel_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_kernel_0_2, "%s\n", (kernel_0_2_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_kernel_0_2, tvin_kernel_0_2);
		}

		tcl_file.set_num(1, &tcl_file.kernel_0_2_depth);
		sprintf(tvin_kernel_0_2, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_kernel_0_2, tvin_kernel_0_2);

		// release memory allocation
		delete [] kernel_0_2_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_kernel_1_0, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_kernel_1_0, tvin_kernel_1_0);

		sc_bv<32>* kernel_1_0_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: kernel_1_0
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: kernel(31, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// carray: (0) => (0) @ (2)
						for (int i_1 = 0; i_1 <= 0; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : kernel[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : kernel[0][0]
							// regulate_c_name       : kernel
							// input_type_conversion : kernel[i_0][i_1]
							if (&(kernel[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> kernel_tmp_mem;
								kernel_tmp_mem = kernel[i_0][i_1];
								kernel_1_0_tvin_wrapc_buffer[hls_map_index].range(31, 0) = kernel_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_kernel_1_0, "%s\n", (kernel_1_0_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_kernel_1_0, tvin_kernel_1_0);
		}

		tcl_file.set_num(1, &tcl_file.kernel_1_0_depth);
		sprintf(tvin_kernel_1_0, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_kernel_1_0, tvin_kernel_1_0);

		// release memory allocation
		delete [] kernel_1_0_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_kernel_1_1, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_kernel_1_1, tvin_kernel_1_1);

		sc_bv<32>* kernel_1_1_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: kernel_1_1
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: kernel(31, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// carray: (1) => (1) @ (2)
						for (int i_1 = 1; i_1 <= 1; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : kernel[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : kernel[0][0]
							// regulate_c_name       : kernel
							// input_type_conversion : kernel[i_0][i_1]
							if (&(kernel[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> kernel_tmp_mem;
								kernel_tmp_mem = kernel[i_0][i_1];
								kernel_1_1_tvin_wrapc_buffer[hls_map_index].range(31, 0) = kernel_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_kernel_1_1, "%s\n", (kernel_1_1_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_kernel_1_1, tvin_kernel_1_1);
		}

		tcl_file.set_num(1, &tcl_file.kernel_1_1_depth);
		sprintf(tvin_kernel_1_1, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_kernel_1_1, tvin_kernel_1_1);

		// release memory allocation
		delete [] kernel_1_1_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_kernel_1_2, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_kernel_1_2, tvin_kernel_1_2);

		sc_bv<32>* kernel_1_2_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: kernel_1_2
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: kernel(31, 0)
				{
					// carray: (1) => (1) @ (2)
					for (int i_0 = 1; i_0 <= 1; i_0 += 2)
					{
						// carray: (2) => (2) @ (2)
						for (int i_1 = 2; i_1 <= 2; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : kernel[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : kernel[0][0]
							// regulate_c_name       : kernel
							// input_type_conversion : kernel[i_0][i_1]
							if (&(kernel[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> kernel_tmp_mem;
								kernel_tmp_mem = kernel[i_0][i_1];
								kernel_1_2_tvin_wrapc_buffer[hls_map_index].range(31, 0) = kernel_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_kernel_1_2, "%s\n", (kernel_1_2_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_kernel_1_2, tvin_kernel_1_2);
		}

		tcl_file.set_num(1, &tcl_file.kernel_1_2_depth);
		sprintf(tvin_kernel_1_2, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_kernel_1_2, tvin_kernel_1_2);

		// release memory allocation
		delete [] kernel_1_2_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_kernel_2_0, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_kernel_2_0, tvin_kernel_2_0);

		sc_bv<32>* kernel_2_0_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: kernel_2_0
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: kernel(31, 0)
				{
					// carray: (2) => (2) @ (2)
					for (int i_0 = 2; i_0 <= 2; i_0 += 2)
					{
						// carray: (0) => (0) @ (2)
						for (int i_1 = 0; i_1 <= 0; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : kernel[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : kernel[0][0]
							// regulate_c_name       : kernel
							// input_type_conversion : kernel[i_0][i_1]
							if (&(kernel[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> kernel_tmp_mem;
								kernel_tmp_mem = kernel[i_0][i_1];
								kernel_2_0_tvin_wrapc_buffer[hls_map_index].range(31, 0) = kernel_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_kernel_2_0, "%s\n", (kernel_2_0_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_kernel_2_0, tvin_kernel_2_0);
		}

		tcl_file.set_num(1, &tcl_file.kernel_2_0_depth);
		sprintf(tvin_kernel_2_0, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_kernel_2_0, tvin_kernel_2_0);

		// release memory allocation
		delete [] kernel_2_0_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_kernel_2_1, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_kernel_2_1, tvin_kernel_2_1);

		sc_bv<32>* kernel_2_1_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: kernel_2_1
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: kernel(31, 0)
				{
					// carray: (2) => (2) @ (2)
					for (int i_0 = 2; i_0 <= 2; i_0 += 2)
					{
						// carray: (1) => (1) @ (2)
						for (int i_1 = 1; i_1 <= 1; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : kernel[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : kernel[0][0]
							// regulate_c_name       : kernel
							// input_type_conversion : kernel[i_0][i_1]
							if (&(kernel[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> kernel_tmp_mem;
								kernel_tmp_mem = kernel[i_0][i_1];
								kernel_2_1_tvin_wrapc_buffer[hls_map_index].range(31, 0) = kernel_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_kernel_2_1, "%s\n", (kernel_2_1_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_kernel_2_1, tvin_kernel_2_1);
		}

		tcl_file.set_num(1, &tcl_file.kernel_2_1_depth);
		sprintf(tvin_kernel_2_1, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_kernel_2_1, tvin_kernel_2_1);

		// release memory allocation
		delete [] kernel_2_1_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_kernel_2_2, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_kernel_2_2, tvin_kernel_2_2);

		sc_bv<32>* kernel_2_2_tvin_wrapc_buffer = new sc_bv<32>[1];

		// RTL Name: kernel_2_2
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: kernel(31, 0)
				{
					// carray: (2) => (2) @ (2)
					for (int i_0 = 2; i_0 <= 2; i_0 += 2)
					{
						// carray: (2) => (2) @ (2)
						for (int i_1 = 2; i_1 <= 2; i_1 += 2)
						{
							// sub                   : i_0 i_1
							// ori_name              : kernel[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : kernel[0][0]
							// regulate_c_name       : kernel
							// input_type_conversion : kernel[i_0][i_1]
							if (&(kernel[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> kernel_tmp_mem;
								kernel_tmp_mem = kernel[i_0][i_1];
								kernel_2_2_tvin_wrapc_buffer[hls_map_index].range(31, 0) = kernel_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_kernel_2_2, "%s\n", (kernel_2_2_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_kernel_2_2, tvin_kernel_2_2);
		}

		tcl_file.set_num(1, &tcl_file.kernel_2_2_depth);
		sprintf(tvin_kernel_2_2, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_kernel_2_2, tvin_kernel_2_2);

		// release memory allocation
		delete [] kernel_2_2_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_output_r, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_output_r, tvin_output_r);

		sc_bv<32>* output_r_tvin_wrapc_buffer = new sc_bv<32>[9];

		// RTL Name: output_r
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: output(31, 0)
				{
					// carray: (0) => (2) @ (1)
					for (int i_0 = 0; i_0 <= 2; i_0 += 1)
					{
						// carray: (0) => (2) @ (1)
						for (int i_1 = 0; i_1 <= 2; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : output[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : output[0][0]
							// regulate_c_name       : output
							// input_type_conversion : output[i_0][i_1]
							if (&(output[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> output_tmp_mem;
								output_tmp_mem = output[i_0][i_1];
								output_r_tvin_wrapc_buffer[hls_map_index].range(31, 0) = output_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 9; i++)
		{
			sprintf(tvin_output_r, "%s\n", (output_r_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_output_r, tvin_output_r);
		}

		tcl_file.set_num(9, &tcl_file.output_r_depth);
		sprintf(tvin_output_r, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_output_r, tvin_output_r);

		// release memory allocation
		delete [] output_r_tvin_wrapc_buffer;

// [call_c_dut] ---------->

		CodeState = CALL_C_DUT;
		convolution2D(input, kernel, output);

		CodeState = DUMP_OUTPUTS;

		// [[transaction]]
		sprintf(tvout_output_r, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_output_r, tvout_output_r);

		sc_bv<32>* output_r_tvout_wrapc_buffer = new sc_bv<32>[9];

		// RTL Name: output_r
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: output(31, 0)
				{
					// carray: (0) => (2) @ (1)
					for (int i_0 = 0; i_0 <= 2; i_0 += 1)
					{
						// carray: (0) => (2) @ (1)
						for (int i_1 = 0; i_1 <= 2; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : output[i_0][i_1]
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : output[0][0]
							// regulate_c_name       : output
							// input_type_conversion : output[i_0][i_1]
							if (&(output[0][0]) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> output_tmp_mem;
								output_tmp_mem = output[i_0][i_1];
								output_r_tvout_wrapc_buffer[hls_map_index].range(31, 0) = output_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 9; i++)
		{
			sprintf(tvout_output_r, "%s\n", (output_r_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_output_r, tvout_output_r);
		}

		tcl_file.set_num(9, &tcl_file.output_r_depth);
		sprintf(tvout_output_r, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_output_r, tvout_output_r);

		// release memory allocation
		delete [] output_r_tvout_wrapc_buffer;

		CodeState = DELETE_CHAR_BUFFERS;
		// release memory allocation: "input_0"
		delete [] tvin_input_0;
		// release memory allocation: "input_1"
		delete [] tvin_input_1;
		// release memory allocation: "input_2"
		delete [] tvin_input_2;
		// release memory allocation: "kernel_0_0"
		delete [] tvin_kernel_0_0;
		// release memory allocation: "kernel_0_1"
		delete [] tvin_kernel_0_1;
		// release memory allocation: "kernel_0_2"
		delete [] tvin_kernel_0_2;
		// release memory allocation: "kernel_1_0"
		delete [] tvin_kernel_1_0;
		// release memory allocation: "kernel_1_1"
		delete [] tvin_kernel_1_1;
		// release memory allocation: "kernel_1_2"
		delete [] tvin_kernel_1_2;
		// release memory allocation: "kernel_2_0"
		delete [] tvin_kernel_2_0;
		// release memory allocation: "kernel_2_1"
		delete [] tvin_kernel_2_1;
		// release memory allocation: "kernel_2_2"
		delete [] tvin_kernel_2_2;
		// release memory allocation: "output_r"
		delete [] tvout_output_r;
		delete [] tvin_output_r;

		AESL_transaction++;

		tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
	}
}

