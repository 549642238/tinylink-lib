#ifndef ARDUINO_FAN_FAN_ARDUINO_UNO_H
#define ARDUINO_FAN_FAN_ARDUINO_UNO_H

#include <Arduino.h>
#include "TL_Config.h"

class Internal_FAN
{
private:
  String res;
  const static int fanPin = 8;

public:
  void init();
  void work();
  void turnOn();
  void turnOff();
};

extern Internal_FAN TL_FAN;

#endif
