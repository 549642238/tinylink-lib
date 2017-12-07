#include"TL_Libraries.h"
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600); 
   TL_MP3.init();
}

void loop() {
  // put your main code here, to run repeatedly:
    char recvChar=0;
    if(Serial.available())
    {
      recvChar = Serial.read();
      switch (recvChar)
      {
        case '1':
            TL_MP3.SpecifyMusicPlay(1);
            Serial.println("Specify the music index to play");
            break;
        case '2':
            TL_MP3.PlayPause();
            Serial.println("Pause the MP3 player");
            break;
        case '3':
            TL_MP3.PlayResume();
            Serial.println("Resume the MP3 player");
            break;
        case '4':
            TL_MP3.PlayNext();
            Serial.println("Play the next song");
            break;
        case '5':
            TL_MP3.PlayPrevious();
            Serial.println("Play the previous song");
            break;
        case '6':
            TL_MP3.PlayLoop();
            Serial.println("Play loop for all the songs");
            break;
        case '7':
            TL_MP3.IncreaseVolume();
            Serial.println("Increase volume");
            break;
        case '8':
            TL_MP3.DecreaseVolume();
            Serial.println("Decrease volume");
            break;
        default:
            break;
     }
    }
}
