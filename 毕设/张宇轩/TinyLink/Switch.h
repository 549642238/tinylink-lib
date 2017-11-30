#ifndef SWITCH_H
#define SWITCH_H

class Switch  {
protected:
	int _pin;
public:
	Switch(int pin): _pin(pin) {
		pinMode(_pin, INPUT);
	}
	int indentify(){
		return digitalRead(_pin);
	}
};

#endif
