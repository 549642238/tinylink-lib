#include "TL_Libraries.h"
// #define Mbed_Led_Template
// #define Mbed_Ble_Led_Template
// #define Mbed_Button_Template
#define Mbed_Accelerometer_Template

#ifdef Mbed_Accelerometer_Template
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
    mAccData = TL_Accelerometer.read(dmp_en);
    if(dmp_en == 0)
    {
        if (1 == mAccData.new_gyo) 
        {
            pc.printf("GYRO: %d, %d, %d\n", mAccData.gyro[0], mAccData.gyro[1],mAccData.gyro[2]);
        }
        if (1 == mAccData.new_accel)
        {
            pc.printf("ACC: %d, %d, %d\n", mAccData.accel[0], mAccData.accel[1],mAccData.accel[2]);
        }
        TL_Time.delayMillis(20);        
    }
    else
    {
        if(1==mAccData.new_angle)
        {
            //mbed编译器pc.printf不支持输出浮点数,keil编译器支持，并且验证通过
            // pc.printf("pitch:%f,yaw:%f,roll:%f\n", mAccData.pitch, mAccData.yaw,mAccData.roll);
            pc.printf("pitch:%d,yaw:%d,roll:%d\n", (uint8_t)mAccData.pitch, (uint8_t)mAccData.yaw,(uint8_t)mAccData.roll);
            TL_Time.delayMillis(100);
        }
    }

}
#endif


#ifdef Mbed_Button_Template
void setup(){
}

void loop(){
	if(TL_BUTTON.read() == PRESSED)
	{
		TL_LED.turnOn();
	}
	else if(TL_BUTTON.read() == RELEASED)
	{
		TL_LED.turnOff();
	}
}
#endif 


#ifdef Mbed_Ble_Led_Template
void setup(){
	TL_Bluetooth.init();//蓝牙服务初始化
	TL_LED.turnOff();
}

void loop(){
	TL_Bluetooth.Ble_Wait();//等待事件
/*  写在着，需要发两次，才能控制灯的亮或者灭
	if(LedState == 1)
	{
		TL_LED.turnOn();
	}
	else 
	{
		TL_LED.turnOff();
	}
*/
}
#endif

#ifdef Mbed_Led_Template
void setup()
{
}

void loop()
{
	TL_Time.delayMillis(1000);
	TL_LED.toggle();	
}

#endif