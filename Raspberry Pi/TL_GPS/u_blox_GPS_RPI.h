#ifndef BBBU_BLOX_H
#define BBBU_BLOX_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

#define GPS_DATA_SIZE 101

typedef struct{
	int year;  
	int month; 
	int day;
	int hour;
	int minute;
	int second;
}date_time;

class u_blox
{
	friend void* read_thread_u_blox(void* arg);
private:
	double lng, lat;// longitude and latitude
	char NS, EW; // North South, East West
	date_time TIME; // time information
	int getComma(unsigned char num, char *str);
	double getDoubleNumber(char *s);
	pthread_mutex_t mutex_u_blox;
	pthread_t tid_u_blox;
  
public:
	u_blox();
	~u_blox();
	int read();
	int read_BL();
	void read_NBL();
	int parse(char *gpsData);
	double lngData();
	double latData();
	date_time timeData();
	//string data();
};


void* read_thread_u_blox(void* arg);
void UTC2BTC(date_time *);

extern u_blox TL_GPS;
#endif
