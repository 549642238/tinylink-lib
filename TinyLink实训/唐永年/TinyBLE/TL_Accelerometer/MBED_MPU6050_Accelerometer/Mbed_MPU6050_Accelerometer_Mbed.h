#ifndef MBED_MPU6050_MPU6050_MBED_H
#define MBED_MPU6050_MPU6050_MBED_H
//main code follow by Chen chen
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

/* Starting sampling rate. */
#define DEFAULT_MPU_HZ  (100)
static signed char board_orientation[9] = {
    1, 0, 0,
    0, 1, 0,
    0, 0, 1
};
#define q30 1073741824
//返回数据类型
typedef struct
{
    short accel[3];//加速度
    unsigned char new_accel;//1-数据有效
    //想要获取四元数和欧拉角pitch,yaw,roll，Dmp_En =1
    long quat[4];
    unsigned char new_angle;
    float pitch;//围绕X轴旋转，也叫做俯仰角
    float yaw;//围绕Y轴旋转，也叫偏航角
    float roll;//围绕Z轴旋转，也叫翻滚角
    unsigned char more;//1-还有数据需要读
    short sensors;//传感器数据是否有效,&INV_XYZ_GYRO,&INV_XYZ_ACCEL,&INV_WXYZ_QUAT
    unsigned char dmp_en;
}AccData_Typedef;

unsigned short inv_orientation_matrix_to_scalar(const signed char *mtx);

class Mbed_MPU6050_Accelerometer_T {
public:
    Mbed_MPU6050_Accelerometer_T(){
    }
    /*初始化加速度传感器
    sample_rate:采样频率 范围4HZ~1KHZ
    accel_fsr:加速度传感器量程2/4/8/16g
    gyro_fsr:陀螺仪传感器量程250/500/1000/2000dps
    Dmp_En:1-使能DMP，直接获得姿态信息，返回四元数
    返回0，初始化成功
    1-传感器初始化失败
    */
	int init(unsigned short sample_rate,unsigned char accel_fsr,
        unsigned short gyro_fsr,unsigned char Dmp_En)
    {
        mbed_i2c_clear(MPU6050_SDA, MPU6050_SCL);
        if (mpu_init(0)) 
        {
            return 1;
        }
        //设置所需要的传感器陀螺仪和加速度
        mpu_set_sensors(INV_XYZ_GYRO | INV_XYZ_ACCEL);
        //使能FIFO,采样完成后，自动将数据放入FIFO中
        mpu_configure_fifo(INV_XYZ_GYRO | INV_XYZ_ACCEL);
        if(Dmp_En == 0)
        {
            //设置采集样率
            mpu_set_sample_rate(sample_rate);
            mpu_set_gyro_fsr(gyro_fsr);
            mpu_set_accel_fsr(accel_fsr);
            //验证是否配置成功
            unsigned char t_accel_fsr;
            unsigned short t_sample_rate, t_gyro_fsr;
            mpu_get_sample_rate(&t_sample_rate);
            mpu_get_gyro_fsr(&t_gyro_fsr);
            mpu_get_accel_fsr(&t_accel_fsr);
            if(gyro_fsr!=t_gyro_fsr||accel_fsr!=t_accel_fsr||
            t_sample_rate!=sample_rate)
            {
                return 2;
            }            
        }
        else
        {
            mpu_set_sample_rate(DEFAULT_MPU_HZ);
            //DMP是MPU加速度传感器特有的功能，其它公司的传感器不支持直接得出四元数
            //因此例程只输出返回加速度和陀螺仪传感器原始数据
            //加载dmp固件,mpu6050内部集成数字运动处理器
            dmp_load_motion_driver_firmware();
            //设置陀螺仪方向
            dmp_set_orientation(
            inv_orientation_matrix_to_scalar(board_orientation));
            //
            // dmp_register_tap_cb(tap_cb);
            // dmp_register_android_orient_cb(android_orient_cb);
            uint16_t dmp_features = DMP_FEATURE_6X_LP_QUAT | DMP_FEATURE_TAP |
                               DMP_FEATURE_ANDROID_ORIENT | DMP_FEATURE_SEND_RAW_ACCEL | DMP_FEATURE_SEND_CAL_GYRO |
                               DMP_FEATURE_GYRO_CAL;
            //设置速率
            dmp_enable_feature(dmp_features);
            dmp_set_fifo_rate(DEFAULT_MPU_HZ);
            mpu_set_dmp_state(1);            
        }
        return 0;
    } 
    /*
    Dmp_En:1-使能DMP，直接获得姿态信息，返回四元数
    */
    AccData_Typedef read(uint8_t Dmp_En)
    {
        AccData_Typedef tAccData; 
        unsigned long sensor_timestamp;
        if(Dmp_En == 0)
        {
            //调用该函数每次只能读出一个采样值
            mpu_read_fifo(tAccData.gyro, tAccData.accel,&sensor_timestamp,
            (unsigned char *)&tAccData.sensors,&tAccData.more);  
            if (tAccData.sensors & INV_XYZ_ACCEL)//加速度值有效
            {
                tAccData.new_accel = 1;
            }
        } 
        if (sensors & INV_XYZ_ACCEL) return 0;
        return -1;
    }
protected:
    #if 0
    double data_x()
    {
        return (double) accel[0] / 16384;
    }
	double data_y()
    {
        return (double) accel[1] / 16384;
    }
	double data_z()
    {
        return (double) accel[2] / 16384;
    }
    #endif

private:
};


typedef Mbed_MPU6050_Accelerometer_T Mbed_MPU6050_Accelerometer;
extern Mbed_MPU6050_Accelerometer TL_Accelerometer;

#endif