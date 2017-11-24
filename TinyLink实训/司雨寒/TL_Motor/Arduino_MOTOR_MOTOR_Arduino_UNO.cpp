#include "Arduino_MOTOR_MOTOR_Arduino_UNO.h"

void Motor::on() {
	digitalWrite(motorPin, HIGH);
}

void Motor::off() {
	digitalWrite(motorPin, LOW);
}

Motor TL_MOTOR;
