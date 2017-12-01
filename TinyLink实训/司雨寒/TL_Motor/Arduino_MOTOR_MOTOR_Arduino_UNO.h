#ifndef ARDUINO_MOTOR_MOTOR_ARDUINO_UNO_H
#define ARDUINO_MOTOR_MOTOR_ARDUINO_UNO_H
#include <Arduino.h>
#include "TL_Config.h"
class Motor {
private:
	int motorPin = MOTOR_DIGITAL_PIN;

public:
	void on();
	void off();
};

extern Motor TL_MOTOR;

#endif
