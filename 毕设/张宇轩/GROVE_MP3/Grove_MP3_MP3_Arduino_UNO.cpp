#include <Arduino.h>
#include "Grove_MP3_MP3_Arduino_UNO.h"

#if MP3_UART_TX == 0 && MP3_UART_RX == 1
    #define mp3 Serial
#else
	SoftwareSerial mp3(MP3_UART_TX, MP3_UART_RX);
#endif

Grove_MP3_MP3::Grove_MP3_MP3(){
}
/****************************************************************
 * Function Name: SelectPlayerDevice
 * Description: Select the player device, U DISK or SD card.
 * Parameters: 0x01:U DISK;  0x02:SD card
 * Return: none
****************************************************************/
void Grove_MP3_MP3::init()
{
    mp3.begin(9600);
    delay(100);
    mp3.write(0x7E);
    mp3.write(0xFF);
    mp3.write(0x06);
    mp3.write(0x09);
    mp3.write(uint8_t(0x00));
    mp3.write(uint8_t(0x00));
    mp3.write(0x02);  //SD
    mp3.write(0xEF);
    delay(200);
}

/****************************************************************
 * Function Name: SpecifyMusicPlay
 * Description: Specify the music index to play, the index is decided by the input sequence of the music.
 * Parameters: index: the music index: 0-65535.
 * Return: none
****************************************************************/
void Grove_MP3_MP3::SpecifyMusicPlay(uint16_t index)
{
    uint8_t hbyte, lbyte;
    hbyte = index / 256;
    lbyte = index % 256;
    mp3.write(0x7E);
    mp3.write(0xFF);
    mp3.write(0x06);
    mp3.write(0x03);
    mp3.write(uint8_t(0x00));
    mp3.write(uint8_t(hbyte));
    mp3.write(uint8_t(lbyte));
    mp3.write(0xEF);
    delay(10);
//  return true;
}

/****************************************************************
 * Function Name: SpecifyfolderPlay
 * Description: Specify the music index in the folder to play, the index is decided by the input sequence of the music.
 * Parameters: folder: folder name, must be number;  index: the music index.
 * Return: none
****************************************************************/
void Grove_MP3_MP3::SpecifyfolderPlay(uint8_t folder, uint8_t index)
{
    mp3.write(0x7E);
    mp3.write(0xFF);
    mp3.write(0x06);
    mp3.write(0x0F);
    mp3.write(uint8_t(0x00));
    mp3.write(uint8_t(folder));
    mp3.write(uint8_t(index));
    mp3.write(0xEF);
    delay(10);
//  return true;
}

/****************************************************************
 * Function Name: PlayPause
 * Description: Pause the MP3 player.
 * Parameters: none
 * Return: none
****************************************************************/
void Grove_MP3_MP3::PlayPause(void)
{
    mp3.write(0x7E);
    mp3.write(0xFF);
    mp3.write(0x06);
    mp3.write(0x0E);
    mp3.write(uint8_t(0x00));
    mp3.write(uint8_t(0x00));
    mp3.write(uint8_t(0x00));
//  mp3.write(0xFE);
//  mp3.write(0xED);
    mp3.write(0xEF);
    delay(20);
//  return true;
}

/****************************************************************
 * Function Name: PlayResume
 * Description: Resume the MP3 player.
 * Parameters: none
 * Return: none
****************************************************************/
void Grove_MP3_MP3::PlayResume(void)
{
    mp3.write(0x7E);
    mp3.write(0xFF);
    mp3.write(0x06);
    mp3.write(0x0D);
    mp3.write(uint8_t(0x00));
    mp3.write(uint8_t(0x00));
    mp3.write(uint8_t(0x00));
//  mp3.write(0xFE);
//  mp3.write(0xEE);
    mp3.write(0xEF);
    delay(20);
//  return true;
}

/****************************************************************
 * Function Name: PlayNext
 * Description: Play the next song.
 * Parameters: none
 * Return: none
****************************************************************/
void Grove_MP3_MP3::PlayNext(void)
{
    mp3.write(0x7E);
    mp3.write(0xFF);
    mp3.write(0x06);
    mp3.write(0x01);
    mp3.write(uint8_t(0x00));
    mp3.write(uint8_t(0x00));
    mp3.write(uint8_t(0x00));
    mp3.write(0xEF);
    delay(10);
//  return true;
}

/****************************************************************
 * Function Name: PlayPrevious
 * Description: Play the previous song.
 * Parameters: none
 * Return: none
****************************************************************/
void Grove_MP3_MP3::PlayPrevious(void)
{
    mp3.write(0x7E);
    mp3.write(0xFF);
    mp3.write(0x06);
    mp3.write(0x02);
    mp3.write(uint8_t(0x00));
    mp3.write(uint8_t(0x00));
    mp3.write(uint8_t(0x00));
    mp3.write(0xEF);
    delay(10);
//  return true;
}

/****************************************************************
 * Function Name: PlayLoop
 * Description: Play loop for all the songs.
 * Parameters: none
 * Return: none
****************************************************************/
void Grove_MP3_MP3::PlayLoop(void)
{
    mp3.write(0x7E);
    mp3.write(0xFF);
    mp3.write(0x06);
    mp3.write(0x11);
    mp3.write(uint8_t(0x00));
    mp3.write(uint8_t(0x00));
    mp3.write(0x01);
    mp3.write(0xEF);
    delay(10);
//  return true;
}

/****************************************************************
 * Function Name: SetVolume
 * Description: Set the volume, the range is 0x00 to 0x1E.
 * Parameters: volume: the range is 0x00 to 0x1E.
 * Return: none
****************************************************************/
void Grove_MP3_MP3::SetVolume(uint8_t volume)
{
    mp3.write(0x7E);
    mp3.write(0xFF);
    mp3.write(0x06);
    mp3.write(0x06);
    mp3.write(uint8_t(0x00));
    mp3.write(uint8_t(0x00));
    mp3.write(volume);
    mp3.write(0xEF);
    delay(10);
//  return true;
}

/****************************************************************
 * Function Name: IncreaseVolume
 * Description: Increase the volume.
 * Parameters: none
 * Return: none
****************************************************************/
void Grove_MP3_MP3::IncreaseVolume(void)
{
    mp3.write(0x7E);
    mp3.write(0xFF);
    mp3.write(0x06);
    mp3.write(0x04);
    mp3.write(uint8_t(0x00));
    mp3.write(uint8_t(0x00));
    mp3.write(uint8_t(0x00));
    mp3.write(0xEF);
    delay(10);
//  return true;
}

/****************************************************************
 * Function Name: DecreaseVolume
 * Description: Decrease the volume.
 * Parameters: none
 * Return: none
****************************************************************/
void Grove_MP3_MP3::DecreaseVolume(void)
{
    mp3.write(0x7E);
    mp3.write(0xFF);
    mp3.write(0x06);
    mp3.write(0x05);
    mp3.write(uint8_t(0x00));
    mp3.write(uint8_t(0x00));
    mp3.write(uint8_t(0x00));
    mp3.write(0xEF);
    delay(10);
//  return true;
}

Grove_MP3_MP3 TL_MP3;