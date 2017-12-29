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
 
#define LED_GREEN   p21
#define LED_RED     p22
#define LED_BLUE    p23
#define BUTTON_PIN  p17
#define BATTERY_PIN p1

#define MPU6050_SDA p12
#define MPU6050_SCL p13

#define UART_TX     p9
#define UART_RX     p11

#define DEFAULT_MPU_HZ  (100)

static signed char board_orientation[9] = {
    1, 0, 0,
    0, 1, 0,
    0, 0, 1
};

unsigned short inv_orientation_matrix_to_scalar( const signed char *mtx);

class MPU6050_GYRO_GYRO {

private:
    unsigned long sensor_timestamp;
	short gyro[3], accel[3], sensors;
	long quat[4];
	unsigned char more;
	unsigned short gyro_fsr;
public:
	MPU6050_GYRO_GYRO();
	void read();
	short data_x();
	short data_y();
	short data_z();
	int setFsr(unsigned short fsr);
}; 

extern MPU6050_GYRO_GYRO TL_Gyro;

#endif
