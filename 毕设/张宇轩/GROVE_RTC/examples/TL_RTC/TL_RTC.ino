#include "TL_Libraries.h"
struct time _time={20,53,31,2018,12,2,SAT};  
struct time *nowtime=&_time;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  TL_RTC.write(nowtime);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(TL_RTC.read()!=-1){
    nowtime=TL_RTC.data();
    Serial.print(nowtime->hour);
    Serial.print(":");
    Serial.print(nowtime->minute);
    Serial.print(":");
    Serial.print(nowtime->second);
    Serial.print("  ");
    Serial.print(nowtime->year, DEC);
    Serial.print("/");
    Serial.print(nowtime->month, DEC);
    Serial.print("/");
    Serial.print(nowtime->dayOfMonth, DEC);
    Serial.print(" ");
    Serial.print(nowtime->dayOfMonth);
    Serial.print("*");
    switch (nowtime->dayOfWeek)// Friendly printout the weekday
    {
      case MON:
        Serial.print("MON");
        break;
      case TUE:
        Serial.print("TUE");
        break;
      case WED:
        Serial.print("WED");
        break;
      case THU:
        Serial.print("THU");
        break;
      case FRI:
        Serial.print("FRI");
        break;
      case SAT:
        Serial.print("SAT");
        break;
      case SUN:
        Serial.print("SUN");
        break;
    }
    Serial.println(" ");
    delay(200);
  }
}
