#ifndef Grove_Mini_Fan_Fan_Arduino_UNO_H
#define Grove_Mini_Fan_Fan_Arduino_UNO_H

#include <Arduino.h>
#include "TL_Config.h"

class Grove_Mini_Fan
{
private:
  int fanPin = FAN_DIGITAL_PIN;

public:
  Grove_Mini_Fan();
  void turnOn();
  void turnOff();
};

extern Grove_Mini_Fan TL_Fan;

#endif
