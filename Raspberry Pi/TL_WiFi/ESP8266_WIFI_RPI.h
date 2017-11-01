#ifndef TINYLINK_ESP8266
#define TINYLINK_ESP8266

#include <ostream>
#include "UrlUtils.h"
#include "SERIAL_RPI.h"

struct Response {
  bool status;
  String value;
  Response(bool stat, String val = ""): status(stat), value(val) {}
};
class ESP8266Wifi {
private:
    tinylink::Serial &_serial;
    Stream *_cerr;
    int _delay, _max_try;
    int _read_timeout;
    
    String _get_raw_response();
    String _get_raw_response(int timeout);
    String _escape(String str);
    Response _send(String buf, const String url, const String method);
    bool _check_response(String resp);
public:
    inline String _send_cmd(const char *atcmd);
    ESP8266Wifi(tinylink::Serial &stream, Stream *debug_stream = NULL);
    void setCerr(Stream *debug_stream);
    void setReadTimeout(int timeout);
    bool join(String SSID, String PassW = "");
    bool disjoin();
    bool init(long baut = 115200);
    bool available();
    bool send(String buf, const String url, const String method = "POST");
    bool send(String buf, int size, const String url, const String method = "POST") {
        return send(buf.substring(0, size), url, method);
    }
    int recv(String &buf, const String url, const String method = "GET");
    int recv(String &buf, int size, const String url, const String method = "GET");
};
extern unsigned long millis(void);
extern void delay(uint32_t);
extern ESP8266Wifi TL_WiFi;
#endif
