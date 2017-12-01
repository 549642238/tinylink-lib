#include <Arduino.h>
#include "TL_Config.h"
#include "Grove_Servo_Servo_Arduino_Uno.h"

Grove_Servo_Servo::Grove_Servo_Servo(){
	myservo.attach(SERVO_DIGITAL_OUTPUT);
}

void Grove_Servo_Servo::write(int pos)
{	
	myservo.write(pos);
}

int Grove_Servo_Servo::read()
{	
	return myservo.read();
}

Grove_Servo_Servo TL_Servo;