
#include "timer.h"
#include <dos.h>

void main(int argc, char* argv[])
{
	Timer::oldTimer = getvect(8);
	setvect(8, Timer::newTimer);


	setvect(8, Timer::oldTimer);
}