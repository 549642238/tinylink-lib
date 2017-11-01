#include "DHT11_RPI.h"
#include "grovepi.h"


namespace tinylink {
DHT11Sensor::DHT11Sensor(int pin){
	_tem = _hum = .0;
    _pin = pin;
    if (init() == -1) exit(-1);
}


int DHT11Sensor::read(){
	pair<float, float> result = dht(_pin);
    _tem = result.first; 
    _hum = result.second;	
	return 0;
}
}
