#include "TL_Libraries.h"
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
    if(TL_Button.indentify())   //按键按下
    {
      TL_Buzzer.turnOn();       //蜂鸣器响
    }
    else                        //按键没按下
    {
      TL_Buzzer.turnOff();      //蜂鸣器不响
    }
}
