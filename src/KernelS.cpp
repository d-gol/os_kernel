#include "KernelS.h"
#include "SCHEDULE.H"

KernelSem::KernelSem(int init)
{
	val=init;
	blocked=new Lista();
}

KernelSem::~KernelSem(){
	delete blocked;
}

void KernelSem::block(){
	PCB::running->state = BLOCKED;
	blocked->put(PCB::running);
	dispatch();
}

void KernelSem::deblock()
{
	PCB* t=blocked->getFirst();
	t->state = READY;
	Scheduler::put(t);
}