#include <Arduino.h>
#include "TL_Config.h"
#include "Grove_Relay_Relay_Arduino_Uno.h"

Grove_Relay_Relay::Grove_Relay_Relay():Controller(RELAY_DIGITAL_OUTPUT){
	//pinMode(RELAY_DIGITAL_OUTPUT, OUTPUT);
}

Grove_Relay_Relay TL_Relay;