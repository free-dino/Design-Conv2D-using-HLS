
set PATH=
call F:/Vivado/Vivado/2018.3/bin/xelab xil_defaultlib.apatb_convolution2D_top glbl -prj convolution2D.prj -L smartconnect_v1_0 -L axi_protocol_checker_v1_1_12 -L axi_protocol_checker_v1_1_13 -L axis_protocol_checker_v1_1_11 -L axis_protocol_checker_v1_1_12 -L xil_defaultlib -L unisims_ver -L xpm --initfile "F:/Vivado/Vivado/2018.3/data/xsim/ip/xsim_ip.ini" --lib "ieee_proposed=./ieee_proposed" -s convolution2D -debug wave
call F:/Vivado/Vivado/2018.3/bin/xsim --noieeewarnings convolution2D -tclbatch convolution2D.tcl

