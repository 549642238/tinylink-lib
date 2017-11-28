#ifndef _74HC595_ARDUINO_UNO_H
#define _74HC595_ARDUINO_UNO_H

class _74HC595_SERIAL_TO_PARALLEL{
private:
public:
	_74HC595_SERIAL_TO_PARALLEL();
	void pinOut(int value);
};

extern _74HC595_SERIAL_TO_PARALLEL TL_74HC595;

#endif