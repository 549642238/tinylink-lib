#ifndef GROVE_MINI_FAN_FAN_ARDUINO_UNO_H
#define GROVE_MINI_FAN_FAN_ARDUINO_UNO_H


#include <Arduino.h>
#include "TL_Config.h"

class GROVE_MINI_FAN
{

private:
  int state;
  const static int  int ledPin = FAN_DIGITAL_PIN;
public:
  GROVE_MINI_FAN();
  void turnOn();
  void turnOff();
 
};

extern GROVE_MINI_FAN TL_FAN;//声明实例化对象

#endif
