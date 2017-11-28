#ifndef MBED_LED_LED_MBED_H
#define MBED_LED_LED_MBED_H
#include <stdio.h>
#include <stdlib.h>
#include "mbed.h"
#include "TL_Config.h"
//构造函数:给成员变量赋值
class Mbed_Led_Led_T {
public:
    Mbed_Led_Led_T():led(p21),led2(p21) {
    }
	void turnOff()
	{
		led = 1;
	}
	void turnOn()
	{
		led = 0;
	}   
	void toggle()
	{
		led = !led;
	}
protected:
    DigitalOut led;	
	DigitalOut led2;	
};
typedef Mbed_Led_Led_T Mbed_Led_Led;
extern Mbed_Led_Led TL_LED;

#endif
