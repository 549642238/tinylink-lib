#include "TL_Libraries.h"
// #define Mbed_Led_Template
// #define Mbed_Ble_Led_Template
// #define Mbed_Button_Template
//波特率9600
#define UART_TX     p9
#define UART_RX     p11
Serial pc(UART_TX, UART_RX);
void setup()
{
    TL_Accelerometer.setFSR(2);
}

void loop()
{
    short x, y , z;
	TL_Accelerometer.read();
	x = TL_Accelerometer.data_x();
	y = TL_Accelerometer.data_y();
	z = TL_Accelerometer.data_z();
	pc.printf("x=%d y=%d z=%d\n",x,y,z);
}