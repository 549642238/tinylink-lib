#ifndef GROVE_DMX512_DMX512_ARDUINO_UNO_H
#define GROVE_DMX512_DMX512_ARDUINO_UNO_H

#include <DmxSimple.h>

class Grove_DMX512_DMX512{
private:
	DmxSimpleClass myDmx;
public:
	Grove_DMX512_DMX512();
	void write(int channel, uint8_t value);
};

extern Grove_DMX512_DMX512 TL_DMX512;

#endif