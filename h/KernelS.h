#ifndef _kernel_sem_h_ 
#define _kernel_sem_h_ 

#include "Lista.h";

class KernelSem{
public:
	int val;
	Lista *blocked;

	KernelSem(int init);
	~KernelSem();
	void block();
	void deblock();
};

#endif