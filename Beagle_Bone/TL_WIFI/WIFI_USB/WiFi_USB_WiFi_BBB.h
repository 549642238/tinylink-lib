#ifndef WIFI_USB_WIFI_BBB_H
#define WIFI_USB_WIFI_BBB_H
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <unistd.h>

#include "TL_Config.h"
#include "TL_HTTPClient.h"
#include "TL_MQTTClient.h"

using namespace std;

class Wifi_Network {
private:
	//TL_HTTP http_client;
	//TL_MQTT mqtt_client;

public:
	Wifi_Network();
	~Wifi_Network();
	bool init();// initialize

	bool join(const char* SSID, const char* P);
	bool join(const string& SSID, const string& PassW = "");// choose the AP and set the password, then join the network
	bool join(const String& SSID, const String& PassW = "");
	bool disjoin();
	bool available();// test whether the network is OK
	
	TL_HTTP& fetchHTTP();
	TL_MQTT& fetchMQTT();
};

#if PLATFORM == 3 && BOARD == 1005
#if WIFI == WIFI_USB
extern Wifi_Network TL_WiFi;
#endif
#endif

#endif
