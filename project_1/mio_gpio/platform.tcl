# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct D:\Xilinx\Workspace\1.Study\project_1\mio_gpio\platform.tcl
# 
# OR launch xsct and run below command.
# source D:\Xilinx\Workspace\1.Study\project_1\mio_gpio\platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {mio_gpio}\
-hw {D:\Xilinx\Workspace\1.Study\project_1\design_1_wrapper.xsa}\
-proc {ps7_cortexa9_0} -os {standalone} -out {D:/Xilinx/Workspace/1.Study/project_1}

platform write
platform generate -domains 
platform active {mio_gpio}
bsp reload
platform generate
