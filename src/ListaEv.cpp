#include "ListaEv.h"

ListaEv::ListaEv(){
	prvi=posl=0;
}

ListaEv::~ListaEv(){
	Elem* tek=prvi,*stari;
	while(tek){
		stari=tek;
		tek=tek->sled;
		delete stari;
	}
	delete tek;
}

void ListaEv::put(Event* p){
	Elem* novi=new Elem(p);
	if(!prvi)
		prvi=novi;
	else
		posl->sled=novi;
	posl=novi;
}

Event* ListaEv::getFirst(){
	if(prvi){
		Elem* stari=prvi;
		prvi=prvi->sled;
		Event* p=stari->pod;
		delete stari;
		return p;
	}
	else
		return 0;
}

void ListaEv::remove(Event* p){
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
