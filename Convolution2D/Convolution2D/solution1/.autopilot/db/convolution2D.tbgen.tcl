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
	{ input_0 int 32 regular {axi_slave 0}  }
	{ input_1 int 32 regular {axi_slave 0}  }
	{ input_2 int 32 regular {axi_slave 0}  }
	{ kernel_0_0 int 32 regular {axi_slave 0}  }
	{ kernel_0_1 int 32 regular {axi_slave 0}  }
	{ kernel_0_2 int 32 regular {axi_slave 0}  }
	{ kernel_1_0 int 32 regular {axi_slave 0}  }
	{ kernel_1_1 int 32 regular {axi_slave 0}  }
	{ kernel_1_2 int 32 regular {axi_slave 0}  }
	{ kernel_2_0 int 32 regular {axi_slave 0}  }
	{ kernel_2_1 int 32 regular {axi_slave 0}  }
	{ kernel_2_2 int 32 regular {axi_slave 0}  }
	{ output_r int 32 regular {axi_slave 1}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "input_0", "interface" : "axi_slave", "bundle":"conv_io","type":"ap_memory","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "input","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 4,"step" : 1},{"low" : 0,"up" : 1,"step" : 1}]}]}], "offset" : {"in":64}, "offset_end" : {"in":127}} , 
 	{ "Name" : "input_1", "interface" : "axi_slave", "bundle":"conv_io","type":"ap_memory","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "input","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 4,"step" : 1},{"low" : 2,"up" : 3,"step" : 1}]}]}], "offset" : {"in":128}, "offset_end" : {"in":191}} , 
 	{ "Name" : "input_2", "interface" : "axi_slave", "bundle":"conv_io","type":"ap_memory","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "input","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 4,"step" : 1},{"low" : 4,"up" : 4,"step" : 1}]}]}], "offset" : {"in":192}, "offset_end" : {"in":223}} , 
 	{ "Name" : "kernel_0_0", "interface" : "axi_slave", "bundle":"conv_io","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "kernel","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 2},{"low" : 0,"up" : 0,"step" : 2}]}]}], "offset" : {"in":224}, "offset_end" : {"in":231}} , 
 	{ "Name" : "kernel_0_1", "interface" : "axi_slave", "bundle":"conv_io","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "kernel","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 2},{"low" : 1,"up" : 1,"step" : 2}]}]}], "offset" : {"in":232}, "offset_end" : {"in":239}} , 
 	{ "Name" : "kernel_0_2", "interface" : "axi_slave", "bundle":"conv_io","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "kernel","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 2},{"low" : 2,"up" : 2,"step" : 2}]}]}], "offset" : {"in":240}, "offset_end" : {"in":247}} , 
 	{ "Name" : "kernel_1_0", "interface" : "axi_slave", "bundle":"conv_io","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "kernel","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 1,"up" : 1,"step" : 2},{"low" : 0,"up" : 0,"step" : 2}]}]}], "offset" : {"in":248}, "offset_end" : {"in":255}} , 
 	{ "Name" : "kernel_1_1", "interface" : "axi_slave", "bundle":"conv_io","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "kernel","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 1,"up" : 1,"step" : 2},{"low" : 1,"up" : 1,"step" : 2}]}]}], "offset" : {"in":256}, "offset_end" : {"in":263}} , 
 	{ "Name" : "kernel_1_2", "interface" : "axi_slave", "bundle":"conv_io","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "kernel","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 1,"up" : 1,"step" : 2},{"low" : 2,"up" : 2,"step" : 2}]}]}], "offset" : {"in":264}, "offset_end" : {"in":271}} , 
 	{ "Name" : "kernel_2_0", "interface" : "axi_slave", "bundle":"conv_io","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "kernel","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 2,"up" : 2,"step" : 2},{"low" : 0,"up" : 0,"step" : 2}]}]}], "offset" : {"in":272}, "offset_end" : {"in":279}} , 
 	{ "Name" : "kernel_2_1", "interface" : "axi_slave", "bundle":"conv_io","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "kernel","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 2,"up" : 2,"step" : 2},{"low" : 1,"up" : 1,"step" : 2}]}]}], "offset" : {"in":280}, "offset_end" : {"in":287}} , 
 	{ "Name" : "kernel_2_2", "interface" : "axi_slave", "bundle":"conv_io","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "kernel","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 2,"up" : 2,"step" : 2},{"low" : 2,"up" : 2,"step" : 2}]}]}], "offset" : {"in":288}, "offset_end" : {"in":295}} , 
 	{ "Name" : "output_r", "interface" : "axi_slave", "bundle":"conv_io","type":"ap_memory","bitwidth" : 32, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "output","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 2,"step" : 1},{"low" : 0,"up" : 2,"step" : 1}]}]}], "offset" : {"out":320}, "offset_end" : {"out":383}} ]}
# RTL Port declarations: 
set portNum 20
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst_n sc_in sc_logic 1 reset -1 active_low_sync } 
	{ s_axi_conv_io_AWVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_conv_io_AWREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_conv_io_AWADDR sc_in sc_lv 9 signal -1 } 
	{ s_axi_conv_io_WVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_conv_io_WREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_conv_io_WDATA sc_in sc_lv 32 signal -1 } 
	{ s_axi_conv_io_WSTRB sc_in sc_lv 4 signal -1 } 
	{ s_axi_conv_io_ARVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_conv_io_ARREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_conv_io_ARADDR sc_in sc_lv 9 signal -1 } 
	{ s_axi_conv_io_RVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_conv_io_RREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_conv_io_RDATA sc_out sc_lv 32 signal -1 } 
	{ s_axi_conv_io_RRESP sc_out sc_lv 2 signal -1 } 
	{ s_axi_conv_io_BVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_conv_io_BREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_conv_io_BRESP sc_out sc_lv 2 signal -1 } 
	{ interrupt sc_out sc_logic 1 signal -1 } 
}
set NewPortList {[ 
	{ "name": "s_axi_conv_io_AWADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":9, "type": "signal", "bundle":{"name": "conv_io", "role": "AWADDR" },"address":[{"name":"convolution2D","role":"start","value":"0","valid_bit":"0"},{"name":"convolution2D","role":"continue","value":"0","valid_bit":"4"},{"name":"convolution2D","role":"auto_start","value":"0","valid_bit":"7"},{"name":"input_0","role":"data","value":"64"},{"name":"input_1","role":"data","value":"128"},{"name":"input_2","role":"data","value":"192"},{"name":"kernel_0_0","role":"data","value":"224"},{"name":"kernel_0_1","role":"data","value":"232"},{"name":"kernel_0_2","role":"data","value":"240"},{"name":"kernel_1_0","role":"data","value":"248"},{"name":"kernel_1_1","role":"data","value":"256"},{"name":"kernel_1_2","role":"data","value":"264"},{"name":"kernel_2_0","role":"data","value":"272"},{"name":"kernel_2_1","role":"data","value":"280"},{"name":"kernel_2_2","role":"data","value":"288"}] },
	{ "name": "s_axi_conv_io_AWVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_io", "role": "AWVALID" } },
	{ "name": "s_axi_conv_io_AWREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_io", "role": "AWREADY" } },
	{ "name": "s_axi_conv_io_WVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_io", "role": "WVALID" } },
	{ "name": "s_axi_conv_io_WREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_io", "role": "WREADY" } },
	{ "name": "s_axi_conv_io_WDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_io", "role": "WDATA" } },
	{ "name": "s_axi_conv_io_WSTRB", "direction": "in", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "conv_io", "role": "WSTRB" } },
	{ "name": "s_axi_conv_io_ARADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":9, "type": "signal", "bundle":{"name": "conv_io", "role": "ARADDR" },"address":[{"name":"convolution2D","role":"start","value":"0","valid_bit":"0"},{"name":"convolution2D","role":"done","value":"0","valid_bit":"1"},{"name":"convolution2D","role":"idle","value":"0","valid_bit":"2"},{"name":"convolution2D","role":"ready","value":"0","valid_bit":"3"},{"name":"convolution2D","role":"auto_start","value":"0","valid_bit":"7"},{"name":"output_r","role":"data","value":"320"}] },
	{ "name": "s_axi_conv_io_ARVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_io", "role": "ARVALID" } },
	{ "name": "s_axi_conv_io_ARREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_io", "role": "ARREADY" } },
	{ "name": "s_axi_conv_io_RVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_io", "role": "RVALID" } },
	{ "name": "s_axi_conv_io_RREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_io", "role": "RREADY" } },
	{ "name": "s_axi_conv_io_RDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_io", "role": "RDATA" } },
	{ "name": "s_axi_conv_io_RRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "conv_io", "role": "RRESP" } },
	{ "name": "s_axi_conv_io_BVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_io", "role": "BVALID" } },
	{ "name": "s_axi_conv_io_BREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_io", "role": "BREADY" } },
	{ "name": "s_axi_conv_io_BRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "conv_io", "role": "BRESP" } },
	{ "name": "interrupt", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_io", "role": "interrupt" } }, 
 	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst_n", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1"],
		"CDFG" : "convolution2D",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "25", "EstimateLatencyMax" : "25",
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
			{"Name" : "output_r", "Type" : "Memory", "Direction" : "O"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.convolution2D_conv_io_s_axi_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	convolution2D {
		input_0 {Type I LastRead 6 FirstWrite -1}
		input_1 {Type I LastRead 6 FirstWrite -1}
		input_2 {Type I LastRead 3 FirstWrite -1}
		kernel_0_0 {Type I LastRead 2 FirstWrite -1}
		kernel_0_1 {Type I LastRead 2 FirstWrite -1}
		kernel_0_2 {Type I LastRead 2 FirstWrite -1}
		kernel_1_0 {Type I LastRead 2 FirstWrite -1}
		kernel_1_1 {Type I LastRead 2 FirstWrite -1}
		kernel_1_2 {Type I LastRead 2 FirstWrite -1}
		kernel_2_0 {Type I LastRead 2 FirstWrite -1}
		kernel_2_1 {Type I LastRead 2 FirstWrite -1}
		kernel_2_2 {Type I LastRead 2 FirstWrite -1}
		output_r {Type O LastRead -1 FirstWrite 10}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "25", "Max" : "25"}
	, {"Name" : "Interval", "Min" : "26", "Max" : "26"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
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
