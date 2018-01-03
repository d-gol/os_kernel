
#include "timer.h"
#include "PCB.h"
#include <dos.h>
#include "SCHEDULE.H"


int Timer::zahtevana_promena_konteksta = 0;
int Timer::protekloVreme = 0;
InterPtr Timer::oldTimer = NULL;


void interrupt Timer::newTimer(...)
{
	if (!zahtevana_promena_konteksta) //pozvao CPU
	{
		Timer::oldTimer();
		Timer::protekloVreme++;
	}

	//ili je pozvan dispatch ili je isteklo vreme
	if (zahtevana_promena_konteksta || (PCB::running->timeSlice == Timer::protekloVreme && PCB::running->timeSlice != 0))
	{
		//backup konteksta tekuce niti
		PCB::running->sp = _SP;
		PCB::running->ss = _SS;
		PCB::running->bp = _BP;

		//stavljanje tekuce niti u scheduler
		if (PCB::running->state == READY)
			Scheduler::put(PCB::running);

		//dohvatanja nove niti iz schedulera
		PCB::running = Scheduler::get();

		if (PCB::running == NULL)
		{

		}

		//restauracija konteksta nove niti u cpu
		_SP = PCB::running->sp;
		_SS = PCB::running->ss;
		_BP = PCB::running->bp;

		Timer::protekloVreme = 0;
		zahtevana_promena_konteksta = 0;
	}
}