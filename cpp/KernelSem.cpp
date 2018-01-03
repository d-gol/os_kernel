#include "KernelSem.h"
#include "SCHEDULE.H"

KernelSem::KernelSem(int init){
	val=init;
	blocked=new Lista();
}

KernelSem::~KernelSem(){
	delete blocked;
}

void KernelSem::block(){
	blocked->put(PCB::running);
	dispatch();
}

void KernelSem::deblock(){
	PCB* t=blocked->getFirst();
	Scheduler::put(t);
}