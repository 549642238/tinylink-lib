#ifndef MPU6050_GYRO_GYRO_TINYBLE_H
#define MPU6050_GYRO_GYRO_TINYBLE_H

#include "mbed.h"
#include "mbed_i2c.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"
#include "nrf51.h"
#include "nrf51_bitfields.h"

#include "BLE.h"
#include "DFUService.h"
#include "UARTService.h"

#define MPU6050_SDA p12
#define MPU6050_SCL p13

#define DEFAULT_MPU_HZ  (100)

class MPU6050_GYRO_GYRO {
    private:
    volatile uint8_t motion_event = 0;
    unsigned long sensor_timestamp;
            short gyro[3], accel[3], sensors;
            long quat[4];
            unsigned char more = 1;
    unsigned short gyro_rate, gyro_fsr;
    int state;
    int status;
public:
    MPU6050_GYRO_GYRO();
    void read();
    short data_x();
    short data_y();
    short data_z();
};

MPU6050_GYRO_GYRO::MPU6050_GYRO_GYRO(){
    
    mbed_i2c_clear(MPU6050_SDA, MPU6050_SCL);
    mbed_i2c_init(MPU6050_SDA, MPU6050_SCL);
    mpu_set_sensors(INV_XYZ_GYRO);
    mpu_init(0);
    mpu_set_sensors(INV_XYZ_GYRO);
    mpu_configure_fifo(INV_XYZ_GYRO);
    mpu_set_sample_rate(DEFAULT_MPU_HZ);

    mpu_get_sample_rate(&gyro_rate);
    mpu_get_gyro_fsr(&gyro_fsr);

    dmp_load_motion_driver_firmware();
    
    uint16_t dmp_features =  DMP_FEATURE_SEND_CAL_GYRO | DMP_FEATURE_GYRO_CAL;
    dmp_enable_feature(dmp_features);
    dmp_set_fifo_rate(DEFAULT_MPU_HZ);
    mpu_set_dmp_state(1);
    
    dmp_set_interrupt_mode(DMP_INT_GESTURE);
    dmp_set_tap_thresh(TAP_XYZ, 50);

 }


void MPU6050_GYRO_GYRO::read(){
        dmp_read_fifo(gyro, accel, quat, &sensor_timestamp, &sensors,
                              &more);
    }

short MPU6050_GYRO_GYRO::data_x(){
    return gyro[0];
}
short MPU6050_GYRO_GYRO::data_y(){
    return gyro[1];
}
short MPU6050_GYRO_GYRO::data_z(){
    return gyro[2];
}

MPU6050_GYRO_GYRO TL_Gyro;

#endif
