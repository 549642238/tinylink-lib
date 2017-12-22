
#include "TL_Libraries.h"

int main(void){
TL_Gyro.setFSR(1000);
while(true){
		short x,y,z;
	TL_Gyro.read();
	x=TL_Gyro.data_x();
	y=TL_Gyro.data_y();
	z=TL_Gyro.data_z();
	printf("x=%d,y=%d,z=%d \n",x,y,z);
	wait(1);
}
	return 0;
}
