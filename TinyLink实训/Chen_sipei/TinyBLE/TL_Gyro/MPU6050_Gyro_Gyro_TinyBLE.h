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
            int state;
            unsigned short gyro_fsr = 2000;
    public:
        //init GYRO
        MPU6050_GYRO_GYRO();
        //setDPS:250 or 500 or 1000 or 2000
        int setFSR(unsigned short fsr);
        /*read GYRO data if success return 0, 
            none data return -1, and set data cache 0*/
        int read();
        
        double data_x(){
            return (double)gyro[0]*gyro_fsr/32768;
            }
        double data_y(){
            return (double)gyro[1]*gyro_fsr/32768;
            }
        double data_z(){
            return (double)gyro[2]*gyro_fsr/32768;
            }  
}; 
 
extern MPU6050_GYRO_GYRO TL_Gyro;


#endif
