#include "Multime.h"
#include "IteratorMultime.h"

#include <iostream>

//Complexitate: 0(1)
Nod::Nod(TElem e, PNod urm)
{
	this->e = e;
	this->urm = urm;
}

//Complexitate: 0(1)
TElem Nod::element()
{
	return e;
}

//Complexitate: 0(1)
PNod Nod::urmator()
{
	return urm;
}

//Complexitate: 0(1)
Multime::Multime() {
	prim = nullptr;
}

//Complexitate: 0(n)
bool Multime::adauga(TElem elem) {
	PNod q = new Nod(elem,nullptr);
	if (prim == nullptr)
	{
		prim = q;
		return true;
	}
	else
	{
		PNod t = prim;
		PNod a=nullptr;
		while (t != nullptr)
		{
			if (t->e == elem)
				return false;
			a = t;
			t = t->urm;
		}
		a->urm = q;
		return true;
	}
}

//Complexitate: 0(n)
//Best case: 0(1)
//Worst case: 0(n)
//Overall: 0
bool Multime::sterge(TElem elem) {
	PNod t = prim;
	if (t == nullptr)
		return false;
	if (t->e == elem)
	{
		prim = t->urm;
		return true;
	}
	while (t->urm != nullptr)
	{
		if (t->urm->e == elem)
		{
			t->urm = t->urm->urm;
			return true;
		}
		t = t->urm;
	}
	return false;
}

//Complexitate: 0(n)
bool Multime::cauta(TElem elem) const {
	PNod t = prim;
	if (t== nullptr)
		return false;
	while (t != nullptr)
	{
		if (t->e == elem)
			return true;
		t = t->urm;
	}
	return false;
}

//Complexitate: 0(n)
int Multime::dim() const {
	if(prim==nullptr)
		return 0;
	else
	{
		int nr = 1;
		PNod t = prim;
		while (t->urm != nullptr)
		{
			nr++;
			t = t->urm;
		}
		return nr;
	}
}

//Complexitate: 0(1)
bool Multime::vida() const {
	if(prim==nullptr)
		return true;
	return false;
}

//Complexitate: 0(n)
Multime::~Multime() {
	while (prim != nullptr)
	{
		PNod p = prim;
		prim = prim->urm;
		delete p;
	}
}

//Complexitate: 0(1)
IteratorMultime Multime::iterator() const {
	return IteratorMultime(*this);
}


//Complexitate: 0(n*m)
void Multime::reuniune(const Multime& b)
{
	if (b.prim != nullptr)
	{
		PNod s = b.prim;
		while (s != nullptr)
		{
			PNod t = prim;
			int ok = 0;
			while (t != nullptr)
			{
				if (t->e == s->e)
					ok = 1;
				t = t->urm;
			}
			if (ok == 0)
				adauga(s->e);
			s = s->urm;
		}
	}
}

