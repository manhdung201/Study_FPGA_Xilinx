/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xuartlite.h"
#include "xparameters.h"

XUartLite_Config *uart_config1, *uart_config2;
XUartLite uart1, uart2;

void uart_init(){
	uart_config1 = XUartLite_LookupConfig(XPAR_UART1_DEVICE_ID);
	int status1 = XUartLite_CfgInitialize(&uart1, uart_config1, uart_config1->RegBaseAddr);

	uart_config2 = XUartLite_LookupConfig(XPAR_UART1_DEVICE_ID);
	int status2 = XUartLite_CfgInitialize(&uart2, uart_config2, uart_config2->RegBaseAddr);

	if((status1 && status2) == XST_SUCCESS){
		xil_printf("UART INIT SUCCUSSFUL\n");
	} else{
		xil_printf("UART INIT FAILED \n");
	}
}

int main()
{
    init_platform();

    uart_init();
    u8 data1[] = "UART 0->1";
    u8 data2[] = "UART 1->0";
    u8 Rx[9];

    xil_printf("Sending data from UART1 -> UART2 \n");

    while(XUartLite_IsSending(&uart1));

    int byteRcvd = 0;
    while (byteRcvd != 9){
    	byteRcvd = byteRcvd + XUartLite_Recv(&uart2, &Rx[byteRcvd], 9);
    }

    xil_printf("Transmission Complete UART 1 -> UART2 \n");
    for(int i = 0 ; i < 9; i++)
    {
    	xil_printf("%0c",Rx[i]);
    }
    xil_printf("\n");
    /////////////////////////////////////////////////

    xil_printf("Sending Data from UART 1 -> UART0\n");


    XUartLite_Send(&uart2, &data2[0], 9);
    while(XUartLite_IsSending(&uart2));

    byteRcvd = 0;

    while(byteRcvd != 9) {
       byteRcvd = byteRcvd + XUartLite_Recv(&uart1, &Rx[byteRcvd], 9);
       }


     xil_printf("Transmission Complete UART1 -> UART0\n");

       for(int i = 0 ; i < 9; i++)
       {
       	xil_printf("%0c",Rx[i]);
       }
       xil_printf("\n");

    cleanup_platform();
    return 0;
}
