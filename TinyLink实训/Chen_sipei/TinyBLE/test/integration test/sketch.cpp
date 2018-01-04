#include "TL_Libraries.h"

double Gx,Gy,Gz,Ax,Ay,Az;

void setup(){
	TL_Gyro.setFSR(500);
	TL_Bluetooth.init("My device");
}

void loop(){
	TL_LED.toggle();
	TL_Gyro.read();
	Gx=TL_Gyro.data_x();
	Gy=TL_Gyro.data_y();
	Gz=TL_Gyro.data_z();
	printf("Gyro=x=%d,y=%d,z=%d \n",Ax,Ay,Az);
	TL_Accelerometer.read();
	Ax=TL_Accelerometer.data_x();
	Ay=TL_Accelerometer.data_y();
	Az=TL_Accelerometer.data_z();
	printf("accel=x=%d,y=%d,z=%d \n",Ax,Ay,Az);
	TL_TIME.delayMillis(5000);
}
#include "TL_Libraries.h"

short x,y,z;

void setup(){
	TL_Gyro.setFSR(500);
}

void loop(){
	TL_Gyro.read();
	x=TL_Gyro.data_x();
	y=TL_Gyro.data_y();
	z=TL_Gyro.data_z();
	printf("x=%d,y=%d,z=%d \n",x,y,z);
	wait(1);
}
