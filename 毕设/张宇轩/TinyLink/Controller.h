#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller  {
protected:
	int _pin;
	int _state;
public:
	Controller(int pin): _state(0), _pin(pin) {
		pinMode(_pin, OUTPUT);
	}
	void turnOn(){
		_state = 1;
		digitalWrite(_pin, HIGH);
	}

	void turnOff(){
		_state = 0;
		digitalWrite(_pin, LOW);
	}
	void toggle(){
		if(_state == 0){
			_state = 1;
			digitalWrite(_pin, HIGH);
		}else{
			_state = 0;
			digitalWrite(_pin, LOW);
		}
	}
};

#endif
