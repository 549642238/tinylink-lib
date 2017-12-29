#include "BBB_MOTOR_MOTOR_BBB.h"


MOTOR::MOTOR(Pin pin){ 
    this->pin = pin;
    status = 0;
}

void MOTOR::turnOn(){ 
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
}

void MOTOR::turnOff(){ 
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
}

bool MOTOR::state(){
    return digitalRead(pin);
}
