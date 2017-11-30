#include "Arduino_MOTOR_MOTOR_Arduino_UNO.h"

void setup() {

}

void loop() {
	TL_Fan.on();
	delay(1000);
	TL_Fan.off();
	delay(1000);
}
