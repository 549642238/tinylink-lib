#ifndef MBED_LED_LED_MBED_H
#define MBED_LED_LED_MBED_H

#include <stdio.h>
#include <stdlib.h>
#include "mbed.h"
#include "TL_Config.h"

struct Mbed_Led_Led
{
	DigitalOut led;
 	Mbed_Led_Led():led(p21){}
 	//��LED 
	void turnOn()
	{
		led = 0;
	}
	//�ر�LED 
	void turnOff()
	{
		led = 1;
	}
	//LED������Ϩ��֮���ת�� 
	void toggle()
	{
		if(led == 0)
		led = 1;
		else if(led == 1)
		led = 0;
	}
	//����LED�Ƶ�״̬ 
	void state()
	{
		led = led;
	}		
};

extern struct Mbed_Led_Led TL_LED;

#endif
