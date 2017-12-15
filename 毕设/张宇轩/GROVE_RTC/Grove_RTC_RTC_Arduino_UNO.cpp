#include <Arduino.h>
#include "TL_Config.h"
#include "Grove_RTC_RTC_Arduino_UNO.h"
#include <Wire.h>

Grove_RTC_RTC::Grove_RTC_RTC():Sensor(malloc(sizeof(struct time))){
	//_data=(struct time*)malloc(sizeof(struct time));
	begin();
}

uint8_t Grove_RTC_RTC::decToBcd(uint8_t val)
{
	return ( (val/10*16) + (val%10) );
}

//Convert binary coded decimal to normal decimal numbers
uint8_t Grove_RTC_RTC::bcdToDec(uint8_t val)
{
	return ( (val/16*10) + (val%16) );
}

void Grove_RTC_RTC::begin()
{
	Wire.begin();
}

void Grove_RTC_RTC::getTime()
{
    // Reset the register pointer
	Wire.beginTransmission(DS1307_I2C_ADDRESS);
	Wire.write((uint8_t)0x00);
	Wire.endTransmission();
	Wire.requestFrom(DS1307_I2C_ADDRESS, 7);
	// A few of these need masks because certain bits are control bits
	_data->second	   = bcdToDec(Wire.read() & 0x7f);
	_data->minute	   = bcdToDec(Wire.read());
	_data->hour	   = bcdToDec(Wire.read() & 0x3f);// Need to change this if 12 hour am/pm
	_data->dayOfWeek  = bcdToDec(Wire.read());
	_data->dayOfMonth = bcdToDec(Wire.read());
	_data->month      = bcdToDec(Wire.read());
	_data->year	   = bcdToDec(Wire.read())+2000;
}
/*******************************************************************/
/*Frunction: Write the time that includes the date to the RTC chip */
void Grove_RTC_RTC::setTime()
{
	Wire.beginTransmission(DS1307_I2C_ADDRESS);
	Wire.write((uint8_t)0x00);
	Wire.write(decToBcd(_data->second));// 0 to bit 7 starts the clock
	Wire.write(decToBcd(_data->minute));
	Wire.write(decToBcd(_data->hour));  // If you want 12 hour am/pm you need to set bit 6
	Wire.write(decToBcd(_data->dayOfWeek));
	Wire.write(decToBcd(_data->dayOfMonth));
	Wire.write(decToBcd(_data->month));
	Wire.write(decToBcd(_data->year-2000));
	Wire.endTransmission();
}

void Grove_RTC_RTC::write(struct time *newtime)
{
    _data=newtime;
	setTime();//write time to the RTC chip
}

int Grove_RTC_RTC::_read()
{	
	if(_data!=NULL)
    {
		getTime();
		return 0;
	}
    return -1;
}

Grove_RTC_RTC TL_RTC;
