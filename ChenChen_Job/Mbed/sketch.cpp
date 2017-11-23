#include "TL_Libraries.h"
// #define Mbed_Led_Template
// #define Mbed_Ble_Led_Template
#define Mbed_Button_Template

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