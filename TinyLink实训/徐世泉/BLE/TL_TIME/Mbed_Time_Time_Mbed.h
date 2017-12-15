#ifndef MBED_TIME_TIME_MBED_H
#define MBED_TIME_TIME_MBED_H

#include <stdio.h>
#include <stdlib.h>
#include "mbed.h"
#include "TL_Config.h"

struct Mbed_Time_Time
{
	//����������ʱ�������ֱ���ʱs�룬ms���룬us΢�� 
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
	
	//����������ʱ������ͳ�Ƴ���ӿ�ʼ���е�����ʱ�䣬��λ�ֱ�Ϊ�룬���룬΢�� 
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
