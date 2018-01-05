#include <stdio.h>
#include <stdlib.h>
#include "Mbed_Time_Time_Mbed.h"

void Mbed_Time_Time_T::delayMillis(unsigned long ms)
{
	wait_ms(ms);
}

void Mbed_Time_Time_T::delayMicros(unsigned long us)
{
	wait_us(us);
}
	
	//����������ʱ������ͳ�Ƴ���ӿ�ʼ���е�����ʱ�䣬��λ�ֱ�Ϊ�룬���룬΢�� 

unsigned long Mbed_Time_Time_T::millisFromStart()
{
	Timer T;
	T.start();
	unsigned long t = T.read_ms();
	T.stop();
	return t;
}
unsigned long Mbed_Time_Time_T::microsFromStart()
{
	Timer T; 
	T.start();
	unsigned long t = T.read_us();
	T.stop();
	return t;
}

Mbed_Time_Time TL_Time;
