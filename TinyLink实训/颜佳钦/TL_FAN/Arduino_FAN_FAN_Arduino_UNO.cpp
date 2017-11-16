#include "Arduino_FAN_FAN_Arduino_UNO.h"


Internal_FAN::Internal_FAN()
{
  pinMode(ledPin, OUTPUT);
  state = 0;
}
void Internal_FAN::init()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  state = 0;
}
void Internal_FAN::test()
{
 while (Serial.available() > 0)  
    {
        comdata += char(Serial.read());
        delay(2);
    }
    if (comdata.length() > 0)
    {
      if(comdata=="on")
      {
        turnOn(); 
        comdata = "";
      }
      else if(comdata=="off")
      {
        turnOff(); 
         comdata = "";
      }
      else {
        comdata="";
        }
    }
}

void Internal_FAN::turnOn()
{
  state = 1;
  digitalWrite(ledPin, HIGH);
}

void Internal_FAN::turnOff()
{
  state = 0;
  digitalWrite(ledPin, LOW);
}

Internal_FAN TL_FAN;
