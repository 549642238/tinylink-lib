#ifndef ARDUINO_MOTOR_MOTOR_ARDUINO_UNO_H
#define ARDUINO_MOTOR_MOTOR_ARDUINO_UNO_H

#include <Arduino.h>
#include "TL_Config.h"

class Internal_MOTOR
{

private:
  const static int  motorPin = 8;//连接用的引脚
public:
	Internal_MOTOR();//构造函数
	void turnOn();//开启电机
	void turnOff();//关闭电机
	/*
		测试程序：
		1）功能：从串口输入“on”使得电机开启 / 从串口输入"off"使得电机关闭
		2）调试情况：还未完全正确
			a一开始必须等一会儿才能输入命令，不然没效果
			b大致正确，但仍会出现有些时候输入on、off都不行，这时候需要等一会才可以继续
		3)猜测：
			a有可能是因为电机本身连线被我动了，接触不良导致不行
	*/
	void test();
};
extern Internal_MOTOR TL_MOTOR;//声明一个实例化对象

#endif
