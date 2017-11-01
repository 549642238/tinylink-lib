#ifndef TINYLINK_TIME
#define TINYLINK_TIME

#include <string>
using std::string;

namespace tinylink {
class Time {
private:
    typedef unsigned long uint64_t;
    typedef unsigned int uint32_t;
	static uint64_t epochMilli, epochMicro;
	void _delayMicrosecondsHard (unsigned int howLong);
public:
	static void initialiseEpoch(void);
    static unsigned long millisFromStart(void);
    static unsigned long microsFromStart(void);
    
    void delayMillis(unsigned long ms);
    void delayMicros(unsigned long ms);
	
    
    string timeFromInternet(void);
    string timeFromGPS(void);
};
}

#endif
