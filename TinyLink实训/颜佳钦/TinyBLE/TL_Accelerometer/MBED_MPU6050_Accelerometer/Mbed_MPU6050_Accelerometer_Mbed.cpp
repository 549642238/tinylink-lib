#include <cstdio>
#include <cstdlib>
#include "Mbed_MPU6050_Accelerometer_Mbed.h"

Mbed_MPU6050_Accelerometer::Mbed_MPU6050_Accelerometer(){
		wait(1);
        mbed_i2c_clear(MPU6050_SDA, MPU6050_SCL);
		mbed_i2c_init(MPU6050_SDA, MPU6050_SCL);
        mpu_init(0); 
        //设置所需要的传感器陀螺仪和加速度
        mpu_set_sensors(INV_XYZ_ACCEL);
        //使能FIFO,采样完成后，自动将数据放入FIFO中
        mpu_configure_fifo(INV_XYZ_ACCEL);
        mpu_set_sample_rate(DEFAULT_MPU_HZ);
        dmp_load_motion_driver_firmware();
		
		mpu_set_sample_rate(accel_rate);
        mpu_set_accel_fsr(accel_fsr);
        uint16_t dmp_features = DMP_FEATURE_6X_LP_QUAT | DMP_FEATURE_TAP |DMP_FEATURE_ANDROID_ORIENT | DMP_FEATURE_SEND_RAW_ACCEL | DMP_FEATURE_SEND_CAL_GYRO |
                             DMP_FEATURE_GYRO_CAL;
            //设置速率
        dmp_enable_feature(dmp_features);
        dmp_set_fifo_rate(DEFAULT_MPU_HZ);
        mpu_set_dmp_state(1);
		dmp_set_interrupt_mode(DMP_INT_GESTURE); 
} 


int Mbed_MPU6050_Accelerometer::read()
{
       return mpu_get_accel_reg(accel,&sensor_timestamp);
}

int Mbed_MPU6050_Accelerometer::setFSR(unsigned short fsr){
	if(mpu_set_accel_fsr(fsr)) return -1;
	else {
		accel_fsr = fsr;
		return 0;
	}
}
//三个加速度分量均以重力加速度g的倍数为单位
double Mbed_MPU6050_Accelerometer::data_x(){
        return (double) accel[0] * accel_fsr/ 32768;
}
double Mbed_MPU6050_Accelerometer::data_y(){
        return (double) accel[1] * accel_fsr/ 32768;
}
double Mbed_MPU6050_Accelerometer::data_z(){
        return (double) accel[2] * accel_fsr/ 32768;
}

Mbed_MPU6050_Accelerometer TL_Accelerometer;