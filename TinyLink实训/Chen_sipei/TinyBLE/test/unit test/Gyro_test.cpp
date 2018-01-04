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
	wait(2);
}
