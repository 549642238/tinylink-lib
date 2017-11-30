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
	
	int init(){
		//I2C存储空间清空
		mbed_i2c_clear(MPU6050_SDA,MPU6050_SCL);

		if(mpu_init(0)){
			return 1;
		}
         //设置所需要的传感器
    	mpu_set_sensors(INV_XYZ_GYRO | INV_XYZ_ACCEL);
		 //设置FIFO
    	mpu_configure_fifo(INV_XYZ_GYRO | INV_XYZ_ACCEL);
		 //设置采样率
    	mpu_set_sample_rate(DEFAULT_MPU_HZ);
		
		dmp_enable_feature(DMP_FEATURE_6X_LP_QUAT|DMP_FEATURE_TAP|    //设置dmp功能
        DMP_FEATURE_ANDROID_ORIENT|DMP_FEATURE_SEND_RAW_ACCEL|DMP_FEATURE_SEND_CAL_GYRO|
                    DMP_FEATURE_GYRO_CAL);
		dmp_set_fifo_rate(DEFAULT_MPU_HZ);        //设置DMP输出速率(最大不超过200Hz)
    	return 0;
	}
}

extern Mbed_MPU6050_Accelerometer TL_Accelerometer;

#endif