#include "One_WiFi_WiFi_LinkIt_One.h"

bool Internal_WiFi::init(){
	LWiFi.begin();
	return true;
}

bool Internal_WiFi::join(const String& SSID, const String& PASSWD){
	char* buffSSID = (char*)malloc(sizeof(char)*(SSID.length()+1));
  	SSID.toCharArray(buffSSID, SSID.length()+1);
	char* buffPASSWD = (char*)malloc(sizeof(char)*(PASSWD.length()+1));
  	PASSWD.toCharArray(buffPASSWD, PASSWD.length()+1);
	join(buffSSID,buffPASSWD);
	free(buffPASSWD);
	free(buffSSID);
}

bool Internal_WiFi::join(const char* SSID, const char* PASSWD){
	unsigned long start = millis();
	int sig = 0;
	sig = LWiFi.connect(SSID, LWiFiLoginInfo(WIFI_AUTH, PASSWD));
	while ((0 == sig) && millis() - start < 10000){
		sig = LWiFi.connect(SSID, LWiFiLoginInfo(WIFI_AUTH, PASSWD));
		delay(200);
	}
	if(sig>0){
		return true;	
	}
	return false;
}

bool Internal_WiFi::disjoin(){
	LWiFi.disconnect();
	return true;
}

One_WiFi_HTTP& Internal_WiFi::fetchHTTP(){
	static One_WiFi_HTTP oneHTTP;
	return oneHTTP;
}

One_WiFi_MQTT& Internal_WiFi::fetchMQTT(){
	static One_WiFi_MQTT oneMQTT;
	return oneMQTT;
}

// HTTP Client
One_WiFi_HTTP::One_WiFi_HTTP(){
	oneClient = new LWiFiClient();
}

bool One_WiFi_HTTP::parseURL(const char* url, char* host, char* para){
	const char *uPtr = url;
	char  *_host, *_para;
	_host = host;
  	_para = para;
  	int state = 0;
  	while (*uPtr != '\0'){
  		if (state == 0 || state == 1){
      			*_host = *uPtr;
      			_host++;
    		}
    		if (*uPtr == '/'){
      			if (state == 1 && *(uPtr - 1) != '/'){
        			*(_host - 1) = '\0';
        			state = 2;
      			}
      			if (state == 0) // first /
     			{
        			if (*(uPtr + 1) == '/') // first //, indicating http://
        			{
        	  			if (_host != host){
       	     					_host = host;
          				}
          				state = 1;
          				uPtr++;
        			}else  // indicating no http://, just the hostname
       				{
          				*(_host - 1)= '\0';
          				state = 2;
        			}
      			}
    		}
    		if (state == 2){
			*_para = *uPtr;
      			_para++;
    		}
    		uPtr++;
 	}
	*_para = '\0';
	if (state == 2){
		return true;
	}else{
		return false;
	}
}


bool One_WiFi_HTTP::get(const String& url){
	char* _url = (char*)malloc(sizeof(char)*(url.length()+1));
	url.toCharArray(_url, url.length()+1);
	bool res = get(_url);
	free(_url);
	return res;
}

bool One_WiFi_HTTP::get(const char *url){
	char host[32], para[200];
	if (parseURL(url, host, para) == false){		
		return false;
	}
	unsigned long start = millis();
	while (0 == oneClient->connect(host, 80) && millis() - start < 2000){
		delay(200);
	}
	oneClient->println(String("GET ") + para + " HTTP/1.0");
	oneClient->println("User-Agent: Wget/1.11.4");
  	oneClient->println("Accept: */*");
  	oneClient->println(String("Host: ") +host);
  	oneClient->println("Connection: Close");
  	oneClient->println();
	int peekByte = -1;
	start = millis();
	while (peekByte == -1 && oneClient->connected() && millis() - start < 1000){
    		peekByte = oneClient->peek();
    		delay(200);
  	}
	if(peekByte == -1){
		return false;
	}
	int lineFeedCount = 0;
	start = millis();
	while (lineFeedCount < 2 && millis() - start < 500){
		int value = oneClient->read();
    		if (value == -1){
      			delay(10);
      			continue;
    		}
    		if (value == '\r'){
      			value = -1;
      			while (value == -1){
        			value = oneClient->read();
			}
			if (value == '\n'){
				lineFeedCount++;
			}else{
				lineFeedCount = 0;
			}
		}else{
			lineFeedCount = 0;
		}
	}
	if(lineFeedCount < 2){
		return false;	
	}
	start = millis();
	char* val = (char*)malloc(sizeof(char)*50);
	strcpy(val,"NULL");
	int  i = 0;
	while (oneClient->connected() && millis() - start < 1000){
    		val[i] = oneClient->read();
    		i++;
  	}
	if(strcmp(val,"NULL")!=0){
		free(val);
		return true;
	}else{
		free(val);
		return false;
	}
}

bool One_WiFi_HTTP::post(const String& url, const String& data){
	char* _url = (char*)malloc(sizeof(char)*(url.length()+1));
  	url.toCharArray(_url, url.length()+1);
  	char* _data = (char*)malloc(sizeof(char)*(data.length()+1));
  	data.toCharArray(_data, data.length()+1);
  	bool res = post(_url,_data);
  	free(_url);
  	free(_data);
  	return res;
}

