

#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xgpiops.h"
#include "xparameters.h"

XGpioPs_Config *gpio_config;
XGpioPs gpio;
void gpio_init(){
	gpio_config = XGpioPs_LookupConfig(XPAR_PS7_GPIO_0_DEVICE_ID);
	int status = XGpioPs_CfgInitialize(&gpio, gpio_config, gpio_config -> BaseAddr);
	if(status == XST_SUCCESS)
		xil_printf("GPIO INIT SUCCESSFUL\n");
	else
		xil_printf("GPIO INIT FAILED\n");
}
int main()
{
    init_platform();
    gpio_init();

    XGpioPs_SetDirectionPin(&gpio, 7, 1);
    XGpioPs_SetDirectionPin(&gpio, 51, 0);



    while(1)
    {
    	u32 dataRead = XGpioPs_ReadPin(&gpio, 51);
    	XGpioPs_WritePin(&gpio, 7, dataRead);
    	xil_printf("Value Read : %0d\n", dataRead);
       	sleep(2);
    }


    cleanup_platform();
    return 0;
}
