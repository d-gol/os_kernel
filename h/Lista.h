#ifndef _lista_h_
#define _lista_h_
#pragma once
#include "Symbol.h"

class Lista{
	struct Elem{
		Symbol* pod;
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