#include "mbed.h"
#include "Mbed_Time_Time_Mbed.h"
#include "Mbed_Led_Led_Mbed.h"

//����������ʹ����LEDģ���TIMEģ�� 
int main(void)
{
	while(1)
	{
		TL_LED.turnOn();
		//�������ǵ���ʱ������ʱ2s 
		TL_TIME.delayMillis(2000);
		TL_LED.turnOff();
		TL_TIME.delayMicros(2000000);
		TL_LED.toggle();
		TL_TIME.delayMillis(5000);
		TL_LED.turnOff();
		TL_TIME.delayMillis(5000);
	}
}