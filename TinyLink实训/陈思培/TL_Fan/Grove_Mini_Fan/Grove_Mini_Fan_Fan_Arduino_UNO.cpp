#include "Grove_Mini_Fan_Fan_Arduino_UNO.h"

Grove_Mini_Fan::Grove_Mini_Fan()
{
    pinMode(fanPin, OUTPUT);
}

void Grove_Mini_Fan::TurnOn()
{
    digitalWrite(fanPin, HIGH);
}

void Grove_Mini_Fan::TurnOff()
{
    digitalWrite(fanPin, LOW);
}

Grove_Mini_Fan TL_Fan;
