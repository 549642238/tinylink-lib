#include "MPU6050_Gyro_Gyro_TinyBLE.h"

MPU6050_GYRO_GYRO TL_Gyro;


MPU6050_GYRO_GYRO::MPU6050_GYRO_GYRO() {
	mbed_i2c_clear(MPU6050_SDA, MPU6050_SCL);
	mbed_i2c_init(MPU6050_SDA, MPU6050_SCL);

	if (mpu_init(0)) {
	    printf("failed to initialize mpu6050\r\n");
	}
	gyro_fsr = 2000;

	//唤醒传感器
	mpu_set_sensors(INV_XYZ_GYRO);
	//将角加速度放入队列中
	mpu_configure_fifo(INV_XYZ_GYRO);
	//设置采样率
	mpu_set_sample_rate(DEFAULT_MPU_HZ);
	dmp_load_motion_driver_firmware();
	//Push gyro and accel orientation to the DMP.
	dmp_set_orientation(
	    inv_orientation_matrix_to_scalar(board_orientation));

	uint16_t dmp_features = DMP_FEATURE_6X_LP_QUAT | DMP_FEATURE_TAP |
	                   DMP_FEATURE_ANDROID_ORIENT | DMP_FEATURE_SEND_RAW_ACCEL | DMP_FEATURE_SEND_CAL_GYRO |
	                   DMP_FEATURE_GYRO_CAL;
	dmp_enable_feature(dmp_features);
	dmp_set_fifo_rate(DEFAULT_MPU_HZ);
	mpu_set_dmp_state(1);

	dmp_set_interrupt_mode(DMP_INT_GESTURE);
}

void MPU6050_GYRO_GYRO::read(){
	dmp_read_fifo(gyro, accel, quat, &sensor_timestamp, &sensors, &more);
	if(!(sensors & INV_XYZ_GYRO)) {
		memset(gyro, 0, sizeof(gyro));
	}
}

short MPU6050_GYRO_GYRO::data_x(){
	return gyro[0];
}

short MPU6050_GYRO_GYRO::data_y(){
	return gyro[1];
}

short MPU6050_GYRO_GYRO::data_z(){
	return gyro[2];
}

int MPU6050_GYRO_GYRO::setFsr(unsigned short fsr) {
	if(mpu_set_gyro_fsr(fsr)) return 1;
	gyro_fsr = fsr;
	return 0;
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
