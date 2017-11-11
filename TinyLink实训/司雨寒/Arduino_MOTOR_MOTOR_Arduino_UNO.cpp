#include "Arduino_MOTOR_MOTOR_Arduino_UNO.h"

void Motor::init() {
	Serial.begin(9600);
	pinMode(motorPin, OUTPUT);
	digitalWrite(motorPin, LOW);
}

void Motor::on() {
	digitalWrite(motorPin, HIGH);
}

void Motor::off() {
	digitalWrite(motorPin, LOW);
}

void Motor::work() {
	while(Serial.available() > 0) {
		char c = Serial.read();
		cmd += c;
		delay(2);
	}
	if(cmd.length() > 0) {
		Serial.println(cmd);
		if(cmd == "on") {
			digitalWrite(motorPin, HIGH);
		} else if(cmd == "off") {
    		digitalWrite(motorPin, LOW);
		}
		cmd = "";
	}
}

Motor TL_MOTOR;
