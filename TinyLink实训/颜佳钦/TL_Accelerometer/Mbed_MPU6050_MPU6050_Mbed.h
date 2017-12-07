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

//MPU6050作为从机时IIC时钟线管脚定义
#define MPU6050_SDA p23
//MPU6050作为从机时IIC数据线管脚定义
#define MPU6050_SCL p24

//定义引脚中断的时间为100，改小时间变大
#define DEFAULT_MPU_HZ  (100)
static signed char accel_orientation[9] = {
    1, 0, 0,
    0, 1, 0,
    0, 0, 1
};

unsigned short inv_orientation_matrix_to_scalar(const signed char *mtx);

class Mbed_MPU6050_Accelerometer{
	
private:
    unsigned long sensor_timestamp;
    short gyro[3], accel[3], sensors;
    long quat[4];
    unsigned char more;
    Serial pc;
	
public:	
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
		 //加载引擎的固件程序
		dmp_load_motion_driver_firmware();
        dmp_set_orientation(inv_orientation_matrix_to_scalar(accel_orientation));
		//设置采样率,DEFAULT_MPU_HZ是外部设置的引脚中断时间
    	mpu_set_sample_rate(DEFAULT_MPU_HZ);
		 //dmp激活以下属性：参考MPU6050 DMP官方手册，在此不详述参数
		dmp_enable_feature(DMP_FEATURE_6X_LP_QUAT|DMP_FEATURE_TAP|    //设置dmp功能
        DMP_FEATURE_ANDROID_ORIENT|DMP_FEATURE_SEND_RAW_ACCEL|DMP_FEATURE_SEND_CAL_GYRO|
                    DMP_FEATURE_GYRO_CAL);
		dmp_set_fifo_rate(DEFAULT_MPU_HZ); 
        //是自检，用来消除漂移的
        run_self_test();		
		//设置DMP输出速率(最大不超过200Hz)
    	mpu_set_dmp_state(1);
        return 1;
	}
	void read(void)
    {
		//stm32 dmp驱动，由这个函数能读出 陀螺仪，加速度，四元数 等的数据
        dmp_read_fifo(gyro, accel, quat, &sensor_timestamp, &sensors,
                              &more);
        
        if (sensors & INV_XYZ_ACCEL) {
            pc.printf("ACC: %d, %d, %d\n", accel[0], accel[1], accel[2]);
        }
        
    }


};
}

extern Mbed_MPU6050_Accelerometer TL_Accelerometer;

#endif