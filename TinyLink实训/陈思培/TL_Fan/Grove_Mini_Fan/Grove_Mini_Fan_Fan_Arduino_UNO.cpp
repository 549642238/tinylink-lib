#include "Arduino_Fan_Fan_Arduino_UNO.h"

Arduino_Fan::Arduino_Fan()
{
    pinMode(fanPin, OUTPUT);
}

void Arduino_Fan::TurnOn()
{
    digitalWrite(fanPin, HIGH);
}

void Arduino_Fan::TurnOff()
{
    digitalWrite(fanPin, LOW);
}


Arduino_Fan TL_Fan;
