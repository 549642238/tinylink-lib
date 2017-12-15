#include "TL_Libraries.h"
void setup() {
  // put your setup code here, to run once:
 
}

void loop() {
  // put your main code here, to run repeatedly:
    if(TL_Button.indentify())      //按键按下
    {
        TL_Relay.turnOn();   //继电器打开，风扇开转
    }
    else
    {
        TL_Relay.turnOff();  //继电器关闭，风扇停转
    }
}
