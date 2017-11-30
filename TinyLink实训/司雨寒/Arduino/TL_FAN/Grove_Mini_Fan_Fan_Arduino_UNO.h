#ifndef ARDUINO_MOTOR_MOTOR_ARDUINO_UNO_H
#define ARDUINO_MOTOR_MOTOR_ARDUINO_UNO_H
#include <Arduino.h>
#include "TL_Config.h"

class Grove_Mini_Fan {
public:
	Grove_Mini_Fan();
	void on();
	void off();
};

extern Grove_Mini_Fan TL_Fan;

#endif
