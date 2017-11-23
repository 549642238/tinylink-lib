#include"Grove_Mini_Fan_Fan_Arduino_UNO.h"

void setup() {
}

void loop() {
  // put your main code here, to run repeatedly:
  TL_Fan.TurnOn();
  delay(5000);
  TL_Fan.TurnOff();
  delay(5000);
}
