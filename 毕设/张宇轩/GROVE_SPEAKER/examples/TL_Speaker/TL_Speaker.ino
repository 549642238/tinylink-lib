#include "TL_Libraries.h"
int a[]={1911,1803,1702,1607,1516,1431,1351,1275,1203,1136,1072,1012};  //不同的频率
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
    for(int index=1;index<=7;index++)     
    {
        TL_Speaker.sound(index);                //发音符1-7的声
        delay(500);
    }
    int len=sizeof(a)/sizeof(a[0]);
    for(int index=0;index<len;index++)
    {
        TL_Speaker.write(a[index]);         //根据频率发声
        delay(100);
    }
}
