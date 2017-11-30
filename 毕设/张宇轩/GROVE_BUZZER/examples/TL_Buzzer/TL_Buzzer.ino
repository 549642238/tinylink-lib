#include "TL_Libraries.h"
void setup() {
  // put your setup code here, to run once:
}

void loop() {  
  // put your main code here, to run repeatedly:
  TL_Buzzer.toggle();   //蜂鸣器发出间隔一秒的滴滴的响声
  delay(1000);
}
