#ifndef Grove_Button_Button_ARDUINO_UNO_H
#define Grove_Button_Button_ARDUINO_UNO_H

#include "Switch.h"

class Grove_Button_Button:public Switch{
public:
	Grove_Button_Button();
};

extern Grove_Button_Button TL_Button;

#endif