#include "mbed.h"
#include "Mbed_Time_Time_Mbed.h"
#include "Mbed_Led_Led_Mbed.h"

//测试用例，使用了LED模块和TIME模块 
int main(void)
{
	while(1)
	{
		TL_LED.turnOn();
		//调用我们的延时函数延时2s 
		TL_TIME.delayMillis(2000);
		TL_LED.turnOff();
		TL_TIME.delayMicros(2000000);
		TL_LED.toggle();
		TL_TIME.delayMillis(5000);
		TL_LED.turnOff();
		TL_TIME.delayMillis(5000);
	}
}