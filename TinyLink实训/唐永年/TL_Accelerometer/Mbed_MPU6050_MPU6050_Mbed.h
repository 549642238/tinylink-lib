#ifndef MBED_MPU6050_MPU6050_MED_H
#define MBED_MPU6050_MPU6050_MED_H

#include <cstdio>
#include <cstdlib>
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"
#include "mbed.h"
#include "TL_config.h"

#define MPU6050_SCL 23
#define MPU6050_SDA 24


class Mbed_MPU6050_Accelerometer{
	Mbed_MPU6050_Accelerometer(){}
	//@return 0 if cuccessful.
	int init(){
		/*
			function mbed_i2c_clear() contains mbed_i2c_init()
		*/
		mbed_i2c_clear(MPU6050_SDA,MPU6050_SCL);
		//mbed_i2c_init(MPU6050_SDA,MPU6050_SCL);
		if(mpu_init(0)){
			return 1;
		}

		/* Get/set hardware configuration. Start gyro. */
    	/* Wake up all sensors. */
    	mpu_set_sensors(INV_XYZ_GYRO | INV_XYZ_ACCEL);
    	/* Push both gyro and accel data into the FIFO. */
    	mpu_configure_fifo(INV_XYZ_GYRO | INV_XYZ_ACCEL);
    	mpu_set_sample_rate(DEFAULT_MPU_HZ);

    	return 0;
	}
}

extern Mbed_MPU6050_Accelerometer TL_Accelerometer;

#endif