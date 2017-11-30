#ifndef Grove_Mini_Fan_Relay_ARDUINO_UNO_H
#define Grove_Mini_Fan_Relay_ARDUINO_UNO_H

#include "Controller.h"

class Grove_Mini_Fan_Relay:public Controller{
public:
	Grove_Mini_Fan_Relay();
};

extern Grove_Mini_Fan_Relay TL_Relay;

#endif