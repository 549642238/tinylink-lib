#ifndef MBED_MPU6050_MPU6050_MBED_H
#define MBED_MPU6050_MPU6050_MBED_H

#include <stdio.h>
#include <stdlib.h>
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"
#include "mbed.h"
#include "TL_Config.h"

#define MPU6050_SDA p12
#define MPU6050_SCL p13
#define MPU6050_SDA p12
#define MPU6050_SCL p13

#define LOG(...)    { pc.printf(__VA_ARGS__); }
/* Starting sampling rate. */
#define DEFAULT_MPU_HZ  (100)

struct Mbed_MPU6050_Accelerometer{
	//UARTService* uartService;
	Mbed_MPU6050_Accelerometer(){
	}
	int init(){
	mbed_i2c_clear(MPU6050_SDA, MPU6050_SCL);
    mbed_i2c_init(MPU6050_SDA, MPU6050_SCL);
    if (mpu_init(0)) {
        LOG("failed to initialize mpu6050\r\n");
    }
	
	/* Get/set hardware configuration. Start gyro. */
    /* Wake up all sensors. */
    mpu_set_sensors(INV_XYZ_GYRO | INV_XYZ_ACCEL);
    /* Push both gyro and accel data into the FIFO. */
    mpu_configure_fifo(INV_XYZ_GYRO | INV_XYZ_ACCEL);
    mpu_set_sample_rate(DEFAULT_MPU_HZ);
    
    /* Read back configuration in case it was set improperly. */
    unsigned char accel_fsr;
    unsigned short gyro_rate, gyro_fsr;
    mpu_get_sample_rate(&gyro_rate);
    mpu_get_gyro_fsr(&gyro_fsr);
    mpu_get_accel_fsr(&accel_fsr);
	InterruptIn motion_probe(p14);
	return 0;
	}

extern struct Mbed_Led_Led TL_LED;

#endif
