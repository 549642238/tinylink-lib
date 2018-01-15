#include "TL_Libraries.h"
#define UART_TX     p9
#define UART_RX     p11
Serial pc(UART_TX, UART_RX,19200);
short Gx,Gy,Gz,Ax,Ay,Az;
int cnt=0;
void setup(){
	TL_Gyro.setFSR(1000);
	TL_Accelerometer.setFSR(4);
	TL_Bluetooth.init("door status");
}

void loop(){
	cnt++;
	pc.printf("%d\n",cnt);
	TL_Gyro.read();
	Gx=TL_Gyro.data_x();
	Gy=TL_Gyro.data_y();
	Gz=TL_Gyro.data_z();
	
	TL_Accelerometer.read();
	Ax=TL_Accelerometer.data_x();
	Ay=TL_Accelerometer.data_y();
	Az=TL_Accelerometer.data_z();
	
	if(Gz>100||Ax>1||Ay>1||Az>1){
		TL_LED.turnOn();
		pc.printf("Gyro x=%d,y=%d,z=%d \n",Gx,Gy,Gz);
		pc.printf("accel x=%d,y=%d,z=%d \n",Ax,Ay,Az);
		pc.printf("Door Open\n");
		TL_Bluetooth.send("door open");			
	}
	else if(Gz<-100||Ax<-1||Ay<-1||Az<-1){
		TL_LED.turnOff();
		pc.printf("Gyro x=%d,y=%d,z=%d \n",Gx,Gy,Gz);
		pc.printf("accel x=%d,y=%d,z=%d \n",Ax,Ay,Az);
		pc.printf("Door Close\n");
		
		TL_Bluetooth.send("door close");
	}
	
	TL_Time.delayMillis(1000);
}
