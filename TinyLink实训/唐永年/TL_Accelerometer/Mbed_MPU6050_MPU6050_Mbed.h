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

#define DEFAULT_MPU_HZ  100

class Mbed_MPU6050_Accelerometer{
	Mbed_MPU6050_Accelerometer():more(1),pc(USBTX,USBRX){}
	//return 0 if cuccessful.
	int init(){
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
		//加载dmp固件
		dmp_load_motion_driver_firmware();
		//更新方向矩阵
		dmp_set_orirentation(inv_orientation_matrix_to_scalar(board_orientation));
		/*
		DMP_FEATURE_6X_LP_QUAT - DMP以200HZ的频率根据陀螺仪的数据计算三轴四元数，低功耗
		DMP_FEATURE_TAP - 这是一个"轻敲"的手势特性，可识别出轻敲事件并分别其基本特征
		DMP_FEATURE_ANDROID_ORIENT - 此功能是兼容Google Motion Driver设备显示方向
		DMP_FEATURE_SEND_RAW_ACCEL - 将加速度计的raw轴的数据放入FIFO,此数据基于芯片坐标系
		DMP_FEATURE_SEND_CAL_GYRO - 将陀螺仪的校准后的数据放入FIFO,不可与DMP_FEATURE_SEND_RAW_GYRO结合使用
		DMP_FEATURE_GYRO_CAL - 此特性将在每次设备静止时间超过8秒时，校准陀螺仪零偏
		*/
		uint16_t dmp_features = DMP_FEATURE_6X_LP_QUAT | DMP_FEATURE_TAP | DMP_FEATURE_ANDROID_ORIENT | DMP_FEATURE_SEND_RAW_ACCEL | DMP_FEATURE_SEND_CAL_GYRO | DMP_FEATURE_GYRO_CAL;
		//使能DMP特性
		dmp_enable_feature(dmp_features);
		//定义DMP输出速率
		dmp_set_fifo_rate(DEFAULT_MPU_HZ);
		//使能DMP
		dmp_set_dmp_state(1);
    	return 0;
	}
}
extern Mbed_MPU6050_Accelerometer TL_Accelerometer;

#endif