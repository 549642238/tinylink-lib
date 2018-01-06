#ifndef MPU6050_GYRO_GYRO_TINYBLE_H
#define MPU6050_GYRO_GYRO_TINYBLE_H
 
#include "mbed.h"
#include "mbed_i2c.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"
#include "nrf51.h"
#include "nrf51_bitfields.h"
 

#include "DFUService.h"

 
#define MPU6050_SDA p12
#define MPU6050_SCL p13
 
/* Starting sampling rate. */
#define DEFAULT_MPU_HZ  (100)

class MPU6050_GYRO_GYRO{
    private:
    unsigned long sensor_timestamp;
            short gyro[3];
            int state;
            unsigned short gyro_fsr, gyro_rate;
    public:
        /*init GYRO*/
        MPU6050_GYRO_GYRO();
        /*setDPS full-scale:250 or 500 or 1000 or 2000 Degree Per Second*/
        int setFSR(unsigned short fsr);
        /*read GYRO X,Y,Z raw data if success return 0, 
            none data return -1, and set data cache 0*/
        int read();
        double data_x();
        double data_y();
        double data_z();
}; 

extern MPU6050_GYRO_GYRO TL_Gyro;

#endif
