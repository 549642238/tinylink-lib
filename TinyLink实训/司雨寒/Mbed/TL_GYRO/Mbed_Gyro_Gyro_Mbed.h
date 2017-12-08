#ifndef MBED_GYRO_GYRO_MBED_H
#define MBED_GYRO_GYRO_MBED_H
#include <cstdio>
#include <cstdlib>
#include "mbed.h"
#include "mbed_i2c.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"
#include "nrf51.h"
#include "nrf51_bitfields.h"
 
#include "BLE.h"
#include "DFUService.h"
#include "UARTService.h"

#define BUTTON_PIN  p17
#define BATTERY_PIN p1
 
#define MPU6050_SDA p12
#define MPU6050_SCL p13
 
#define UART_TX     p9
#define UART_RX     p11
#define UART_CTS    p8
#define UART_RTS    p10


#define DEFAULT_MPU_HZ  (100)

unsigned short inv_orientation_matrix_to_scalar(const signed char *mtx);
static inline unsigned short inv_row_2_scale(const signed char *row);

class Gyro {
	unsigned long sensor_timestamp;
	short gyro[3], accel[3], sensors;
	long quat[4];
	unsigned char more;

	signed char board_orientation[9];

	Gyro() {
		memset(board_orientation, 0, sizeof(board_orientation));
		for(int i = 0 ; i < 3; i++) board_orientation[i][i] = 1;
	}
	int init() {
		mbed_i2c_clear(MPU6050_SDA, MPU6050_SCL);
		mbed_i2c_init(MPU6050_SDA, MPU6050_SCL);
		if(mpu_init(0)) return 1;
		//唤醒传感器
		mpu_set_sensors(INV_XYZ_GYRO | INV_XYZ_ACCEL);
		//将角加速度和轴加速度数据放入队列中
		mpu_configure_fifo(INV_XYZ_GYRO | INV_XYZ_ACCEL);
		//设置采样率
		mpu_set_sample_rate(DEFAULT_MPU_HZ);
		dmp_load_motion_driver_firmware();
		//设置传感器朝向
		dmp_set_orientation(inv_orientation_matrix_to_scalar(board_orientation));
	}

	//读取XYZ三个方向的角加速度
	void read(short* g) {
		dmp_read_fifo(gyro, accel, quat, &sensor_timestamp, &sensors, &more);
		if(sensors) {
			g[0] = gyro[0];
			g[1] = gyro[1];
			g[2] = gyro[2];
		} else {
			g[0] = g[1] = g[2] = 0;
		}
	}

	//读X方向的角加速度
	short read_X() {
		dmp_read_fifo(gyro, accel, quat, &sensor_timestamp, &sensors, &more);
		return sensors ? gyro[0] : 0;
	}

	//读Y方向的角加速度
	short read_Y() {
		dmp_read_fifo(gyro, accel, quat, &sensor_timestamp, &sensors, &more);
		return sensors ? gyro[1] : 0;
	}

	//读Z方向的角加速度
	short read_Z() {
		dmp_read_fifo(gyro, accel, quat, &sensor_timestamp, &sensors, &more);
		return sensors ? gyro[2] : 0;
	}
};

extern Gyro TL_Gyro;

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

#endif
