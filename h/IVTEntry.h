
#ifndef _ivtentry_h_
#define _ivtentry_h_

#include "util.h"

class ListaEv;

class IVTEntry
{
public:
	IVTEntry(unsigned char ivtNo, InterPtr newRoutine);
	~IVTEntry();
	unsigned char ivtNo;
	InterPtr oldRoutine;
	ListaEv* events;

	void signalEvents();

	static IVTEntry* entries[256];
};

#endif // !_ivtentry_h_
