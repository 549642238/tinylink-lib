#include "Arduino_MOTOR_MOTOR_Arduino_UNO.h"

void setup() {

}

void loop() {
	TL_Motor.on();
	delay(1000);
	TL_Motor.off();
	delay(1000);
}
