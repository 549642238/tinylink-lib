#include "ESP8266_WIFI_RPI.h"
#include "UrlUtils.h"
#include "core.h"
#include <sys/time.h>

unsigned long millis() {
  struct timeval t;
  gettimeofday(&t, NULL);
  return (t.tv_sec * 1000 + t.tv_usec / 1000);
}
void delay(uint32_t duration)
{
  struct timeval currentTime, delayLength, endTime;

  gettimeofday(&currentTime, NULL);

  delayLength.tv_sec  = duration / 1000;
  delayLength.tv_usec = (duration % 1000) * 1000;  

  timeradd(&currentTime, &delayLength, &endTime);

  while(timercmp(&currentTime, &endTime, <))
  gettimeofday(&currentTime, NULL);
}
ESP8266Wifi::ESP8266Wifi(tinylink::Serial &stream, Stream *debug_stream):_serial(stream) {
    _cerr = debug_stream;
    _delay = 300;
    _max_try = 10;
    _read_timeout = 3;
}
void ESP8266Wifi::setCerr(Stream *debug_stream) {
  _cerr = debug_stream;
}
void ESP8266Wifi::setReadTimeout(int timeout) {
  _read_timeout = timeout; 
}
bool ESP8266Wifi::init(long baut) {
    _serial.begin(baut); delay(_delay);
    return true;
}
bool ESP8266Wifi::join(String SSID, String PassW) {
    String cmd = String("AT+CWJAP_CUR=") + _escape(SSID) + "," + _escape(PassW);
    
    _send_cmd("AT+CWMODE_CUR=1");//station mode
    _send_cmd("AT+CWDHCP_CUR=1,1"); //set station, enable DHCP
    
    int cnt = 0;
    for (; cnt < _max_try && _send_cmd(cmd.c_str()).indexOf("CONNECTED") < 0; ++cnt) delay(_delay * 10);
    return (cnt < _max_try);
}
bool ESP8266Wifi::disjoin() {
    return (_send_cmd("AT+CWQAP").indexOf(String("OK")) >= 0);
}
String ESP8266Wifi::_send_cmd(const char *atcmd) {
    _serial.println(atcmd);
    /*Do NOT add delay here, at least on Arduino platform. 
     *Otherwise, you may lose some data.
     */
    return _get_raw_response();
}
String ESP8266Wifi::_get_raw_response() {
    return _get_raw_response(_read_timeout);
}

String ESP8266Wifi::_get_raw_response(int timeout) {
    if (_cerr) _cerr->println(String("==========="));
  
    String ans;

    unsigned long start = millis();
    while (1) {
      while ((_serial.available()) > 0) {
        ans += (char)_serial.read();
        start = millis();
      }
      
      if (millis() - start >= timeout) break;     
    }
    if (_cerr) _cerr->println(ans + "\n^^^^^^^^^^^^^");
    
    return ans;
}
String ESP8266Wifi::_escape(String str) {
    String quote("\"");
    return quote + UrlUtils::escape(str) + quote;
}
bool ESP8266Wifi::available() {
    return _serial.available();
}

bool ESP8266Wifi::_check_response(String resp) {
   int pos = resp.indexOf("+IPD");
   return (pos >= 0 && resp.substring(0, pos).indexOf("ERROR") < 0); 
}
/* Due to the memory limit of arduino, we may lose some data in response.
 * */
Response ESP8266Wifi::_send(String data, const String url, const String method) {
    UrlUtils urlUtils(data, url, method, _cerr);
    if (! urlUtils.check_url()) return false;

    String startCmd = "AT+CIPSTART=" + _escape("TCP") + "," + _escape(urlUtils.get_server()) + "," + urlUtils.get_port();
    String ret;
    while (1) {
      ret = _send_cmd(startCmd.c_str());
      if (ret.indexOf("busy") < 0) break;
      delay(_delay); 
    }

    _send_cmd("AT+CIPMODE=0");
    String request = urlUtils.get_request();
    //ESP8266 may count the ending \r\n. So here the length is 2 more.
    String sendCmd = String("AT+CIPSEND=") + String(request.length() + 2, DEC);
    if (_send_cmd(sendCmd.c_str()).indexOf(">") >= 0) { 
      String resp = _send_cmd(request.c_str());
      return Response(_check_response(resp), resp);
    }
    return Response(false);
}
bool ESP8266Wifi::send(String buf, const String url, const String method) {
    return _send(buf, url, method).status;
}
int ESP8266Wifi::recv(String &buf, const String url, const String method) {
    Response resp = _send("", url, method);
    if (!resp.status) return 0;
    buf = resp.value;
    return buf.length();
}
int ESP8266Wifi::recv(String &buf, int size, const String url, const String method) {
    Response resp = _send("", url, method);
    if (!resp.status) return 0;
    buf = (resp.value.length() > size)?resp.value.substring(0, size): resp.value;
    return buf.length();
}

Stream debug_stream(std::cerr);
ESP8266Wifi TL_WiFi(TL_Serial, &debug_stream);
