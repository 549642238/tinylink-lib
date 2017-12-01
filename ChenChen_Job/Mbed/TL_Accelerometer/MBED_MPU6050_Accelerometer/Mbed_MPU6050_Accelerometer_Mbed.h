#ifndef MBED_MPU6050_MPU6050_MBED_H
#define MBED_MPU6050_MPU6050_MBED_H

#include <stdio.h>
#include <stdlib.h>
#include "mbed_i2c.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"
#include "mbed.h"
#include "TL_Config.h"
#include "nrf51.h"
#include "nrf51_bitfields.h"


#define MPU6050_SDA p12
#define MPU6050_SCL p13

// #define LOG(...)    { pc.printf(__VA_ARGS__); }
/* Starting sampling rate. */
#define DEFAULT_MPU_HZ  (100)
static signed char board_orientation[9] = {
    1, 0, 0,
    0, 1, 0,
    0, 0, 1
};

unsigned short inv_orientation_matrix_to_scalar(const signed char *mtx);

class Mbed_MPU6050_Accelerometer_T {
public:
    Mbed_MPU6050_Accelerometer_T():more(1),pc(USBTX, USBRX){
    }
	int init()
    {
        mbed_i2c_clear(MPU6050_SDA, MPU6050_SCL);
        mbed_i2c_init(MPU6050_SDA, MPU6050_SCL);
        if (mpu_init(0)) 
        {
            pc.printf("failed to initialize mpu6050\r\n");
        }
        /* Get/set hardware configuration. Start gyro. */
        /* Wake up all sensors. */
        mpu_set_sensors(INV_XYZ_GYRO | INV_XYZ_ACCEL);
        /* Push both gyro and accel data into the FIFO. */
        mpu_configure_fifo(INV_XYZ_GYRO | INV_XYZ_ACCEL);
        mpu_set_sample_rate(DEFAULT_MPU_HZ);
        // 增加算法
        dmp_load_motion_driver_firmware();
        dmp_set_orientation(
        inv_orientation_matrix_to_scalar(board_orientation));
        //
        // dmp_register_tap_cb(tap_cb);
        // dmp_register_android_orient_cb(android_orient_cb);
        uint16_t dmp_features = DMP_FEATURE_6X_LP_QUAT | DMP_FEATURE_TAP |
                           DMP_FEATURE_ANDROID_ORIENT | DMP_FEATURE_SEND_RAW_ACCEL | DMP_FEATURE_SEND_CAL_GYRO |
                           DMP_FEATURE_GYRO_CAL;
        dmp_enable_feature(dmp_features);
        dmp_set_fifo_rate(DEFAULT_MPU_HZ);
        mpu_set_dmp_state(1);
        return 1;
    }    
    void read(void)
    {
        dmp_read_fifo(gyro, accel, quat, &sensor_timestamp, &sensors,
                              &more);
        if (sensors & INV_XYZ_GYRO) {
            pc.printf("GYRO: %d, %d, %d\n", gyro[0], gyro[1], gyro[2]);
        }
        if (sensors & INV_XYZ_ACCEL) {
            pc.printf("ACC: %d, %d, %d\n", accel[0], accel[1], accel[2]);
        }
        
        if (sensors & INV_WXYZ_QUAT) {
            pc.printf("QUAT: %ld, %ld, %ld, %ld\n", quat[0], quat[1], quat[2], quat[3]);
        }
    }
protected:
    void tap_cb(unsigned char direction, unsigned char count)
    {
        pc.printf("Tap motion detected\n");
    }

    void android_orient_cb(unsigned char orientation)
    {
        pc.printf("Oriention changed\n");
    }

private:
    unsigned long sensor_timestamp;
    short gyro[3], accel[3], sensors;
    long quat[4];
    unsigned char more;
    Serial pc;
};


typedef Mbed_MPU6050_Accelerometer_T Mbed_MPU6050_Accelerometer;
extern Mbed_MPU6050_Accelerometer TL_Accelerometer;

#endif
