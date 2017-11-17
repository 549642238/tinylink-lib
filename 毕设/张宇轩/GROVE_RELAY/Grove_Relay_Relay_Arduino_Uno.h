#ifndef GROVE_RELAY_RELAY_ARDUINO_UNO_H
#define GROVE_RELAY_RELAY_ARDUINO_UNO_H

#include "Controller.h"

class Grove_Relay_Relay:public Controller{
private:
	//int state;
public:
	Grove_Relay_Relay();
};

extern Grove_Relay_Relay TL_Relay;

#endif