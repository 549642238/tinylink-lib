#ifndef GROVE_MPU6050_ACCELEROMETER_ARDUINO_UNO_H
#define GROVE_MPU6050_ACCELEROMETER_ARDUINO_UNO_H



#include <Arduino.h>
#include "TL_Config.h"
#include "Wire.h"
#include "MPU6050.h"
#include "I2Cdev.h"


class Grove_MPU6050_Accelerometer_Arduino_UNO{
private:
	MPU6050 accelgyro;
	I2Cdev I2C_M;
	int status;
	int16_t ax, ay, az;
	int state;
public:
	Grove_MPU6050_Accelerometer_Arduino_UNO();
	int read();
	double data_x();
	double data_y();
	double data_z();
};

extern Grove_MPU6050_Accelerometer_Arduino_UNO TL_Accelerometer;

#endif
