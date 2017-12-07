#ifndef GROVE_RTC_RTC_ARDUINO_UNO_H
#define GROVE_RTC_RTC_ARDUINO_UNO_H

#include "Sensor_template.h"
#include "Writer.h"
#define DS1307_I2C_ADDRESS 0x68

#define MON 1
#define TUE 2
#define WED 3
#define THU 4
#define FRI 5
#define SAT 6
#define SUN 7

struct time{
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
	uint16_t year;
	uint8_t month;
	uint8_t dayOfMonth;
	uint8_t dayOfWeek;// day of week, 1 = Monday
};

class Grove_RTC_RTC:public Sensor<struct time *>,public Writer<struct time *>{
private:
	int _read();
    void begin();
	uint8_t decToBcd(uint8_t val);
	uint8_t bcdToDec(uint8_t val);
	void setTime(void);
	void getTime(void);

public:
	Grove_RTC_RTC();
	void write(struct time *newtime);
};

extern Grove_RTC_RTC TL_RTC;

#endif
