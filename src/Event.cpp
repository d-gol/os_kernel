#include "Event.h"
#include "KernelEv.h"
#include "PCB.h"
#include "util.h"
#include "IVTEntry.h"
#include "ListaEv.h"

Event::Event(IVTNo ivtNo)
{
	myImpl=new KernelEv(ivtNo);
	IVTEntry::entries[ivtNo]->events->put(this);
}

Event::~Event()
{
	lock();
	if (IVTEntry::entries[myImpl->ivtNo] != NULL)
		IVTEntry::entries[myImpl->ivtNo]->events->remove(this);
	delete myImpl;
	unlock();
}

void Event::wait(){
	
	if (PCB::running != myImpl->owner)
		return;
	
	lock();
	if (--myImpl->val<0)
	{
		myImpl->block();
	}
	unlock();
}

void Event::signal(){
	lock();
	if (myImpl->val++<0)
	{
		myImpl->deblock();
	}
	unlock();
}
