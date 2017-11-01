#ifndef ONE_WIFI_WIFI_LINKIT_ONE_H
#define ONE_WIFI_WIFI_LINKIT_ONE_H

#include <Arduino.h>
#include <LWiFi.h>
#include <LWiFiClient.h>
#include <IPStack.h>
#include <Countdown.h>
#include <MQTTClient.h>
#include "TL_Config.h"

#define WIFI_AUTH LWIFI_WPA

typedef void (*messageHandler)(MQTT::MessageData&);

class One_WiFi_HTTP{
private:
	bool parseURL(const char* url, char* host, char* para);
	LWiFiClient* oneClient;
public:
	One_WiFi_HTTP();
	bool get(const String& url);
  	bool get(const char *url);
  	bool post(const String& url, const String& data);
  	bool post(const char* url, const char* data);
};

class One_WiFi_MQTT{
private:
	char* _serverName, *_clientName, *_userName, *_password;
	int _port;
	LWiFiClient* tcpClient;
	IPStack *ipstack;
	MQTT::Client<IPStack, Countdown, 200> *client;
public:
	One_WiFi_MQTT();
	int connect(char* serverName, int port, char* clientName, char* userName="", char* password="");	// 0 for success
	//int connect(const String serverName, const int port, const String clientName, const String userName="", const String password="");
	int reconnect();											// 0 for success
	int disconnect();											// 0 for success
	bool isConnected();											// 1 for success
	//int publish(const String& topicName, MQTT::Message& message);						// 0 for success
	//int publish(const char* topicName, MQTT::Message& message);
	int publish(const char* topicName, char* data, int length, int qos=0);
	//int publish(const String& topicName, const String& data,  int length, int qos=0);
	int subscribe(const char* topicFilter, MQTT::Client<IPStack, Countdown>::messageHandler mh, int qos=0);	// 0 for success
	int unsubscribe(const char* topicFilter);								// 0 for success
};

class Internal_WiFi{
public:
	Internal_WiFi(){}
	bool init();
	bool join(const String& SSID, const String& PASSWD);
	bool join(const char* SSID, const char* PASSWD);
	bool disjoin();
	One_WiFi_MQTT& fetchMQTT();
	One_WiFi_HTTP& fetchHTTP();
};

typedef One_WiFi_HTTP TL_HTTP;
typedef One_WiFi_MQTT TL_MQTT;

extern Internal_WiFi TL_WiFi;

#endif
