
#include "Idle.h"
#include "util.h"

Idle* Idle::idle = NULL;

Idle::Idle() : Thread(1024, 2)
{
	pcb = myPCB;
}

void Idle::run()
{
	while (1);
}

