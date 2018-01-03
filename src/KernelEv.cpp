#include "KernelEv.h"
#include "SCHEDULE.H"
#include "PCB.h"

KernelEv::KernelEv(IVTNo ivtNo)
{
	this->ivtNo=ivtNo;
	owner= PCB::running;
	val=0;
}

KernelEv::~KernelEv(){

}

void KernelEv::block(){
	PCB::running->state = BLOCKED;
	dispatch();
}

void KernelEv::deblock()
{
	owner->state = READY;
	Scheduler::put(owner);
}