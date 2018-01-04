#ifndef MBED_MPU6050_MPU6050_MBED_H
#define MBED_MPU6050_MPU6050_MBED_H

#include <cstdio>
#include <cstdlib>
#include "mbed.h"
#include "TL_Config.h"
//located in ../library/eMPL_MPU6050
#include "mbed_i2c.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"
//located in ../library/nRF51822/TARGET_MCU_NRF51822/sdk/source/device
#include "nrf51.h"
#include "nrf51_bitfields.h"

#include "math.h"

#define MPU6050_SDA p12
#define MPU6050_SCL p13

#define DEFAULT_MPU_HZ (100)

class Mbed_MPU6050_Accelerometer{
private:
	unsigned long sensor_timestamp;
	short accel[3];
	int state;
	unsigned short accel_fsr,accel_rate;
public:
    /*初始化加速度传感器
    sample_rate:采样频率 范围4HZ~1KHZ
    accel_fsr:加速度传感器量程2/4/8/16g
    gyro_fsr:陀螺仪传感器量程250/500/1000/2000dps
    Dmp_En:1-使能DMP，直接获得姿态信息，返回四元数
    返回0，初始化成功
    1-传感器初始化失败
    */
	Mbed_MPU6050_Accelerometer();
	int setFSR(unsigned short fsr);
    /*
    Dmp_En:1-使能DMP，直接获得姿态信息，返回四元数
    */
    //AccData_Typedef read(uint8_t Dmp_En);
	
	int read();
    double data_x();
	double data_y();
	double data_z();
};

extern Mbed_MPU6050_Accelerometer TL_Accelerometer;

#endif
