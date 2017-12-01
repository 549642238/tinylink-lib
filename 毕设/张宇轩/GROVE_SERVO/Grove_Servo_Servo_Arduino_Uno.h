#ifndef GROVE_Servo_Servo_ARDUINO_UNO_H
#define GROVE_Servo_Servo_ARDUINO_UNO_H

#include <Servo.h>
#include "Writer.h"

class Grove_Servo_Servo:public Writer<int>{
private:
	Servo myservo;
public:
	Grove_Servo_Servo();
	void write(int pos);
	int read();
};

extern Grove_Servo_Servo TL_Servo;

#endif