#ifndef MBED_TIME_TIME_MBED_H
#define MBED_TIME_TIME_MBED_H

#include <stdio.h>
#include <stdlib.h>
#include "mbed.h"
#include "TL_Config.h"

class Mbed_Time_Time_T
{
	public:
	Mbed_Time_Time_T()
	{}
	//定义三个延时函数，分别延时s秒，ms毫秒，us微秒 

	void delayMillis(unsigned long ms)
	{
		wait_ms(ms);
	}
	void delayMicros(unsigned long us)
	{
		wait_us(us);
	}
	
	//定义三个计时函数，统计程序从开始运行到结束时间，单位分别为秒，毫秒，微秒 

	unsigned long millisFromStart()
	{
		Timer T;
		T.start();
		unsigned long t = T.read_ms();
		T.stop();
		return t;
	}
	unsigned long microsFromStart()
	{
		Timer T; 
		T.start();
		unsigned long t = T.read_us();
		T.stop();
		return t;
	}		
};

typedef Mbed_Time_Time_T Mbed_Time_Time;
extern Mbed_Time_Time TL_Time;

#endif