#include "mbed.h"
#include "Mbed_Time_Time_Mbed.h"
#define LED_BLUE    p23


DigitalOut led1(LED_BLUE);

//����������ʹ����LEDģ���TIMEģ�� 
int main(void)
{
	led1 = 0;
	while(1)
	{
		led1 = 1;
		//�������ǵ���ʱ������ʱ2s 
		TL_TIME.delayMillis(2000);
		led1 = 0;
		TL_TIME.delayMicros(2000000);
	}
}