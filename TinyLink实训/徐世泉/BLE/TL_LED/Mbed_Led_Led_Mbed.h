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
 	//打开LED 
	void turnOn()
	{
		led = 0;
	}
	//关闭LED 
	void turnOff()
	{
		led = 1;
	}
	//LED灯亮和熄灭之间的转换 
	void toggle()
	{
		if(led == 0)
		led = 1;
		else if(led == 1)
		led = 0;
	}
	//保持LED灯的状态 
	void state()
	{
		led = led;
	}		
};

extern struct Mbed_Led_Led TL_LED;

#endif
