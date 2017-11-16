#ifndef ARDUINO_FAN_FAN_ARDUINO_UNO_H
#define ARDUINO_FAN_FAN_ARDUINO_UNO_H

#include <Arduino.h>
#include "TL_Config.h"

class Arduino_Fan
{
private:
    const static int fanPin = FAN_DIGITAL_PIN;
public:
    Arduino_Fan();
    void TurnOn();
    void TurnOff();
};

extern Arduino_Fan TL_Fan;

#endif
