#ifndef ARDUINO_MOTOR_MOTOR_ARDUINO_UNO_H
#define ARDUINO_MOTOR_MOTOR_ARDUINO_UNO_H
#include <Arduino.h>
class Motor {
private:
	const static int motorPin = 8;
	String cmd;

public:
	void init();
	void on();
	void off();
	void work();
};

extern Motor TL_MOTOR;

#endif
