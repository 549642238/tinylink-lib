#include "configRPI.h"
#include "TL_Libraries.h"

tinylink::Serial TL_Serial;
tinylink::Time TL_Time;
BTimer TL_Timer;

void _setup() {
	tinylink::Time::initialiseEpoch();
	timer_initialize();
}
void _cleanup() {
	timer_finalize();
}
int main() {
	_setup();
    setup();
    while (1) loop();
	_cleanup();
	return 0;
}
