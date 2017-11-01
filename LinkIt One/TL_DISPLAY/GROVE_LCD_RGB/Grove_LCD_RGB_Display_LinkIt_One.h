#ifndef GROVE_LCD_RGB_DISPLAY_LINKIT_ONE.h
#define GROVE_LCD_RGB_DISPLAY_LINKIT_ONE.h

#include "rgb_lcd.h"

class GROVE_LCD_RGB_DISPLAY{
private:
	int state;
	rgb_lcd lcd;
public:
	GROVE_LCD_RGB_DISPLAY();
	void show(const char* data);
	void show(const String& data);
	void clear();
};

extern GROVE_LCD_RGB_DISPLAY TL_Display;

#endif
