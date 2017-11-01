#ifndef TIMER_H
#define TIMER_H

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;
// 1000 -> 100 edited by fkb 16/12/14
#define MAX_TIMER_COUNT 100

//typedef void (*timer_handler)(void * user_data);

typedef void (*timer_handler)();

/*typedef enum {
	TIMER_ONE_SHOT = 0,
	TIMER_PERIODIC
} timer_Type;
*/
#define TIMER_ONE_SHOT 0
#define TIMER_PERIODIC 1

struct timer_node
{
    long                 fd;
    timer_handler        callback;
    void *              user_data;
    unsigned int        interval;
    int              type;
    struct timer_node * next;
};

class BTimer {
private:
    struct timer_node * new_node;
    struct itimerspec new_value;
    int start_flag; // indicate whether the the timer starts
    int interval_num; // for further usage
public:
	BTimer(); // internal defaults to 2s, type defaults to 
	BTimer(unsigned int interval, timer_handler handler, int type = TIMER_PERIODIC, void * user_data = NULL);
	~BTimer();
	BTimer& attachInterrupt(timer_handler handler);
	BTimer& detachInterrupt();
	//BTimer& setOneShot();
	//BTimer& setPeriodic();
	BTimer& setPeriod(unsigned int interval, int type = TIMER_PERIODIC);
	BTimer& setFrequency(unsigned int frep, int type = TIMER_PERIODIC);
	bool start();
	bool stop();
};

int timer_initialize();
void timer_finalize();
struct timer_node * _get_timer_from_fd(int fd);

#endif
