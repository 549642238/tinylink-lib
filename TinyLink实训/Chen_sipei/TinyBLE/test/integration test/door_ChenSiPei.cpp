#include "TL_Libraries.h"

short Gx,Gy,Gz,Ax,Ay,Az;
int door=0,cnt=0;
void setup(){
	TL_Gyro.setFSR(500);
}

void loop(){
	cnt++;
	printf("%d\n",cnt);
	TL_Gyro.read();
	Gx=TL_Gyro.data_x();
	Gy=TL_Gyro.data_y();
	Gz=TL_Gyro.data_z();
	
	TL_Accelerometer.read();
	Ax=TL_Accelerometer.data_x();
	Ay=TL_Accelerometer.data_y();
	Az=TL_Accelerometer.data_z();
	
	if(Gz>100||Ax>2||Ay>2||Az>2){
		TL_LED.turnOn();
		printf("Gyro=x=%d,y=%d,z=%d \n",Gx,Gy,Gz);
		printf("accel=x=%d,y=%d,z=%d \n",Ax,Ay,Az);
		if(door){
			printf("Door Open\n");
			door=0;
		}		
	}
	else if(Gz<-100||Ax<-2||Ay<-2||Az<-2){
		TL_LED.turnOff();
		printf("Gyro=x=%d,y=%d,z=%d \n",Gx,Gy,Gz);
		printf("accel=x=%d,y=%d,z=%d \n",Ax,Ay,Az);
		printf("Door Close\n");
		door=1;
	}
	
	TL_TIME.delayMillis(1000);
}