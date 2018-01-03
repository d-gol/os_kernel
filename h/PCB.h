
#ifndef _pcb_h_
#define _pcb_h_

#include "THREAD.H"

class Semaphore;

enum STATES { CREATED = 1, READY = 2, BLOCKED = 3, DONE = 4 };

class PCB
{
public:
	static int posId;
	int id;
	StackSize stackSize;
	Time timeSlice;
	Thread* myThread;

	PCB(StackSize stackSize, Time timeSlice, Thread* myThread);
	~PCB();

	//context
	unsigned* stack;
	unsigned sp;
	unsigned ss;
	unsigned bp;

	void create_stack();

	STATES state;
	static PCB* running;

	static void wrapper();

	Semaphore* semWaitToComplete;

};

#endif // !_pcb_h_
