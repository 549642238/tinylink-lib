#include "SDS018_PM25_Arduino_UNO.h"

#if PM25_UART_TX == 0 || PM25_UART_RX == 1
  #if PM25_UART_TX == 0 && PM25_UART_RX == 1 // (UTX, URX) = (0, 1)
    #define SDS018_Serial Serial
  #else
    #pragma message("Error: UART RX and TX are not consecutive!")
  #endif
#else
  SoftwareSerial SDS018_Serial(PM25_UART_TX, PM25_UART_RX);
#endif

T_SDS018::T_SDS018():Sensor(0.0){
  SDS018_Serial.begin(9600);
}

int T_SDS018::_read()
{
  unsigned char t[10];
  int counter = 0;
  int rounds = 0;
  int flag = 0;
  
  double pm25Sum;
  double pm10Sum;
  
  pm25 = pm10 = pm25Sum = pm10Sum = 0;

  while(SDS018_Serial.available())
  {
    unsigned char ch = SDS018_Serial.read();
    if (ch == 170)
    {
      if (flag == 0)
      {
        flag = 1;
      }
      else
      {
        if (counter == 10 && t[1] == 192 && t[9] == 171)
        {
          unsigned char crc = t[2] + t[3] + t[4] + t[5] + t[6] + t[7];
          if (crc == t[8])
          {
            rounds++;
            double pm25Cur = 1.0 * (int(t[3]) * 256 + int(t[2])) / 10;
            double pm10Cur = 1.0 * (int(t[5]) * 256 + int(t[4])) / 10;
            pm25Sum += pm25Cur;
            pm10Sum += pm10Cur;
          }
          else
          {
            // writeFile(String() + "\n" + "CRC error");
          }
        }
        else
        {
          // writeFile(String() + "Counter: " + counter + "\nChars: ");
//          Serial.write(t, counter);
//          Serial.println("");
        }
      }
      counter = 0;
    }
    t[counter++] = ch;
  }
  delay(2000);
  if (flag && rounds > 0)
  {
    pm25 = pm25Sum / rounds;
    pm10 = pm10Sum / rounds;
    // writeFile(String() + "T_SDS018 sample rounds: " + rounds);
    _data = pm25;
    return 0;
  }
  else
  {
    // writeFile("No SDS data available");
    return -1;
  }
}

T_SDS018 TL_PM25;
