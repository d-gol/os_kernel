#include "Semaphore.h"
#include "KernelSem.h"

Semaphore::Semaphore(int init=1){
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
	if(val()-1<0){
		myImpl->val--;
		myImpl->block;
	}
	unlock();
}

void Semaphore::signal(){
	lock();
	if(val()<0){
		myImpl->val++;
		myImpl->deblock;
	}
	unlock();
}
