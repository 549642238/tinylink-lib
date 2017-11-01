#include <Arduino.h>
#include "TL_Config.h"
#include "Grove_Relay_Relay_Arduino_Uno.h"

Grove_Relay_Relay::Grove_Relay_Relay():state(0){
	pinMode(RELAY_DIGITAL_OUTPUT, OUTPUT);
}

void Grove_Relay_Relay::turnOn(){
	state = 1;
	digitalWrite(RELAY_DIGITAL_OUTPUT, HIGH);
}

void Grove_Relay_Relay::turnOff(){
	state = 0;
	digitalWrite(RELAY_DIGITAL_OUTPUT, LOW);
}

void Grove_Relay_Relay::toggle(){
	if(state == 0){
		state = 1;
		digitalWrite(RELAY_DIGITAL_OUTPUT, HIGH);
	}else{
		state = 0;
		digitalWrite(RELAY_DIGITAL_OUTPUT, LOW);
	}
}

Grove_Relay_Relay TL_Relay;