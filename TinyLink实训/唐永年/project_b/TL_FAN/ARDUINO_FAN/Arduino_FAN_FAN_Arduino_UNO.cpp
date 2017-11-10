#include "Arduino_FAN_FAN_Arduino_UNO.h"

void Internal_FAN::init()
{
  Serial.begin(9600);
  pinMode(fanPin, OUTPUT);
  res="";
}

void Internal_FAN::work()
{
	while(Serial.available()>0){
		char ch = Serial.read();
		if(ch == '\n'){
			if(res == "on"){
			digitalWrite(fanPin, HIGH);
		}else if(res == "off"){
			digitalWrite(fanPin, LOW);
		}
		res = "";
    }else {
		res += ch;
    }
    delay(500);
  }
}

void Internal_FAN::turnOn()
{
  digitalWrite(fanPin, HIGH);
}

void Internal_FAN::turnOff()
{
  digitalWrite(fanPin, LOW);
}

Internal_FAN TL_FAN;
