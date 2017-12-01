#include "DHT11_Temperature_LinkIt_One.h"

DHT11_Temperature_LinkIt_One::DHT11_Temperature_LinkIt_One():Sensor(0.0), DHT11Temp(TEMPERATURE_DIGITAL_OUTPUT, DHT11_SENSOR){
	DHT11Temp.begin();
}

int DHT11_Temperature_LinkIt_One::_read(){
	double chk = (double)DHT11Temp.readTemperature();
	if (!isnan(chk)){
		_data = chk;
		return 0;
	}
	return -1;
}

DHT11_Temperature_LinkIt_One TL_Temperature;
