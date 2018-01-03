#ifndef _lista_h_
#define _lista_h_

#include "PCB.h"


class Lista{
	struct Elem{
		PCB* pod;
		Elem* sled;
		Elem(PCB *p,Elem* s=0){
			pod=p;
			sled=s;
		}
	};
	Elem* prvi,*posl;
public:
	Lista();
	~Lista();
	void put(PCB* p);
	PCB* getFirst();
	void remove(PCB* p);
};

#endif