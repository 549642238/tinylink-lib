#include "TL_Libraries.h"
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    int brightness;
    TL_DMX512.write(2,0);  
    TL_DMX512.write(3,0);
    TL_DMX512.write(4,0);  
    TL_DMX512.write(5,0);  
    TL_DMX512.write(6,0);    
    if(Serial.available())
    {
      char c=Serial.read();
      if(c=='2')     
      {
         Serial.println("red light test");
         for (brightness = 0; brightness <= 255; brightness++)
          {
            TL_DMX512.write(2,brightness);  //Channel 2 to control red light 
            delay(5);
          }
      }
      else if(c=='3')
      {
        Serial.println("green light and purple light test");
        for (brightness = 0; brightness <= 255; brightness++)
          {
            TL_DMX512.write(3,brightness);  //Channel 3 to control green light and purple light 
            delay(5);
          }
      }
        else if(c=='4')
      {
         Serial.println("blue light test");
         for (brightness = 0; brightness <= 255; brightness++)
          {
            TL_DMX512.write(4,brightness);  //Channel 4 to Control blue light 
            delay(5);
          }
      }
        else if(c=='5')
      {
         Serial.println("motor test");
         for (brightness = 0; brightness <= 255; brightness++)
          {
            TL_DMX512.write(2,100); 
            TL_DMX512.write(5,brightness);  //Channel 5 to control motor
            delay(5);
          }
      }
        else if(c=='6')
      {
         Serial.println("comprehensive test");
         TL_DMX512.write(6,255);  //Channel 6 is comprehensive test
         delay(20000);
      }
    }
}
