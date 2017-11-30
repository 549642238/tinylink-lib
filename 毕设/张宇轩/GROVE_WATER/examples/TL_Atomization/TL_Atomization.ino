#include "TL_Libraries.h"
void setup() {
  // put your setup code here, to run once:
 
}

void loop() {
  // put your main code here, to run repeatedly:
    if(TL_Button.indentify())      //按键按下
    {
        TL_Atomization.turnOn();   //开始雾化
    }
    else
    {
        TL_Atomization.turnOff();  //停止雾化
    }
}
