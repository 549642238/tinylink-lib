#include <Arduino.h>
#include "TL_Config.h"
#include "Grove_Servo_Servo_Arduino_Uno.h"

Grove_Servo_Servo::Grove_Servo_Servo():Sensor(0){
	
}

void Grove_Servo_Servo::init()
{	
	myservo.attach(SERVO_DIGITAL_OUTPUT);
}


void Grove_Servo_Servo::write(int pos)
{	
	myservo.write(pos);
}

int Grove_Servo_Servo::_read()
{	
	int pos=myservo.read();
	if(pos>=0&&pos<=180){
		_data=pos;
		return 0;
	}
	return -1;
}

Grove_Servo_Servo TL_Servo;