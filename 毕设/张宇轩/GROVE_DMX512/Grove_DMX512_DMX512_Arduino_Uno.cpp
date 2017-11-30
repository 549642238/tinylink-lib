#include <Arduino.h>
#include "TL_Config.h"
#include "Grove_DMX512_DMX512_Arduino_Uno.h"

Grove_DMX512_DMX512::Grove_DMX512_DMX512(){
	myDmx.usePin(DMX512_DIGITAL_OUTPUT);
}

void Grove_DMX512_DMX512::write(int channel, uint8_t value)
{	
	myDmx.write(channel,value);
}

Grove_DMX512_DMX512 TL_DMX512;