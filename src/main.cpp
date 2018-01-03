
#include "timer.h"
#include <dos.h>
#include "Idle.h"
#include "PCB.h"

extern int userMain(int argc, char* argv[]);

void main(int argc, char* argv[])
{
	Timer::oldTimer = getvect(8);
	setvect(8, Timer::newTimer);

	Idle::idle = new Idle();
	Idle::idle->start();

	PCB::running = new PCB(0, 0, NULL);

	userMain(argc, argv);

	setvect(8, Timer::oldTimer);
}