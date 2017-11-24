#include"Grove_Mini_Fan_Fan_Arduino_UNO.h"

void setup() {
}

void loop() {
  
  TL_FAN.turnOn();
  delay(5000);
  TL_FAN.turnOff();
  delay(5000);
}
