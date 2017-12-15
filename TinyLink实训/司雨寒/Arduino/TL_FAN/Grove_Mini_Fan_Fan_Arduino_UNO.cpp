#include "Grove_Mini_Fan_Fan_Arduino_UNO.h"

Grove_Mini_Fan::Grove_Mini_Fan() {
	pinMode(FAN_DIGITAL_PIN, OUTPUT);
}

void Motor::on() {
	digitalWrite(FAN_DIGITAL_PIN, HIGH);
}

void Motor::off() {
	digitalWrite(FAN_DIGITAL_PIN, LOW);
}

Grove_Mini_Fan TL_Fan;
