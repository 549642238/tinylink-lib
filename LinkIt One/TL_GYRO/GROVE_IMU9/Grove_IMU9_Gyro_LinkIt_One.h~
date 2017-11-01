#ifndef GROVE_IMU9_GYRO_ARDUINO_UNO_H
#define GROVE_IMU9_GYRO_ARDUINO_UNO_H

#include <Arduino.h>
#include "TL_Config.h"
#include "Wire.h"
#include "MPU9250.h"
#include "I2Cdev.h"


class Grove_9DOF_Gyro{
private:
	MPU9250 accelgyro;
	I2Cdev   I2C_M;
	int status;
	int16_t gx, gy, gz;
	int state;
public:
	Grove_9DOF_Gyro();
	int read();
	void init();
	double data_x();
	double data_y();
	double data_z();
};

extern Grove_9DOF_Gyro TL_Gyro;

#endif
