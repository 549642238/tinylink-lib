#include <Arduino.h>
#include <Wire.h>
#include "TL_Config.h"
#include "Grove_LCD_RGB_Display_LinkIt_One.h"

GROVE_LCD_RGB_DISPLAY::GROVE_LCD_RGB_DISPLAY():state(0){
}

void GROVE_LCD_RGB_DISPLAY::show(const char* data){
	if(state == 0){
		lcd.begin(16, 2);
		//lcd.setRGB(255, 0, 0);
		lcd.print("hello, master!");
		delay(500);
		state = 1;
	}
	lcd.print(data);
}

void GROVE_LCD_RGB_DISPLAY::show(const String& data){
	if(state == 0){
		lcd.begin(16, 2);
		//lcd.setRGB(255, 0, 0);
		lcd.print("hello, master!");
		delay(500);
		state = 1;
	}
	lcd.print(data);
}

void GROVE_LCD_RGB_DISPLAY::clear(){
	if(state == 0){
		lcd.begin(16, 2);
		//lcd.setRGB(255, 0, 0);
		lcd.print("hello, master!");
		delay(500);
		state = 1;
	}
	lcd.clear();
}

GROVE_LCD_RGB_DISPLAY TL_Display;
