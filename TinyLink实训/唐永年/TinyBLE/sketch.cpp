#include "TL_Libraries.h"
// #define Mbed_Led_Template
// #define Mbed_Ble_Led_Template
// #define Mbed_Button_Template
//波特率9600
#define UART_TX     p9
#define UART_RX     p11
Serial pc(UART_TX, UART_RX);
AccData_Typedef mAccData;
uint8_t dmp_en;//1-获取姿态 0-加速度和角速度原始数据
void setup()
{
    int state;
    mAccData.more = 1;
    dmp_en = 1;
    state = TL_Accelerometer.init(50,2,2000,dmp_en);
    if(0!=state)
    {
        pc.printf("MPU6060 init fail%d\n",state);
    }
    else
    {
        pc.printf("MPU6060 Start\n");
    }
}

void loop()
{
    /*int state = TL_Accelerometer.read(dmp_en);
	if(state != -1){
        pc.printf("ACC: %.2lf, %.2lf, %.2lf\n", TL_Accelerometer.data_x(), TL_Accelerometer.data_y(),TL_Accelerometer.data_z());
		TL_Time.delayMillis(1000);
    }*/
	mAccData = TL_Accelerometer.read(dmp_en);
	if(mAccData.state != -1){
		pc.printf("ACC: %d, %d, %d\n", mAccData.accel[0], mAccData.accel[1],mAccData.accel[2]);
	}
	TL_Time.delayMillis(200);   
}