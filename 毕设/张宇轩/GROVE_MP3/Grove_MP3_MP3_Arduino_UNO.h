#ifndef GROVE_MP3_MP3_ARDUINO_UNO_H
#define GROVE_MP3_MP3_ARDUINO_UNO_H
#include <SoftwareSerial.h>
#include "TL_Config.h"

class Grove_MP3_MP3{
private:
	
public:
	Grove_MP3_MP3();
	void init();
	void SelectPlayerDevice(uint8_t device);

	void SpecifyMusicPlay(uint16_t index);
    
	void SpecifyfolderPlay(uint8_t folder, uint8_t index);
    
	void PlayPause(void);
    
	void PlayResume(void);
   
	void PlayNext(void);
   
	void PlayPrevious(void);
    
	void PlayLoop(void);
    
	void SetVolume(uint8_t volume);
    
	void IncreaseVolume(void);
    
	void DecreaseVolume(void);
};

extern Grove_MP3_MP3 TL_MP3;


#endif
