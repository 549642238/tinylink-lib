#ifndef MBED_BUTTON_BUTTON_MBED_H
#define MBED_BUTTON_BUTTON_MBED_H
#include <stdio.h>
#include <stdlib.h>
#include "mbed.h"
#include "TL_Config.h"
	enum {
    RELEASED = 0,
    PRESSED,
    IDLE
	};
//构造函数:给成员变量赋值
class Mbed_Button_Button_T {
public:
    Mbed_Button_Button_T():button(p17){
    }

	int read(){
		return button.read();
	}
protected:
	DigitalIn button;
};
typedef Mbed_Button_Button_T Mbed_Button_Button;
extern Mbed_Button_Button TL_BUTTON;

#endif
