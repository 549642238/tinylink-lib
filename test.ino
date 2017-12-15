#include "TL_Libraries.h"

void on(){
  TL_LED.turnOn();
}

void off(){
  TL_LED.turnOff();
}

void toggle(){
  TL_LED.toggle();
}

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  on();       //  test on
  // off();   //  test off
  // toggle();//  test toggle
  TL_Time.delayMillis(1000);
}

