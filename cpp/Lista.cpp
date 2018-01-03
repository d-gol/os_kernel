#include "Lista.h"

Lista::Lista(){
	prvi=posl=0;
}

Lista::~Lista(){
	Elem* tek=prvi,*stari;
	while(tek){
		stari=tek;
		delete stari->pod;
		tek=tek->sled;
		delete stari;
	}
	delete tek;
}

void Lista::put(PCB* p){
	Elem* novi=new Elem(p);
	if(!prvi)
		prvi=novi;
	else
		posl->sled=novi;
	posl=novi;
}

PCB* Lista::getFirst(){
	if(prvi){
		Elem* stari=prvi;
		prvi=prvi->sled;
		PCB* p=stari->pod;
		delete stari;
		return p;
	}
	else
		return 0;
}

void Lista::remove(PCB* p){
	Elem* tek=prvi,*pret=0;
	while(tek && tek->pod!=p){
		pret=tek;
		tek=tek->sled;
	}
	if(tek){
		if(!pret)
			prvi=prvi->sled;
		else
			pret->sled=tek->sled;
		if(!tek->sled)
			posl=pret;
		if(!prvi)
			posl=0;
	}
}
