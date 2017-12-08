/**
 	designed by xsq
	 2017/11/1
	 changed at 2017/11/24
*/
#ifndef GROVE_MINI_FAN_FAN_ARDUINO_UNO_H
#define GROVE_MINI_FAN_FAN_ARDUINO_UNO_H

#include <Arduino.h>
#include "TL_Config.h"

class Grove_Mini_Fan
{
private:
    const static int  fanPin = 8;
public:
    Grove_Mini_Fan();
    void TurnOn();
    void TurnOff();
};

extern Grove_Mini_Fan TL_Fan;

#endif
