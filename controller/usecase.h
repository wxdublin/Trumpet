#ifndef USECASE_H
#define USECASE_H 1

#include "eventhandler.h"

typedef void (*usecase_atserverjoin_func)(struct usecase * u, struct serverdata * server);
typedef void (*usecase_ateventsatisfaction_func)(struct usecase * u, struct event * e, struct eventhistory * es);
typedef void (*usecase_finish_func)(struct usecase * u);

struct usecase{
	struct eventhandler * eh;
	usecase_atserverjoin_func atserverjoin;
	usecase_ateventsatisfaction_func ateventsatisfaction;
	usecase_finish_func finish;
	void * u2;
};

struct usecase_netwide{
	struct usecase u;
	uint16_t targetservers;
	uint16_t eventsnum;
	uint16_t serversnum;
};

struct usecase_congestion{
	struct usecase u;
	bool proactive_udpeventon; //a hack to check if the proactive event is added or not
	bool reactive_udpeventon;  //a hack to see if the udp heavy hitter detection event is on or not.
	uint16_t serversnum;
};


struct usecase * usecase_netwide_init(uint16_t targetservers, uint16_t eventsnum);
struct usecase * usecase_congestion_init(void);

#endif /* usecase.h */
