

#ifndef _idle_h_
#define _idle_h_

#include "THREAD.H"

class Idle : public Thread
{
public:
	Idle();
	void run();
	PCB* pcb;
	static Idle* idle;
};

#endif // !_idle_h_
