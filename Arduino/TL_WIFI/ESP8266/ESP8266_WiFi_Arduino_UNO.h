#ifndef ESP8266_WIFI_ARDUINO_UNO_H
#define ESP8266_WIFI_ARDUINO_UNO_H

#include <Arduino.h>
#include "TL_Config.h"
#include <IPStack.h>
#include <Countdown.h>
#include <WiFiEsp.h>
#include <WiFiEspClient.h>
#include <MQTTClient.h>
#include <SoftwareSerial.h>


// HTPP client based on ESP8266 device
class ESP8266_HTTP{
private:
	WiFiEspClient* espClient;
	String response;
	bool parseURL(const char* url, char* host, char* para);
public:
	ESP8266_HTTP();
	bool get(const String& url);
	bool get(const char *url);
	bool post(const String& url, const String& data);
	bool post(const char* url, const char* data);
	String getResponse();
};

// MQTT client based on ESP8266 device
class ESP8266_MQTT{
private:
	char* _serverName, *_clientName, *_userName, *_password;
	int _port;
	WiFiEspClient *tcpClient;
	IPStack *ipstack;
	MQTT::Client<IPStack, Countdown, 140> *client;
public:
	ESP8266_MQTT();
	//~ESP8266_MQTT();
	int connect(char* serverName, int port, char* clientName, char* userName="", char* password="");	// 0 for success
	//int connect(const String serverName, const int port, const String clientName, const String userName="", const String password="");
	int reconnect();											// 0 for success
	int disconnect();											// 0 for success
	bool isConnected();											// 0 for success
	//int publish(const String& topicName, MQTT::Message& message);						// 1 for success
	//int publish(const char* topicName, MQTT::Message& message);
	int publish(const char* topicName, char* data, int length, int qos=0);
	//int publish(const String& topicName, const String& data, int length, int qos=0);
	int subscribe(const char* topicFilter, MQTT::Client<IPStack, Countdown>::messageHandler mh, int qos=0);	// 0 for success
	int unsubscribe(const char* topicFilter);								// 0 for success
};


// ESP8266 device function
class ESP8266_WiFi{
private:
	int status;
public:
	ESP8266_WiFi();
	bool init();
	bool join(String& SSID, const String& PASSWD);
	bool join(char* SSID, const char* PASSWD);
	bool disjoin();
	ESP8266_MQTT& fetchMQTT();
	ESP8266_HTTP& fetchHTTP();
};

typedef ESP8266_HTTP TL_HTTP;
typedef ESP8266_MQTT TL_MQTT;

extern ESP8266_WiFi TL_WiFi;

#endif
