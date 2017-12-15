#ifndef GROVE_MINI_MOTOR_MOTOR_ARDUINO_UNO_H
#define GROVE_MINI_MOTOR_MOTOR_ARDUINO_UNO_H

#include <Arduino.h>
#include "TL_Config.h"

class Grove_Mini_Motor
{
    private:
        int stateSig;
    public:
        Grove_Mini_Motor();
        void turnOn();
        void turnOff();
        int state();
};

extern Grove_Mini_Motor TL_Motor;

#endif
