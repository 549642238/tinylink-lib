


/**********************************************************************************
   * 情况1：
   *    间断执行TL_MOTOR.turnOn以及TL_MOTOR.turnOff()，结果是两个函数都有效果
   *    
  **********************************************************************************/
/*
#include "TL_Libraries.h"
#define num 3
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
void loop(){
   // put your main code here, to run repeatedly:
         TL_MOTOR.turnOn();
         delay(1000);
         TL_MOTOR.turnOff();
         delay(1000);
  }
  */
  /**********************************************************************************
   * 情况2：
   *    自己直接写了一个类，达到了运行的效果
   *    
  **********************************************************************************/
  /*
  #define num 3
 class Internal_MOTOR{
    public:
      void turnOn(){digitalWrite(8,HIGH);}
      void turnOff(){digitalWrite(8,LOW);}
  };
 void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  Internal_MOTOR T1;
  char buf[num]={};
  int i=0;
  while(Serial.available()){
        buf[i]=Serial.read();
        delay(2);
        if((++i)==num) i=0;
    }
        if(strcmp(buf, "on") == 0){
          Serial.print("on\n");
          T1.turnOn();
        }else if(strcmp(buf, "off") == 0){
           Serial.print("off\n");
            T1.turnOff();
        }
}
*/
  /**********************************************************************************
   * 情况3：
   *   直接通过TL_MOTOR来实现，但情况是仅有turnOn但不见turnOff
   *    
  **********************************************************************************/
  /*
#include "TL_Libraries.h"
#define num 3
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  char buf[num]={};
  int i=0;
  while(Serial.available()){
        buf[i]=Serial.read();
        delay(2);
        if((++i)==num) i=0;
    }
        if(strcmp(buf, "on") == 0){
          TL_MOTOR.turnOn();
        }else if(strcmp(buf, "off") == 0){
            TL_MOTOR.turnOff();
        }
}
*/
 /**********************************************************************************
   * 情况4：
   *   
   *    
  **********************************************************************************/
  
#include "TL_Libraries.h"
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//初始化串口
}
void loop() {
  // put your main code here, to run repeatedly:
 char buf[3] = {};//存放命令
 int i = 0;
  while (!Serial.available());//等待键入指令
    while (Serial.available()) {
      buf[i] = Serial.read();
      delay(2);
      if ((++i) == 3) i = 0;
    }
    if (strcmp(buf, "on") == 0) {
      TL_Fan.turnOn();
    }
    else if (strcmp(buf, "off") == 0) {
       TL_Fan.turnOff();
    }
}



