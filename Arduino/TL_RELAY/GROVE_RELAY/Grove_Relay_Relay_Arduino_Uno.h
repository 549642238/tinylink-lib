#ifndef GROVE_RELAY_RELAY_ARDUINO_UNO_H
#define GROVE_RELAY_RELAY_ARDUINO_UNO_H

class Grove_Relay_Relay_Arduino_Uno{
private:
	int stateSig;
public:
	Grove_Relay_Relay_Arduino_Uno();
	void turnOn();
	void turnOff();
	void toggle();
	const int state();
};

extern Grove_Relay_Relay_Arduino_Uno TL_Relay;

#endif
