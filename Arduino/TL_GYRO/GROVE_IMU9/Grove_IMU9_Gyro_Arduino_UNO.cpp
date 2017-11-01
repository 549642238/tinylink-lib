#include "Grove_IMU9_Gyro_Arduino_UNO.h"

Grove_9DOF_Gyro::Grove_9DOF_Gyro(){
	state = 0;
}

int Grove_9DOF_Gyro::read(){
	if (state == 0){
		Wire.begin();
		accelgyro.initialize();
		if(accelgyro.testConnection()){
			status = 1;
		}else{
			status = 0;
		}
		state = 1;
	}
	if(status == 1){
		gx = accelgyro.getRotationX();
		gy = accelgyro.getRotationY();
		gz = accelgyro.getRotationZ();
		return 0;
	}else{
		return -1;
	}
}

double Grove_9DOF_Gyro::data_x(){
	return (double) gx * 250 / 32768;
}

double Grove_9DOF_Gyro::data_y(){
	return (double) gy * 250 / 32768;
}

double Grove_9DOF_Gyro::data_z(){
	return (double) gz * 250 / 32768;
}



#if GYRO == GROVE_IMU9
	Grove_9DOF_Gyro TL_Gyro;
#endif