bool One_WiFi_HTTP::post(const char* url, const char* data){
	char host[32], para[200];
	if (parseURL(url, host, para) == false){
		return false;
	}
	unsigned long start = millis();
	while (0 == oneClient->connect(host, 80) && millis() - start < 2000){
		delay(200);
	}
	oneClient->println(String("POST ") + para + " HTTP/1.0");
	//oneClient->println("User-Agent: Wget/1.11.4");
  	//oneClient->println("Accept: */*");
	oneClient->println(String("Host: ") +host);
	oneClient->println("Content-Type: application/x-www-form-urlencoded");
	oneClient->println(String("Content-Length: ")+strlen(data));
	oneClient->println();
	oneClient->println(data);
  	//oneClient->println("Connection: Close");
  	oneClient->println();
	int peekByte = -1;
	start = millis();
	while (peekByte == -1 && oneClient->connected() && millis() - start < 1000){
    		peekByte = oneClient->peek();
    		delay(200);
  	}
	if(peekByte == -1){
		return false;
	}
	int lineFeedCount = 0;
	start = millis();
	while (lineFeedCount < 2 && millis() - start < 500){
		int value = oneClient->read();
    		if (value == -1){
      			delay(10);
      			continue;
    		}
    		if (value == '\r'){
      			value = -1;
      			while (value == -1){
        			value = oneClient->read();
			}
			if (value == '\n'){
				lineFeedCount++;
			}else{
				lineFeedCount = 0;
			}
		}else{
			lineFeedCount = 0;
		}
	}
	if(lineFeedCount < 2){
		return false;	
	}
	start = millis();
	char* val = (char*)malloc(sizeof(char)*50);
	strcpy(val,"NULL");
	int  i = 0;
	while (oneClient->connected() && millis() - start < 1000){
    		val[i] = oneClient->read();
    		i++;
  	}
	if(strcmp(val,"NULL")!=0){
		free(val);
		return true;
	}else{
		free(val);
		return false;
	}
}

// MQTT Client
One_WiFi_MQTT::One_WiFi_MQTT(){
}
/*
int One_WiFi_MQTT::connect(const String& serverName, const int port, const String& clientName, const String& userName, const String& password){
	int __port = port;
	char* __serverName = (char*)malloc(sizeof(char)*(serverName.length()+1));
	serverName.toCharArray(__serverName, serverName.length()+1);
	char* __clientName = (char*)malloc(sizeof(char)*(clientName.length()+1));
	clientName.toCharArray(__clientName, clientName.length()+1);
	char* __userName = (char*)malloc(sizeof(char)*(userName.length()+1));
	userName.toCharArray(__userName, userName.length()+1);
	char* __password = (char*)malloc(sizeof(char)*(password.length()+1));
	password.toCharArray(__password, password.length()+1);
	int res = connect(__serverName, __port, __clientName, __userName, __password);
	free(__serverName);
	free(__clientName);
	free(__userName);
	free(__password);
	return res;
}
*/
int One_WiFi_MQTT::connect(char* serverName, int port, char* clientName, char* userName, char* password){
	_port = port;
	_serverName = (char*)malloc(sizeof(char)*(strlen(serverName)+1));
	strcpy(_serverName, serverName);
	_clientName = (char*)malloc(sizeof(char)*(strlen(clientName)+1));
	strcpy(_clientName, clientName);
	_userName =(char*)malloc(sizeof(char)*(strlen(userName)+1));
	strcpy(_userName, userName);
	_password = (char*)malloc(sizeof(char)*(strlen(password)+1));
	strcpy(_password, password);
	tcpClient = new LWiFiClient();
	ipstack = new IPStack(*tcpClient);
	client = new MQTT::Client<IPStack, Countdown, 200>(*ipstack);
	if(!client->isConnected()){
		int rc = ipstack->connect(_serverName, _port);
		if (rc != 1){
			return rc;
		}
		MQTTPacket_connectData data = MQTTPacket_connectData_initializer;       
		data.MQTTVersion = 4;
		data.clientID.cstring = _clientName;
		data.username.cstring = _userName;
		data.password.cstring = _password;
		rc = client->connect(data);
		return rc;
	}else{
		return 0;
	}
}

int One_WiFi_MQTT::reconnect(){
	if(!client->isConnected()){
		int rc = ipstack->connect(_serverName, _port);
		if (rc != 1){
			return rc;
		}
		MQTTPacket_connectData data = MQTTPacket_connectData_initializer;       
		data.MQTTVersion = 4;
		data.clientID.cstring = _clientName;
		data.username.cstring = _userName;
		data.password.cstring = _password;
		rc = client->connect(data);
		return rc;
	}else{
		return 0;
	}
}

int One_WiFi_MQTT::disconnect(){
	client->disconnect();
	return 0;
}

bool One_WiFi_MQTT::isConnected(){
	return client->isConnected();
}

int One_WiFi_MQTT::publish(const char* topicName, char* data, int length, int qos){
	if(reconnect()!=0){
		return -1;
	}
	MQTT::Message message;
	message.retained = false;
	message.dup = false;
	switch(qos){
		case 1:{
			message.qos = MQTT::QOS1;
			break;
		}
		case 2:{
			message.qos = MQTT::QOS2;
			break;
		}
		default:{
			message.qos = MQTT::QOS0;
			break;
		}
	}
	message.payload = (void*)data;
	message.payloadlen = length;
	int res = client->publish(topicName, message);
	return res;
}

int One_WiFi_MQTT::subscribe(const char* topicFilter, MQTT::Client<IPStack, Countdown>::messageHandler mh, int qos){
	if(reconnect()!=0){
		return -1;
	}
	MQTT::QoS Qos;
	switch(qos){
		case 1:{
			Qos = MQTT::QOS1;
			break;
		}
		case 2:{
			Qos = MQTT::QOS2;
			break;
		}
		default:{
			Qos = MQTT::QOS0;
			break;
		}
	}
	return client->subscribe(topicFilter, Qos, mh);
}

int One_WiFi_MQTT::unsubscribe(const char* topicFilter){
	return client->unsubscribe(topicFilter);
}

Internal_WiFi TL_WiFi;
