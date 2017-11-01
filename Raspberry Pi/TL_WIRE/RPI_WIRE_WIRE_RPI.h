#ifndef TINYLINK_WIRE
#define TINYLINK_WIRE

#include "tl_network.h"
#include <vector>
#include <string>
using std::vector;
using std::string;

namespace tinylink{
class Wire: public Network{
public:
	bool setConfig(string IP, string netmask, string gateway, vector<string>& dns_nameservers);
};
}

#endif
