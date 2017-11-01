#include "tl_network.h"
#include <cstdlib>
#include <sstream>
#include <algorithm>

namespace tinylink {
    Network::Network() {
        curl_global_init(CURL_GLOBAL_ALL);
        if (! (_curl = curl_easy_init())) std::exit(-1);

        curl_easy_setopt(_curl, CURLOPT_WRITEFUNCTION, &_write_callback);
        curl_easy_setopt(_curl, CURLOPT_WRITEDATA, &_resp);
    }
    Network::~Network() {
        if (_curl) {
            curl_easy_cleanup(_curl);
            curl_global_cleanup();
        }
    }
    size_t Network::_write_callback(void *contents, size_t size, size_t nmemb, void *userdata) {
        size_t num = size * nmemb;
        ((string *)userdata)->append((char *)contents, num);
        return num;
    }
    CURLcode Network::_post(const string url, const string data) {
        /*Do NOT curl_easy_escape url here, otherwise it will cause CURLE_COULDNT_RESOLVE_HOST error */
        curl_easy_setopt(_curl, CURLOPT_URL, url.c_str());

        char *tmp = curl_easy_escape(_curl, data.c_str(), 0);
        curl_easy_setopt(_curl, CURLOPT_POSTFIELDS, tmp);
        curl_free(tmp);

        string::size_type size = data.size();
        curl_easy_setopt(_curl, ((size >= (string::size_type)(1 << 31))? CURLOPT_POSTFIELDSIZE_LARGE: CURLOPT_POSTFIELDSIZE), size);

        _resp.clear();
        return curl_easy_perform(_curl);
    }

    CURLcode Network::_get(const string url, const string data) {
        curl_easy_setopt(_curl, CURLOPT_URL, url.c_str());

        _resp.clear();
        return curl_easy_perform(_curl);
    }

    bool Network::init() {
        return true;
    }
    bool Network::available() {
        return true;
    }
	bool Network::send(string buf, const string url, const string method) {
        if (method == "POST") {
            return (_post(url, buf) == CURLE_OK);
        } 
        if (method == "GET") {
            return (_get(url, buf) == CURLE_OK);
        } 
        return false;
    }
	bool Network::send(string buf, size_t size, const string url, const string method) {
        return send(buf.substr(0, size), url, method);
    }
	ssize_t Network::recv(string &buf, const string url, const string method) {
        return _recv(buf, url, method, [](string &resp)->string{
            return resp;
        });
    }
	ssize_t Network::recv(string &buf, size_t size, const string url, const string method) {
        return _recv(buf, url, method, [size](string &resp)->string{
            return resp.substr(0, std::min(resp.size(), size));
        });
    }
	ssize_t Network::_recv(string &buf, const string url, const string method, 
            std::function<string (string &)> fnc) {
        if ((method == "POST" && _post(url, "") == CURLE_OK) 
        || (method == "GET" && _get(url, "") == CURLE_OK)) {
            buf = fnc(_resp);
            return buf.size();
        } 
        return -1;
    }
}
