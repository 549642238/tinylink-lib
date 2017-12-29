#ifndef BBB_MOTOR_MOTOR_BBB_H
#define BBB_MOTOR_MOTOR_BBB_H

#include <iostream> 
#include <fstream> 
#include <string> 
#include <sstream>
#include <cstdio>
#include "CommonDefines.h"
#include "GPIO.h"
#include "OVERLAY.h"
#include "TL_Config.h"

using namespace std;


class MOTOR { 
private: 
    Pin pin;
    bool status;
public: 
    MOTOR(Pin pin); 
    virtual void turnOn(); 
    virtual void turnOff(); 
    virtual bool state();
};

extern MOTOR TL_Motor;

#endif
