#ifndef MBED_TIME_TIME_MBED_H
#define MBED_TIME_TIME_MBED_H

#include <stdio.h>
#include <stdlib.h>
#include "mbed.h"
#include "TL_Config.h"
//构造函数:给成员变量赋值
class Mbed_Time_Time_T {
public:
    Mbed_Time_Time_T() {
    }
	unsigned long millisFromStart(){
			Timer timer;
			timer.start();
			unsigned long t = timer.read_ms();
			timer.stop();
			return t;
	}
	unsigned long microsFromStart(){
			Timer timer;
			timer.start();
			unsigned long t = timer.read_us();
			timer.stop();
			return t;
	}
	void delayMillis(unsigned long ms){
			wait_ms(ms);
	}
	void delayMicros(unsigned long us){
			wait_us(us);
	}	
};
typedef Mbed_Time_Time_T Mbed_Time_Time;
extern Mbed_Time_Time TL_Time;

#endif
