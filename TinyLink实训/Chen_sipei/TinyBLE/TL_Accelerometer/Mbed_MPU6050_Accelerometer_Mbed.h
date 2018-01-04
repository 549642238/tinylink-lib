#ifndef MBED_MPU6050_MPU6050_MBED_H
#define MBED_MPU6050_MPU6050_MBED_H
//Main code Refer to Chenchen
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
    public:
	short accel[3];//加速度
	short gyro[3];
	int state;
	unsigned char new_gyo;//1-数据有效
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

//static unsigned short inv_orientation_matrix_to_scalar(const signed char *mtx);

class Mbed_MPU6050_Accelerometer{
public:
    /*初始化加速度传感器
    sample_rate:采样频率 范围4HZ~1KHZ
    accel_fsr:加速度传感器量程2/4/8/16g
    gyro_fsr:陀螺仪传感器量程250/500/1000/2000dps
    Dmp_En:1-使能DMP，直接获得姿态信息，返回四元数
    返回0，初始化成功
    1-传感器初始化失败
    */
	int init(unsigned short sample_rate,unsigned char accel_fsr,
        unsigned short gyro_fsr,unsigned char Dmp_En);
    /*
    Dmp_En:1-使能DMP，直接获得姿态信息，返回四元数
    */
    AccData_Typedef read(uint8_t Dmp_En);
    double data_x();
	double data_y();
	double data_z();
	short x,y,z;
};
extern AccData_Typedef mAccData;

extern Mbed_MPU6050_Accelerometer TL_Accelerometer;

#endif