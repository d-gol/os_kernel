#ifndef _lista_ev_h_
#define _lista_ev_h_

class Event;

class ListaEv{
public:
	struct Elem{
		Event* pod;
		Elem* sled;
		Elem(Event *p,Elem* s=0){
			pod=p;
			sled=s;
		}
	};
	Elem* prvi,*posl;
	ListaEv();
	~ListaEv();
	void put(Event* p);
	Event* getFirst();
	void remove(Event* p);
};

#endif