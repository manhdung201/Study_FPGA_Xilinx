# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct D:\Xilinx\Workspace\1.Study\project_6_UART\UART_MIO\platform.tcl
# 
# OR launch xsct and run below command.
# source D:\Xilinx\Workspace\1.Study\project_6_UART\UART_MIO\platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {UART_MIO}\
-hw {D:\Xilinx\Workspace\1.Study\project_6_UART\design_1_wrapper.xsa}\
-proc {ps7_cortexa9_0} -os {standalone} -out {D:/Xilinx/Workspace/1.Study/project_6_UART}

platform write
platform generate -domains 
platform active {UART_MIO}
platform generate
