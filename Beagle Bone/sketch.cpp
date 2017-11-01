#include "Arduino.h"

void setup(){
}

void loop(){
	TL_Time.delayMillis(1000);
	TL_Temperature.read();
	double temperature = TL_Temperature.data();
	cout << "Temperature: " <<  temperature << endl;

	TL_Time.delayMillis(1000);
	TL_Light.read();
	double light = TL_Light.data();
	cout << "Light: " <<  light << endl;
}
