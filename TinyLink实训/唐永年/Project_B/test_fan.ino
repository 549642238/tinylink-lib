#include "TL_Libraries.h"

void setup() {
}

void loop() {
  // put your main code here, to run repeatedly:
  TL_Fan.Turn_On();
  delay(5000);
  TL_Fan.Turn_Off();
  delay(5000);
}
