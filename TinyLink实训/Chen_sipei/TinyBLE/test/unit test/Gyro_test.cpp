#include "TL_Libraries.h"
#define UART_TX     p9
#define UART_RX     p11
Serial pc(UART_TX, UART_RX,9600);
short x,y,z;

void setup(){
	TL_Gyro.setFSR(500);
}

void loop(){
	TL_Gyro.read();
	x=TL_Gyro.data_x();
	y=TL_Gyro.data_y();
	z=TL_Gyro.data_z();
	pc.printf("x=%d,y=%d,z=%d \n",x,y,z);
	wait(2);
}
