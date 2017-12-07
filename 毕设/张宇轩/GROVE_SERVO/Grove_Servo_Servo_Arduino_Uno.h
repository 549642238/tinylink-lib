#ifndef GROVE_Servo_Servo_ARDUINO_UNO_H
#define GROVE_Servo_Servo_ARDUINO_UNO_H

#include <Servo.h>
#include "Sensor_template.h"
#include "Writer.h"

class Grove_Servo_Servo:public Sensor<int>,public Writer<int>{
private:
	Servo myservo;
	int _read();
public:
	Grove_Servo_Servo();
    void init();
	void write(int pos);
};

extern Grove_Servo_Servo TL_Servo;

#endif