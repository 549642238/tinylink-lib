# include "u_blox_GPS_RPI.h"
#include "SERIAL_RPI.h"

static tinylink::Serial U_BLOX_Serial;

u_blox::u_blox(){
	lng = lat = 0;
	NS = 'N';
	EW = 'E';
	TIME.year = TIME.month = TIME.day = TIME.hour = TIME.minute = TIME.second = 0;
	pthread_mutex_init(&mutex_u_blox, NULL);
    U_BLOX_Serial.begin(9600);
}

u_blox::~u_blox(){
	pthread_mutex_destroy(&mutex_u_blox);
}

int u_blox::getComma(unsigned char num, char* str){
	unsigned char i, j = 0;
	int len = strlen((char *)str);
	for(i = 0; i < len; i++){
		if(str[i] == ',')
			j++;
		if(j == num)
			return i + 1;
	}
	return 0;
}

double u_blox::getDoubleNumber(char *s){
	char buf[20];
	memset(buf, 0, 20);
	unsigned char i;
	double rev;
	i = getComma(1, s);
	i = i - 1;
	strncpy(buf, s, i);
	buf[i] = 0;
	rev = atof(buf);
	return rev;
}

void UTC2BTC(date_time *gps){
//***************************************************
//如果秒号先出,再出时间数据,则将时间数据+1秒
	gps->second++; //加一秒
	if(gps->second>59){
		gps->second=0;
		gps->minute++;
		if(gps->minute>59){
			gps->minute=0;
			gps->hour++;
		}
	}	

//***************************************************
	gps->hour+=8;		//北京时间跟UTC时间相隔8小时
	if(gps->hour>23)
	{
		gps->hour-=24;
		gps->day+=1;
		if(gps->month==2 ||gps->month==4 ||gps->month==6 ||gps->month==9 ||gps->month==11 ){
			if(gps->day>30){			//上述几个月份是30天每月，2月份还不足30
		   		gps->day=1;
				gps->month++;
			}
		}
		else{
			if(gps->day>31){			//剩下的几个月份都是31天每月
		   		gps->day=1;
				gps->month++;
			}
		}
		if(gps->year % 4 == 0 ){//
	   		if(gps->day > 29 && gps->month ==2){		//闰年的二月是29天
	   			gps->day=1;
				gps->month++;
			}
		}
		else{
	   		if(gps->day>28 &&gps->month ==2){		//其他的二月是28天每月
	   			gps->day=1;
				gps->month++;
			}
		}
		if(gps->month>12){
			gps->month-=12;
			gps->year++;
		}		
	}
}

int u_blox::parse(char *gpsData){
	double latitude = 0;
	double longitude = 0;
	int tmp, checksum;
	if(gpsData[0] == '$')
	{
		tmp = getComma(1, gpsData);
		pthread_mutex_lock(&mutex_u_blox);
		TIME.hour     = (gpsData[tmp + 0] - '0') * 10 + (gpsData[tmp + 1] - '0');
		TIME.minute   = (gpsData[tmp + 2] - '0') * 10 + (gpsData[tmp + 3] - '0');
		TIME.second   = (gpsData[tmp + 4] - '0') * 10 + (gpsData[tmp + 5] - '0');

		tmp = getComma(9, gpsData);
		TIME.day     = (gpsData[tmp+0]-'0')*10+(gpsData[tmp+1]-'0');  
		TIME.month   = (gpsData[tmp+2]-'0')*10+(gpsData[tmp+3]-'0');  
		TIME.year    = (gpsData[tmp+4]-'0')*10+(gpsData[tmp+5]-'0')+2000; 	
		//UTC2BTC(&TIME); // turn the time to east area area
		pthread_mutex_unlock(&mutex_u_blox); 

		tmp = getComma(3, gpsData);
		latitude = getDoubleNumber(&gpsData[tmp]);
		tmp = getComma(5, gpsData);
		longitude = getDoubleNumber(&gpsData[tmp]);
		tmp = getComma(2, gpsData);
		checksum = gpsData[tmp];
		if (checksum == 'A')
		{
			if (latitude != 0 && longitude != 0)
			{
				pthread_mutex_lock(&mutex_u_blox);
				lat = latitude / 100;
				NS =  gpsData[getComma(4, gpsData)];
				lng = longitude / 100;
				EW =  gpsData[getComma(6, gpsData)];
				
				//cout << "GPS  reading success Time:"<<" "<<TIME.year << " "<<TIME.month<<" "<<TIME.day <<" "<<TIME.hour<< " "<< TIME.minute<<" "<<TIME.second<<endl;
				//cout << "latitude: " << lat <<NS<< "  longitude: " <<lng <<EW<<endl;
				
				pthread_mutex_unlock(&mutex_u_blox);

			}
			/*
			pthread_mutex_lock(&mutex_u_blox);
			cout << "GPS  reading success"<<" "<<TIME.year << " "<<TIME.month<<" "<<TIME.day <<" "<<TIME.hour<< " "<< TIME.minute<<" "<<TIME.second<<endl;
			cout << "latitude: " << lat <<NS<< "  longitude: " <<lng <<EW<<endl;
			pthread_mutex_unlock(&mutex_u_blox);
			*/
			return 0;
		}
		return -1;
	}
	return -1;
}

void u_blox::read_NBL(){
	pthread_create(&tid_u_blox, NULL, read_thread_u_blox, this);
		
}

static char GPS_buff[GPS_DATA_SIZE] = "";

int u_blox::read(){
	return read_BL();
}

int u_blox::read_BL(){
	while(U_BLOX_Serial.available()){
		int GPS_flag = 0;
		char ch = U_BLOX_Serial.read();
		memset(GPS_buff, 0, sizeof(GPS_buff));
		if (ch == '$'){
			GPS_buff[0] = '$';
			while (U_BLOX_Serial.available() == -1);
			for(int i = 1; i < 6; i++){
				char ch2 = U_BLOX_Serial.read();
				GPS_buff[i] = ch2;
			}

			if (strncmp(GPS_buff + 1, "GPRMC", 5) == 0 ){
				while (U_BLOX_Serial.available() == -1);
				char *temp = GPS_buff + 6;
				while(U_BLOX_Serial.available()){
					char ch1 = U_BLOX_Serial.read();
					if (ch1 != '$') {
						*temp = ch1;
						temp ++;
						GPS_flag = 1;
					}
					else {
						U_BLOX_Serial.flush();
						break;
					}				
				}
			}
			if (GPS_flag == 1) {
				//cout << GPS_buff <<endl;
				parse(GPS_buff);
				return 0;
			}
		}
	}
	return -1;
}

double u_blox::lngData(){
	double temp;
	pthread_mutex_lock(&mutex_u_blox);
	temp = lng;
	pthread_mutex_unlock(&mutex_u_blox);
	return temp;
}

double u_blox::latData(){
	double temp;
	pthread_mutex_lock(&mutex_u_blox);
	temp = lat;
	pthread_mutex_unlock(&mutex_u_blox);
	return temp;
}

date_time u_blox::timeData(){
	date_time temp;
	pthread_mutex_lock(&mutex_u_blox);
	temp = TIME;
	pthread_mutex_unlock(&mutex_u_blox);
	return temp;
}


void* read_thread_u_blox(void* arg){
	pthread_detach(pthread_self());	
	u_blox* temp = (u_blox*) arg;
	//while(1)
	{
		temp->read_BL();
		//printf("In thread ID = %lu \n", pthread_self());
		pthread_exit(0);		
	}
}

u_blox TL_GPS;
