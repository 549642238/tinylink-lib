#include "TL_Libraries.h"
#define BIT_LEN         0
#define BIT_START_H     1
#define BIT_START_L     2
#define BIT_DATA_H      3
#define BIT_DATA_L      4
#define BIT_DATA_LEN    5
#define BIT_DATA        6

unsigned char dtaSend[20];

void dtaInit()
{
    dtaSend[BIT_LEN]        = 11;      // all data that needs to be sent
    dtaSend[BIT_START_H]    = 179;      // the logic high duration of "Start"
    dtaSend[BIT_START_L]    = 90;     // the logic low duration of "Start"
    dtaSend[BIT_DATA_H]     = 11;     // the logic "long" duration in the communication
    dtaSend[BIT_DATA_L]     = 33;     // the logic "short" duration in the communication
    
    dtaSend[BIT_DATA_LEN]   = 6;      // Number of data which will sent. If the number is other, you should increase or reduce dtaSend[BIT_DATA+x].
    
    dtaSend[BIT_DATA+0]     = 128;      // data that will sent
    dtaSend[BIT_DATA+1]     = 127;
    dtaSend[BIT_DATA+2]     = 192;
    dtaSend[BIT_DATA+3]     = 63;
    dtaSend[BIT_DATA+4]     = 192;
    dtaSend[BIT_DATA+5]     = 63;
}
void setup() {
  // put your setup code here, to run once:
  dtaInit();
}

void loop() {
  // put your main code here, to run repeatedly:
    TL_IRSend.write(dtaSend);
    delay(2000);
}
