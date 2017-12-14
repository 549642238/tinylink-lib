#include "Grove_Mini_Fan_Fan_Arduino_UNO.h"

//初始化pin脚
Grove_Mini_Fan::Grove_Mini_Fan()
{
	pinMode(FAN_DIGITAL_PIN,OUTPUT);
}
//开启电机
void Grove_Mini_Fan::turnOn()
{
	digitalWrite(FAN_DIGITAL_PIN, HIGH);
}
//关闭电机
void Grove_Mini_Fan::turnOff()
{
	digitalWrite(FAN_DIGITAL_PIN, LOW);
}
//定义实例化对象
Grove_Mini_Fan TL_Fan;
