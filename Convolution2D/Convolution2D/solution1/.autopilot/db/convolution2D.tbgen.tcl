set moduleName convolution2D
set isTaskLevelControl 1
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {convolution2D}
set C_modelType { void 0 }
set C_modelArgList {
	{ input_0 int 32 regular {array 10 { 1 1 } 1 1 }  }
	{ input_1 int 32 regular {array 10 { 1 1 } 1 1 }  }
	{ input_2 int 32 regular {array 5 { 1 1 } 1 1 }  }
	{ kernel_0_0 int 32 regular {pointer 0}  }
	{ kernel_0_1 int 32 regular {pointer 0}  }
	{ kernel_0_2 int 32 regular {pointer 0}  }
	{ kernel_1_0 int 32 regular {pointer 0}  }
	{ kernel_1_1 int 32 regular {pointer 0}  }
	{ kernel_1_2 int 32 regular {pointer 0}  }
	{ kernel_2_0 int 32 regular {pointer 0}  }
	{ kernel_2_1 int 32 regular {pointer 0}  }
	{ kernel_2_2 int 32 regular {pointer 0}  }
	{ output_r int 32 regular {array 9 { 0 3 } 0 1 }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "input_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "input","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 4,"step" : 1},{"low" : 0,"up" : 1,"step" : 1}]}]}]} , 
 	{ "Name" : "input_1", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "input","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 4,"step" : 1},{"low" : 2,"up" : 3,"step" : 1}]}]}]} , 
 	{ "Name" : "input_2", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "input","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 4,"step" : 1},{"low" : 4,"up" : 4,"step" : 1}]}]}]} , 
 	{ "Name" : "kernel_0_0", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "kernel","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 2},{"low" : 0,"up" : 0,"step" : 2}]}]}]} , 
 	{ "Name" : "kernel_0_1", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "kernel","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 2},{"low" : 1,"up" : 1,"step" : 2}]}]}]} , 
 	{ "Name" : "kernel_0_2", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "kernel","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 2},{"low" : 2,"up" : 2,"step" : 2}]}]}]} , 
 	{ "Name" : "kernel_1_0", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "kernel","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 1,"up" : 1,"step" : 2},{"low" : 0,"up" : 0,"step" : 2}]}]}]} , 
 	{ "Name" : "kernel_1_1", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "kernel","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 1,"up" : 1,"step" : 2},{"low" : 1,"up" : 1,"step" : 2}]}]}]} , 
 	{ "Name" : "kernel_1_2", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "kernel","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 1,"up" : 1,"step" : 2},{"low" : 2,"up" : 2,"step" : 2}]}]}]} , 
 	{ "Name" : "kernel_2_0", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "kernel","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 2,"up" : 2,"step" : 2},{"low" : 0,"up" : 0,"step" : 2}]}]}]} , 
 	{ "Name" : "kernel_2_1", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "kernel","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 2,"up" : 2,"step" : 2},{"low" : 1,"up" : 1,"step" : 2}]}]}]} , 
 	{ "Name" : "kernel_2_2", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "kernel","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 2,"up" : 2,"step" : 2},{"low" : 2,"up" : 2,"step" : 2}]}]}]} , 
 	{ "Name" : "output_r", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "output","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 2,"step" : 1},{"low" : 0,"up" : 2,"step" : 1}]}]}]} ]}
# RTL Port declarations: 
set portNum 37
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ input_0_address0 sc_out sc_lv 4 signal 0 } 
	{ input_0_ce0 sc_out sc_logic 1 signal 0 } 
	{ input_0_q0 sc_in sc_lv 32 signal 0 } 
	{ input_0_address1 sc_out sc_lv 4 signal 0 } 
	{ input_0_ce1 sc_out sc_logic 1 signal 0 } 
	{ input_0_q1 sc_in sc_lv 32 signal 0 } 
	{ input_1_address0 sc_out sc_lv 4 signal 1 } 
	{ input_1_ce0 sc_out sc_logic 1 signal 1 } 
	{ input_1_q0 sc_in sc_lv 32 signal 1 } 
	{ input_1_address1 sc_out sc_lv 4 signal 1 } 
	{ input_1_ce1 sc_out sc_logic 1 signal 1 } 
	{ input_1_q1 sc_in sc_lv 32 signal 1 } 
	{ input_2_address0 sc_out sc_lv 3 signal 2 } 
	{ input_2_ce0 sc_out sc_logic 1 signal 2 } 
	{ input_2_q0 sc_in sc_lv 32 signal 2 } 
	{ input_2_address1 sc_out sc_lv 3 signal 2 } 
	{ input_2_ce1 sc_out sc_logic 1 signal 2 } 
	{ input_2_q1 sc_in sc_lv 32 signal 2 } 
	{ kernel_0_0 sc_in sc_lv 32 signal 3 } 
	{ kernel_0_1 sc_in sc_lv 32 signal 4 } 
	{ kernel_0_2 sc_in sc_lv 32 signal 5 } 
	{ kernel_1_0 sc_in sc_lv 32 signal 6 } 
	{ kernel_1_1 sc_in sc_lv 32 signal 7 } 
	{ kernel_1_2 sc_in sc_lv 32 signal 8 } 
	{ kernel_2_0 sc_in sc_lv 32 signal 9 } 
	{ kernel_2_1 sc_in sc_lv 32 signal 10 } 
	{ kernel_2_2 sc_in sc_lv 32 signal 11 } 
	{ output_r_address0 sc_out sc_lv 4 signal 12 } 
	{ output_r_ce0 sc_out sc_logic 1 signal 12 } 
	{ output_r_we0 sc_out sc_logic 1 signal 12 } 
	{ output_r_d0 sc_out sc_lv 32 signal 12 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "input_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "input_0", "role": "address0" }} , 
 	{ "name": "input_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "input_0", "role": "ce0" }} , 
 	{ "name": "input_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "input_0", "role": "q0" }} , 
 	{ "name": "input_0_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "input_0", "role": "address1" }} , 
 	{ "name": "input_0_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "input_0", "role": "ce1" }} , 
 	{ "name": "input_0_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "input_0", "role": "q1" }} , 
 	{ "name": "input_1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "input_1", "role": "address0" }} , 
 	{ "name": "input_1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "input_1", "role": "ce0" }} , 
 	{ "name": "input_1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "input_1", "role": "q0" }} , 
 	{ "name": "input_1_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "input_1", "role": "address1" }} , 
 	{ "name": "input_1_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "input_1", "role": "ce1" }} , 
 	{ "name": "input_1_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "input_1", "role": "q1" }} , 
 	{ "name": "input_2_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "input_2", "role": "address0" }} , 
 	{ "name": "input_2_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "input_2", "role": "ce0" }} , 
 	{ "name": "input_2_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "input_2", "role": "q0" }} , 
 	{ "name": "input_2_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "input_2", "role": "address1" }} , 
 	{ "name": "input_2_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "input_2", "role": "ce1" }} , 
 	{ "name": "input_2_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "input_2", "role": "q1" }} , 
 	{ "name": "kernel_0_0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "kernel_0_0", "role": "default" }} , 
 	{ "name": "kernel_0_1", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "kernel_0_1", "role": "default" }} , 
 	{ "name": "kernel_0_2", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "kernel_0_2", "role": "default" }} , 
 	{ "name": "kernel_1_0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "kernel_1_0", "role": "default" }} , 
 	{ "name": "kernel_1_1", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "kernel_1_1", "role": "default" }} , 
 	{ "name": "kernel_1_2", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "kernel_1_2", "role": "default" }} , 
 	{ "name": "kernel_2_0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "kernel_2_0", "role": "default" }} , 
 	{ "name": "kernel_2_1", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "kernel_2_1", "role": "default" }} , 
 	{ "name": "kernel_2_2", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "kernel_2_2", "role": "default" }} , 
 	{ "name": "output_r_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "output_r", "role": "address0" }} , 
 	{ "name": "output_r_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "output_r", "role": "ce0" }} , 
 	{ "name": "output_r_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "output_r", "role": "we0" }} , 
 	{ "name": "output_r_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "output_r", "role": "d0" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "",
		"CDFG" : "convolution2D",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "70", "EstimateLatencyMax" : "70",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "input_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "input_1", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "input_2", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "kernel_0_0", "Type" : "None", "Direction" : "I"},
			{"Name" : "kernel_0_1", "Type" : "None", "Direction" : "I"},
			{"Name" : "kernel_0_2", "Type" : "None", "Direction" : "I"},
			{"Name" : "kernel_1_0", "Type" : "None", "Direction" : "I"},
			{"Name" : "kernel_1_1", "Type" : "None", "Direction" : "I"},
			{"Name" : "kernel_1_2", "Type" : "None", "Direction" : "I"},
			{"Name" : "kernel_2_0", "Type" : "None", "Direction" : "I"},
			{"Name" : "kernel_2_1", "Type" : "None", "Direction" : "I"},
			{"Name" : "kernel_2_2", "Type" : "None", "Direction" : "I"},
			{"Name" : "output_r", "Type" : "Memory", "Direction" : "O"}]}]}


set ArgLastReadFirstWriteLatency {
	convolution2D {
		input_0 {Type I LastRead 5 FirstWrite -1}
		input_1 {Type I LastRead 5 FirstWrite -1}
		input_2 {Type I LastRead 5 FirstWrite -1}
		kernel_0_0 {Type I LastRead 4 FirstWrite -1}
		kernel_0_1 {Type I LastRead 4 FirstWrite -1}
		kernel_0_2 {Type I LastRead 5 FirstWrite -1}
		kernel_1_0 {Type I LastRead 5 FirstWrite -1}
		kernel_1_1 {Type I LastRead 6 FirstWrite -1}
		kernel_1_2 {Type I LastRead 6 FirstWrite -1}
		kernel_2_0 {Type I LastRead 6 FirstWrite -1}
		kernel_2_1 {Type I LastRead 6 FirstWrite -1}
		kernel_2_2 {Type I LastRead 6 FirstWrite -1}
		output_r {Type O LastRead -1 FirstWrite 8}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "70", "Max" : "70"}
	, {"Name" : "Interval", "Min" : "71", "Max" : "71"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	input_0 { ap_memory {  { input_0_address0 mem_address 1 4 }  { input_0_ce0 mem_ce 1 1 }  { input_0_q0 mem_dout 0 32 }  { input_0_address1 MemPortADDR2 1 4 }  { input_0_ce1 MemPortCE2 1 1 }  { input_0_q1 MemPortDOUT2 0 32 } } }
	input_1 { ap_memory {  { input_1_address0 mem_address 1 4 }  { input_1_ce0 mem_ce 1 1 }  { input_1_q0 mem_dout 0 32 }  { input_1_address1 MemPortADDR2 1 4 }  { input_1_ce1 MemPortCE2 1 1 }  { input_1_q1 MemPortDOUT2 0 32 } } }
	input_2 { ap_memory {  { input_2_address0 mem_address 1 3 }  { input_2_ce0 mem_ce 1 1 }  { input_2_q0 mem_dout 0 32 }  { input_2_address1 MemPortADDR2 1 3 }  { input_2_ce1 MemPortCE2 1 1 }  { input_2_q1 MemPortDOUT2 0 32 } } }
	kernel_0_0 { ap_none {  { kernel_0_0 in_data 0 32 } } }
	kernel_0_1 { ap_none {  { kernel_0_1 in_data 0 32 } } }
	kernel_0_2 { ap_none {  { kernel_0_2 in_data 0 32 } } }
	kernel_1_0 { ap_none {  { kernel_1_0 in_data 0 32 } } }
	kernel_1_1 { ap_none {  { kernel_1_1 in_data 0 32 } } }
	kernel_1_2 { ap_none {  { kernel_1_2 in_data 0 32 } } }
	kernel_2_0 { ap_none {  { kernel_2_0 in_data 0 32 } } }
	kernel_2_1 { ap_none {  { kernel_2_1 in_data 0 32 } } }
	kernel_2_2 { ap_none {  { kernel_2_2 in_data 0 32 } } }
	output_r { ap_memory {  { output_r_address0 mem_address 1 4 }  { output_r_ce0 mem_ce 1 1 }  { output_r_we0 mem_we 1 1 }  { output_r_d0 mem_din 1 32 } } }
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
