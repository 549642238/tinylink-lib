#include "Grove_Mini_Motor_Motor_Arduino_UNO.h"

Grove_Mini_Motor::Grove_Mini_Motor():stateSig(0)
{
    pinMode(MOTOR_DIGITAL_PIN, OUTPUT);
}

void Grove_Mini_Motor::turnOn()
{
    digitalWrite(MOTOR_DIGITAL_PIN, HIGH);
    stateSig=1;
}

void Grove_Mini_Motor::turnOff()
{
    digitalWrite(MOTOR_DIGITAL_PIN, LOW);
    stateSig=0;
}

int Grove_Mini_Motor::state()
{
    return stateSig;
}
Grove_Mini_Motor TL_Motor;
