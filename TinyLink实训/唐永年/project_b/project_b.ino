#include "TL_Libraries.h"
void setup() {
    TL_FAN.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  TL_FAN.work();
}
