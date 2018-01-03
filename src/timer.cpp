
#include "timer.h"
#include "PCB.h"
#include <dos.h>
#include "SCHEDULE.H"
#include "Idle.h"


int Timer::zahtevana_promena_konteksta = 0;
int Timer::protekloVreme = 0;
InterPtr Timer::oldTimer = NULL;

extern void tick();

void interrupt Timer::newTimer(...)
{
	if (!zahtevana_promena_konteksta)
	{
		Timer::oldTimer();
		Timer::protekloVreme++;
		tick();
	}

	if (zahtevana_promena_konteksta || (PCB::running->timeSlice == Timer::protekloVreme && PCB::running->timeSlice != 0))
	{
		PCB::running->sp = _SP;
		PCB::running->ss = _SS;
		PCB::running->bp = _BP;

		if (PCB::running->state == READY && PCB::running != Idle::idle->pcb)
			Scheduler::put(PCB::running);

		PCB::running = Scheduler::get();

		if (PCB::running == NULL)
		{
			PCB::running = Idle::idle->pcb;
		}

		_SP = PCB::running->sp;
		_SS = PCB::running->ss;
		_BP = PCB::running->bp;

		Timer::protekloVreme = 0;
		zahtevana_promena_konteksta = 0;
	}
}