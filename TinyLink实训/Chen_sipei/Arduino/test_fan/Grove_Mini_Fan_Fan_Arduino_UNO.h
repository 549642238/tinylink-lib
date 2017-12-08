#ifndef GROVE_MINI_FAN_FAN_ARDUINO_UNO_H
#define GROVE_MINI_FAN_FAN_ARDUINO_UNO_H

#include <Arduino.h>
#include "TL_Config.h"

class Grove_Mini_Fan
{
public:
    Grove_Mini_Fan();
    void TurnOn();
    void TurnOff();
};

extern Grove_Mini_Fan TL_Fan;

#endif
