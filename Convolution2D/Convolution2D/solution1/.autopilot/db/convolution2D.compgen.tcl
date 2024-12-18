# This script segment is generated automatically by AutoPilot

# clear list
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_begin
    cg_default_interface_gen_bundle_begin
    AESL_LIB_XILADAPTER::native_axis_begin
}

set port_conv_io {
ap_start { }
ap_done { }
ap_ready { }
ap_idle { }
input_0 { 
	dir I
	width 32
	depth 10
	mode ap_memory
	offset 64
	offset_end 127
}
input_1 { 
	dir I
	width 32
	depth 10
	mode ap_memory
	offset 128
	offset_end 191
}
input_2 { 
	dir I
	width 32
	depth 5
	mode ap_memory
	offset 192
	offset_end 223
}
kernel_0_0 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 224
	offset_end 231
}
kernel_0_1 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 232
	offset_end 239
}
kernel_0_2 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 240
	offset_end 247
}
kernel_1_0 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 248
	offset_end 255
}
kernel_1_1 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 256
	offset_end 263
}
kernel_1_2 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 264
	offset_end 271
}
kernel_2_0 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 272
	offset_end 279
}
kernel_2_1 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 280
	offset_end 287
}
kernel_2_2 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 288
	offset_end 295
}
output_r { 
	dir O
	width 32
	depth 9
	mode ap_memory
	offset 320
	offset_end 383
}
}


# Native S_AXILite:
if {${::AESL::PGuard_simmodel_gen}} {
	if {[info proc ::AESL_LIB_XILADAPTER::s_axilite_gen] == "::AESL_LIB_XILADAPTER::s_axilite_gen"} {
		eval "::AESL_LIB_XILADAPTER::s_axilite_gen { \
			id 1 \
			corename convolution2D_conv_io_axilite \
			name convolution2D_conv_io_s_axi \
			ports {$port_conv_io} \
			op interface \
			is_flushable 0 \ 
		} "
	} else {
		puts "@W \[IMPL-110\] Cannot find AXI Lite interface model in the library. Ignored generation of AXI Lite  interface for 'conv_io'"
	}
}

if {${::AESL::PGuard_rtl_comp_handler}} {
	::AP::rtl_comp_handler convolution2D_conv_io_s_axi
}


# Adapter definition:
set PortName ap_clk
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_clock] == "cg_default_interface_gen_clock"} {
eval "cg_default_interface_gen_clock { \
    id -1 \
    name ${PortName} \
    reset_level 0 \
    sync_rst true \
    corename apif_ap_clk \
    data_wd ${DataWd} \
    op interface \
}"
} else {
puts "@W \[IMPL-113\] Cannot find bus interface model in the library. Ignored generation of bus interface for '${PortName}'"
}
}


# Adapter definition:
set PortName ap_rst_n
set DataWd 1 
if {${::AESL::PGuard_autoexp_gen}} {
if {[info proc cg_default_interface_gen_reset] == "cg_default_interface_gen_reset"} {
eval "cg_default_interface_gen_reset { \
    id -2 \
    name ${PortName} \
    reset_level 0 \
    sync_rst true \
    corename apif_ap_rst_n \
    data_wd ${DataWd} \
    op interface \
}"
} else {
puts "@W \[IMPL-114\] Cannot find bus interface model in the library. Ignored generation of bus interface for '${PortName}'"
}
}



# merge
if {${::AESL::PGuard_autoexp_gen}} {
    cg_default_interface_gen_dc_end
    cg_default_interface_gen_bundle_end
    AESL_LIB_XILADAPTER::native_axis_end
}


