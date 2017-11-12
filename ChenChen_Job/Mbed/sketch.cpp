#include "TL_Libraries.h"

void setup(){
	 TL_Bluetooth.init();
}

void loop(){
	TL_Time.delayMillis(1000);
	if(TL_BUTTON.read() == PRESSED)
	{
		TL_LED.turnOn();
	}
	else if(TL_BUTTON.read() == RELEASED)
	{
		TL_LED.turnOff();
	}
	if(LedState == 1)
	{
		TL_LED.turnOn();
	}
	else 
	{
		TL_LED.turnOff();
	}
	// TL_Bluetooth.send("Hello world\0");
}
