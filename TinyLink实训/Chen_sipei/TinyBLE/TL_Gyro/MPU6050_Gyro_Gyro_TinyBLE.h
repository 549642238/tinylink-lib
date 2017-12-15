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
            short gyro[3], accel[3], sensors;
            long quat[4];
            unsigned char more = 1;
    public:
        MPU6050_GYRO_GYRO();
        
        void read();

        short data_x(){
            return gyro[0];
        }
        short data_y(){
            return gyro[1];
        }
        short data_z(){
            return gyro[2];
        }  
}; 
 
extern MPU6050_GYRO_GYRO TL_Gyro;



#endif
