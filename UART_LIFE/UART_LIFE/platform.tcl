# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct D:\Xilinx\Workspace\1.Study\UART_LIFE\UART_LIFE\platform.tcl
# 
# OR launch xsct and run below command.
# source D:\Xilinx\Workspace\1.Study\UART_LIFE\UART_LIFE\platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {UART_LIFE}\
-hw {D:\Xilinx\Workspace\1.Study\UART_LIFE\design_1_wrapper.xsa}\
-proc {ps7_cortexa9_0} -os {standalone} -out {D:/Xilinx/Workspace/1.Study/UART_LIFE}

platform write
platform generate -domains 
platform active {UART_LIFE}
bsp reload
platform generate
platform clean
platform generate
