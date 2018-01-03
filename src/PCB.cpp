
#include "PCB.h"
#include <dos.h>
#include "util.h"
#include "Semaphor.h"


PCB* PCB::running = 0;
int PCB::posId = 0;

PCB::PCB(StackSize stackSize, Time timeSlice, Thread* myThread)
{
	lock();
	id=++posId;
	this->stackSize=stackSize;
	this->timeSlice=timeSlice;
	this->myThread=myThread;
	this->state=CREATED;
	this->stack = NULL;
	this->semWaitToComplete = new Semaphore(0);
	unlock();

}

PCB::~PCB()
{
	lock();
	delete[] stack;
	delete semWaitToComplete;
	unlock();
}

void PCB::create_stack()
{
	lock();
	stack = new unsigned[stackSize];
	stack[stackSize - 1] = 0x200;			
	stack[stackSize - 2] = FP_SEG(PCB::wrapper);		
	stack[stackSize - 3] = FP_OFF(PCB::wrapper);		
	stack[stackSize - 9] = _DS;				
	this->ss = FP_SEG(&stack[stackSize - 12]);
	this->sp = FP_OFF(&stack[stackSize - 12]);	
	this->bp = FP_OFF(&stack[stackSize - 12]);
	unlock();
}

void PCB::wrapper()
{
	PCB::running->myThread->run();
	
	lock();
	PCB::running->state = DONE; 

	while (PCB::running->semWaitToComplete->val() < 0)
		PCB::running->semWaitToComplete->signal();

	dispatch();
}

