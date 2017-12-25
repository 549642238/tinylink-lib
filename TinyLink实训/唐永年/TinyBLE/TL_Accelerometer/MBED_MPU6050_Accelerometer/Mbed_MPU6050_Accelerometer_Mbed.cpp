#include <cstdio>
#include <cstdlib>
#include "Mbed_MPU6050_Accelerometer_Mbed.h"

static inline unsigned short inv_row_2_scale(const signed char *row)
{
    unsigned short b;

    if (row[0] > 0)
        b = 0;
    else if (row[0] < 0)
        b = 4;
    else if (row[1] > 0)
        b = 1;
    else if (row[1] < 0)
        b = 5;
    else if (row[2] > 0)
        b = 2;
    else if (row[2] < 0)
        b = 6;
    else
        b = 7;      // error
    return b;
}

unsigned short inv_orientation_matrix_to_scalar(
    const signed char *mtx)
{
    unsigned short scalar;

    /*
       XYZ  010_001_000 Identity Matrix
       XZY  001_010_000
       YXZ  010_000_001
       YZX  000_010_001
       ZXY  001_000_010
       ZYX  000_001_010
     */

    scalar = inv_row_2_scale(mtx);
    scalar |= inv_row_2_scale(mtx + 3) << 3;
    scalar |= inv_row_2_scale(mtx + 6) << 6;


    return scalar;
}


Mbed_MPU6050_Accelerometer TL_Accelerometer;

Serial pcc(p9, p11);
int Mbed_MPU6050_Accelerometer::init(unsigned short sample_rate,unsigned char accel_fsr,
        unsigned short gyro_fsr,unsigned char Dmp_En){
        mbed_i2c_clear(MPU6050_SDA, MPU6050_SCL);
		mbed_i2c_init(MPU6050_SDA, MPU6050_SCL);
        if (mpu_init(0)) 
        {
			return 1;
        }
        //设置所需要的传感器陀螺仪和加速度
        mpu_set_sensors(INV_XYZ_GYRO | INV_XYZ_ACCEL);
        //使能FIFO,采样完成后，自动将数据放入FIFO中
        mpu_configure_fifo(INV_XYZ_GYRO | INV_XYZ_ACCEL);
        mpu_set_sample_rate(DEFAULT_MPU_HZ);
        dmp_load_motion_driver_firmware();
		
		mpu_set_sample_rate(sample_rate);
        mpu_set_gyro_fsr(gyro_fsr);
        mpu_set_accel_fsr(accel_fsr);
        //设置陀螺仪方向
        dmp_set_orientation(
        inv_orientation_matrix_to_scalar(board_orientation));
            //
            // dmp_register_tap_cb(tap_cb);
            // dmp_register_android_orient_cb(android_orient_cb);
        uint16_t dmp_features = DMP_FEATURE_6X_LP_QUAT | DMP_FEATURE_TAP |DMP_FEATURE_ANDROID_ORIENT | DMP_FEATURE_SEND_RAW_ACCEL | DMP_FEATURE_SEND_CAL_GYRO |
                             DMP_FEATURE_GYRO_CAL;
            //设置速率
        dmp_enable_feature(dmp_features);
        dmp_set_fifo_rate(DEFAULT_MPU_HZ);
        mpu_set_dmp_state(1);
		dmp_set_interrupt_mode(DMP_INT_GESTURE);  
        return 0;
} 

AccData_Typedef Mbed_MPU6050_Accelerometer::read(uint8_t Dmp_En)
{
       AccData_Typedef tAccData; 
       unsigned long sensor_timestamp;
	   tAccData.state = dmp_read_fifo(tAccData.gyro,tAccData.accel,tAccData.quat, &sensor_timestamp, &tAccData.sensors,&tAccData.more);
	    x = tAccData.accel[0];
		y = tAccData.accel[1];
		z = tAccData.accel[2];
		return tAccData;
}

double Mbed_MPU6050_Accelerometer::data_x(){
        return (double) x / 16384;
}
double Mbed_MPU6050_Accelerometer::data_y(){
        return (double) y / 16384;
}
double Mbed_MPU6050_Accelerometer::data_z(){
        return (double) z / 16384;
}
