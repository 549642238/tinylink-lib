/**
 	designed by xsq
	 2017/11/1
	 changed at 2017/11/24
*/
#include "Grove_Mini_Fan_Fan_Arduino_UNO.h"

//���õ������������ 
Grove_Mini_Fan::Grove_Mini_Fan()
{
    pinMode(fanPin, OUTPUT);
}

//�򿪵�� 
void Grove_Mini_Fan::TurnOn()
{
    digitalWrite(fanPin, HIGH);
}

//�رյ�� 
void Grove_Mini_Fan::TurnOff()
{
    digitalWrite(fanPin, LOW);
}

Grove_Mini_Fan TL_Fan;
