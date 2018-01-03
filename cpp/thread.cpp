
#include "THREAD.H"
#include "PCB.h"
#include "SCHEDULE.H"
#include "timer.h"

Thread::Thread(StackSize stackSize, Time timeSlice)
{
	lock();
	myPCB = new PCB(stackSize, timeSlice, this);
	unlock();
}

Thread::~Thread()
{
	waitToComplete();
	lock();
	delete myPCB;
	unlock();
}

void Thread::start()
{
	lock();
	myPCB->create_stack();
	myPCB->state = READY;
	Scheduler::put(myPCB);
	unlock();
}


void dispatch()
{
	lock();
	Timer::zahtevana_promena_konteksta = 1;
	Timer::newTimer();
	unlock();
}

//II deo
void Thread::waitToComplete()
{

}
