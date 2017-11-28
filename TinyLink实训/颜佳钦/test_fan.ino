#include"Grove_Mini_Fan_Fan_Arduino_UNO.h"

void setup() {
}

void loop() {
  
  TL_Fan.turnOn();
  delay(5000);
  TL_Fan.turnOff();
  delay(5000);
}
