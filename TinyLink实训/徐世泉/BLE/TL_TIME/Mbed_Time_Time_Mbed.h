#ifndef MBED_TIME_TIME_MBED_H
#define MBED_TIME_TIME_MBED_H

#include <stdio.h>
#include <stdlib.h>
#include "mbed.h"
#include "TL_Config.h"

struct Mbed_Time_Time
{
	//定义三个延时函数，分别延时s秒，ms毫秒，us微秒 
	/*
	void delay_s(unsigned long s)
	{
		wait(s);
	}
	*/
	void delayMillis(unsigned long ms)
	{
		wait_ms(ms);
	}
	void delayMicros(unsigned long us)
	{
		wait_us(us);
	}
	
	//定义三个计时函数，统计程序从开始运行到结束时间，单位分别为秒，毫秒，微秒 
	/*
	unsigned long sFromStart()
	{
		Timer T;
		T.start();
		unsigned long t = T.read();
	}
	*/
	unsigned long millisFromStart()
	{
		Timer T;
		T.start();
		unsigned long t = T.read_ms();
	}
	unsigned long microsFromStart()
	{
		Timer T; 
		T.start();
		unsigned long t = T.read_us();
	}		
};

extern struct Mbed_Time_Time TL_TIME;

#endif
