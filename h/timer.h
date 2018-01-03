

#ifndef _timer_h_
#define _timer_h_

#include "util.h"

class Timer
{
public:
	static int zahtevana_promena_konteksta;
	static int protekloVreme;
	static InterPtr oldTimer;
	static void interrupt newTimer(...);
};

#endif