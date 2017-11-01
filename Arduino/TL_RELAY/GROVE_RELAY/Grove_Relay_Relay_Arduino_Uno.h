#ifndef GROVE_RELAY_RELAY_ARDUINO_UNO_H
#define GROVE_RELAY_RELAY_ARDUINO_UNO_H

class Grove_Relay_Relay{
private:
	int state;
public:
	Grove_Relay_Relay();
	void turnOn();
	void turnOff();
	void toggle();
};

extern Grove_Relay_Relay TL_Relay;

#endif