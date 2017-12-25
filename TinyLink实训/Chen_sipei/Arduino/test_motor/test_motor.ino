#include "Grove_Mini_Motor_Motor_Arduino_UNO.h"

void setup() {
}

void loop() {
    TL_Motor.turnOn();
    printf("%d\n",TL_Motor.state());
    delay(2000);
    TL_Motor.turnOff();
    printf("%d\n",TL_Motor.state());
    delay(2000);
}
