#ifndef ARDUINO_FAN_FAN_ARDUINO_UNO_H
#define ARDUINO_FAN_FAN_ARDUINO_UNO_H

#include <Arduino.h>
#include "TL_Config.h"

class Internal_FAN
{

private:
  int state;
  const static int ledPin = 8;
  String comdata = "";
public:
  Internal_FAN();
  void turnOn();
  void turnOff();
   void test();
    void init();
};

extern Internal_FAN TL_FAN;

#endif
