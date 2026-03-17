#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xgpio.h"
#include "xparameters.h"

XGpio_Config *gpio_config;
XGpio gpio;

void init(){
	int status;
	gpio_config = XGpio_LookupConfig(XPAR_AXI_GPIO_0_DEVICE_ID);
	status = XGpio_CfgInitialize(&gpio, gpio_config, gpio_config->BaseAddress);
	if(status == XST_SUCCESS){
		xil_printf("Device init Successful\n");
	} else {
		xil_printf("Device init Failed");
	}
}

int main()
{
	u32 swValue = 0;
    init_platform();

    XGpio_SetDataDirection(&gpio,1, 0xf);
    XGpio_SetDataDirection(&gpio, 2, 0x0);
    while(1){
    	swValue = XGpio_DiscreteRead(&gpio, 1);
        XGpio_DiscreteWrite(&gpio, 2, swValue);
        xil_printf("Switch value read : %d\n", swValue);
        sleep(2);
    }
    cleanup_platform();
    return 0;
}
