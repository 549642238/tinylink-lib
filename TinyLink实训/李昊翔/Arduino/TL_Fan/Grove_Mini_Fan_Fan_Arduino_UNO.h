#ifndef GROVE_MINI_FAN_FAN_ARDUINO_UNO_H
#define GROVE_MINI_FAN_FAN_ARDUINO_UNO_H

#include <Arduino.h>
#include "TL_Config.h"


#if FAN == GROVE_MINI_FAN
	#define FANPIN FAN_DIGITAL_PIN
#endif 

class Grove_Mini_Fan
{
private:
	uint8_t  fanPin;//pin to use
public:
	Grove_Mini_Fan();//constructed function:init the pin
	void turnOn();//turn on the fan
	void turnOff();//turn off the fan
};
extern Grove_Mini_Fan TL_Fan;

#endif
