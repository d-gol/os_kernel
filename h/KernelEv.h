#ifndef _kernel_ev_h_ 
#define _kernel_ev_h_ 

class PCB;

typedef unsigned char IVTNo;

class KernelEv{
public:
	IVTNo ivtNo;
	int val;
	PCB *owner;

	KernelEv(IVTNo ivtNo);
	~KernelEv();
	void block();
	void deblock();
};

#endif