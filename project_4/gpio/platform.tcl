# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct D:\Xilinx\Workspace\1.Study\project_4\gpio\platform.tcl
# 
# OR launch xsct and run below command.
# source D:\Xilinx\Workspace\1.Study\project_4\gpio\platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {gpio}\
-hw {D:\Xilinx\Workspace\1.Study\project_4\design_1_wrapper.xsa}\
-proc {ps7_cortexa9_0} -os {standalone} -out {D:/Xilinx/Workspace/1.Study/project_4}

platform write
platform generate -domains 
platform active {gpio}
bsp reload
platform generate
