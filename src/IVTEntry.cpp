
#include "IVTEntry.h"
#include "ListaEv.h"
#include <dos.h>
#include "THREAD.H"
#include "event.h"

IVTEntry* IVTEntry::entries[256];

IVTEntry::IVTEntry(unsigned char ivtNo, InterPtr newRoutine)
{
	lock();
	this->ivtNo = ivtNo;
	this->oldRoutine = getvect(ivtNo);
	setvect(ivtNo, newRoutine);
	events = new ListaEv();
	IVTEntry::entries[ivtNo] = this;
	unlock();
}

IVTEntry::~IVTEntry()
{
	lock();
	delete events;
	setvect(ivtNo, oldRoutine);
	IVTEntry::entries[ivtNo] = NULL;
	unlock();
}

void IVTEntry::signalEvents()
{
	lock();
	for (ListaEv::Elem* tek = events->prvi; tek; tek = tek->sled)
	{
		tek->pod->signal();
	}
	unlock();

	dispatch();
}

