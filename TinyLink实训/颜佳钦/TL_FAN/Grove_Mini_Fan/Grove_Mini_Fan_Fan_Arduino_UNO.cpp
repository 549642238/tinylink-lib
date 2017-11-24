#include "Grove_Mini_Fan_Fan_Arduino_UNO.h"

//初始化pin脚
Grove_Mini_Fan::Grove_Mini_FAN()
{
  pinMode(ledPin, OUTPUT);
  state = 0;
}

//开启电机
void Grove_Mini_Fan::turnOn()
{
  state = 1;
  digitalWrite(ledPin, HIGH);
}
//关闭电机
void Grove_Mini_Fan::turnOff()
{
  state = 0;
  digitalWrite(ledPin, LOW);
}
//定义实例化对象
Grove_Mini_Fan TL_FAN;
