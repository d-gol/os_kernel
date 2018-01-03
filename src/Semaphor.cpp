#include "Semaphor.h"
#include "KernelS.h"
#include "util.h"

Semaphore::Semaphore(int init){
	myImpl=new KernelSem(init);
}

Semaphore::~Semaphore(){
	delete myImpl;
}

int Semaphore::val()const{
	return myImpl->val;
}

void Semaphore::wait(){
	lock();
	if (--myImpl->val<0)
	{
		myImpl->block();
	}
	unlock();
}

void Semaphore::signal(){
	lock();
	if (myImpl->val++<0)
	{
		myImpl->deblock();
	}
	unlock();
}
