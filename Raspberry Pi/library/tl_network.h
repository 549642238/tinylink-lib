#ifndef TINYLINK_NETWORK
#define TINYLINK_NETWORK

#include <curl/curl.h>
#include <functional>
#include <string>
using std::string;

namespace tinylink {
class Network {
private:
    CURL *_curl;
    string _resp;
    static size_t _write_callback(void *contents, size_t size, size_t nmemb, void *userdata);
    CURLcode _post(const string url, const string data);
    CURLcode _get(const string url, const string data);
	virtual ssize_t _recv(string &buf, const string url, const string method, 
            std::function<string (string &)> fnc);
public:
    Network();
    ~Network();
    virtual bool init();
    virtual bool available();
	virtual bool send(string buf, const string url, const string method = "POST");
	virtual bool send(string buf, size_t size, const string url, const string method = "POST");
	virtual ssize_t recv(string &buf, const string url, const string method = "GET");
	virtual ssize_t recv(string &buf, size_t size, const string url, const string method = "GET");
};
}
#endif
