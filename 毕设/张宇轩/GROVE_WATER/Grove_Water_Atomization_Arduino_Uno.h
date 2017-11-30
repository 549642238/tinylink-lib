#ifndef Grove_Water_Atomization_ARDUINO_UNO_H
#define Grove_Water_Atomization_ARDUINO_UNO_H

#include "Controller.h"

class Grove_Water_Atomization:public Controller{
public:
	Grove_Water_Atomization();
};

extern Grove_Water_Atomization TL_Atomization;

#endif