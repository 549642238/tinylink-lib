#include"MPU6050_Gyro_Gyro_TinyBLE.h"

MPU6050_GYRO_GYRO TL_Gyro;

MPU6050_GYRO_GYRO::MPU6050_GYRO_GYRO(){
    wait(1);
    
    printf("---- Seeed Tiny BLE ----\n");
    
    mbed_i2c_clear(MPU6050_SDA, MPU6050_SCL);
    mbed_i2c_init(MPU6050_SDA, MPU6050_SCL);
    
    if (mpu_init(0)) {
        printf("failed to initialize mpu6050\r\n");
    }
    
    /* Get/set hardware configuration. Start gyro. */
    /* Wake up all sensors. */
    mpu_set_sensors(INV_XYZ_GYRO | INV_XYZ_ACCEL);
    /* Push both gyro and accel data into the FIFO. */
    mpu_configure_fifo(INV_XYZ_GYRO | INV_XYZ_ACCEL);
    mpu_set_sample_rate(DEFAULT_MPU_HZ);
    
    /* Read back configuration in case it was set improperly. */
    unsigned char accel_fsr;
    unsigned short gyro_rate;
    mpu_get_sample_rate(&gyro_rate);
    mpu_get_gyro_fsr(&gyro_fsr);
    mpu_get_accel_fsr(&accel_fsr);
    
    dmp_load_motion_driver_firmware();
    
    uint16_t dmp_features = DMP_FEATURE_6X_LP_QUAT | DMP_FEATURE_TAP |
                       DMP_FEATURE_ANDROID_ORIENT | DMP_FEATURE_SEND_RAW_ACCEL | DMP_FEATURE_SEND_CAL_GYRO |
                       DMP_FEATURE_GYRO_CAL;
    dmp_enable_feature(dmp_features);
    dmp_set_fifo_rate(DEFAULT_MPU_HZ);
    mpu_set_dmp_state(1);
    
    dmp_set_interrupt_mode(DMP_INT_GESTURE);  
}

int MPU6050_GYRO_GYRO::read(){
     state = dmp_read_fifo(gyro, accel, quat, &sensor_timestamp, &sensors, &more);
     if(state){
         gyro[0]=0;
         gyro[1]=0;
         gyro[2]=0;
     }
     printf("state=%d\n",state);
     return state;
}

int MPU6050_GYRO_GYRO::setFSR(unsigned short fsr){
     if(mpu_set_gyro_fsr(fsr)){
         return -1;
     }
     else{
         gyro_fsr = fsr;
         return 0;
     }
}
