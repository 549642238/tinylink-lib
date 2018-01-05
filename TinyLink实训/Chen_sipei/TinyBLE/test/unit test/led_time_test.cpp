#include "TL_Libraries.h"

void setup(){
}

void loop(){
	TL_Time.delayMillis(1000);
	TL_LED.toggle();
	TL_Time.delayMicros(1000000);
	TL_LED.turnOn();
	TL_Time.delayMillis(1000);
	TL_LED.turnOn();
	TL_Time.millisFromStart();
}
