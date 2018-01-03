
#include "PCB.h"
#include <dos.h>


PCB* PCB::running = 0;
int PCB::posId = 0;

PCB::PCB(StackSize stackSize, Time timeSlice, Thread* myThread)
{
	id=++posId;
	this->stackSize=stackSize;
	this->timeSlice=timeSlice;
	this->myThread=myThread;
	this->state=CREATED;
}

PCB::~PCB()
{
	state=DONE;
	delete myThread;
}

void PCB::create_stack()
{
	lock();
	stack = new unsigned[stackSize];
	stack[stackSize - 1] = 0x200;			//0x200 1 je gde je inter... flag
	stack[stackSize - 2] = FP_SEG(PCB::wrapper);		//cs
	stack[stackSize - 3] = FP_OFF(PCB::wrapper);		//ip (PC)
	stack[stackSize - 9] = _DS;				//data segment
	this->ss = FP_SEG(&stack[stackSize - 12]);	//SEG kupi segment od adrese koju prosledimo
	this->sp = FP_OFF(&stack[stackSize - 12]);	//SP treba da bude na ovom mestu (namestamo ga na to mesto)
	this->bp = FP_OFF(&stack[stackSize - 12]); //Base pointer treba da pokazuje na pocetak steka
	unlock();
}

void PCB::wrapper()
{
	PCB::running->myThread->run();
	
	lock();
	PCB::running->state = DONE; //da se ne bi vratila u CPU posle dispatch
	dispatch();
}

