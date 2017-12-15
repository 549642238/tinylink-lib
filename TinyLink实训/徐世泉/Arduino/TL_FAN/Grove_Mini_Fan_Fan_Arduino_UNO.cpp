/**
 	designed by xsq
	 2017/11/1
	 changed at 2017/11/24
*/
#include "Grove_Mini_Fan_Fan_Arduino_UNO.h"

//设置电机的驱动引脚 
Grove_Mini_Fan::Grove_Mini_Fan()
{
    pinMode(fanPin, OUTPUT);
}

//打开电机 
void Grove_Mini_Fan::TurnOn()
{
    digitalWrite(fanPin, HIGH);
}

//关闭电机 
void Grove_Mini_Fan::TurnOff()
{
    digitalWrite(fanPin, LOW);
}

Grove_Mini_Fan TL_Fan;
