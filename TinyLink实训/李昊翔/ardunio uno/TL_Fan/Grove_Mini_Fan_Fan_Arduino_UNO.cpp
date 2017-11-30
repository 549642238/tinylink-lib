#include "Grove_Mini_Fan_Fan_Arduino_UNO.h"

Grove_Mini_Fan::Grove_Mini_Fan():fanPin(FANPIN)
{
	pinMode(fanPin, OUTPUT);
}
void Grove_Mini_Fan::turnOn()
{
  digitalWrite(fanPin, HIGH);
}
void Grove_Mini_Fan::turnOff()
{
	digitalWrite(fanPin, LOW);
}
Grove_Mini_Fan TL_Fan;//定义这个实例化对象
