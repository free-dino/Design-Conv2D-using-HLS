transcript off
onbreak {quit -force}
onerror {quit -force}
transcript on

asim +access +r +m+Conv2D_design  -L xil_defaultlib -L xilinx_vip -L axi_infrastructure_v1_1_0 -L axi_vip_v1_1_19 -L processing_system7_vip_v1_0_21 -L xilinx_vip -L unisims_ver -L unimacro_ver -L secureip -O5 xil_defaultlib.Conv2D_design xil_defaultlib.glbl

do {Conv2D_design.udo}

run 1000ns

endsim

quit -force
