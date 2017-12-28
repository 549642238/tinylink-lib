#include "TL_Libraries.h"

short x,y,z;

void setup(){
	TL_Gyro.setFSR(500);
	TL_Bluetooth.init("My device");
	TL_Accelerometer.setFSR(2);
}

void loop(){
	TL_LED.toggle();
	TL_Gyro.read();
	x=TL_Gyro.data_x();
	y=TL_Gyro.data_y();
	z=TL_Gyro.data_z();
	printf("Gyro=x=%d,y=%d,z=%d \n",x,y,z);
	TL_Accelerometer.read();
	x=TL_Accelerometer.data_x();
	y=TL_Accelerometer.data_y();
	z=TL_Accelerometer.data_z();
	printf("accel=x=%d,y=%d,z=%d \n",x,y,z);
	TL_TIME.delayMillis(5000);
}
