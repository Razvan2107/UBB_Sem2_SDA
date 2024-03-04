#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>
#include <iostream>

using namespace std;

Nod::Nod(TElem e, PNod st, PNod dr)
{
	this->e = e;
	this->st = st;
	this->dr = dr;
}

TElem Nod::element()
{
	return e;
}

PNod Nod::stanga()
{
	return st;
}

PNod Nod::dreapta()
{
	return dr;
}

Colectie::Colectie()
{
	rad = nullptr;
}

//Complexitate: 0(h) unde h reprezinta inaltimea arborelui
PNod Colectie::adauga_rec(PNod p, TElem e)
{
	if (p == nullptr)
		p = new Nod(e, nullptr, nullptr);
	else
	{
		if (e <= p->e)
			p->st = adauga_rec(p->st, e);
		else
			p->dr = adauga_rec(p->dr, e);
	}
	return p;
}

//Complexitate: 0(h) unde h reprezinta inaltimea arborelui
void Colectie::adauga(TElem elem) 
{
	rad = adauga_rec(rad, elem);
}

//Complexitate: 0(h) unde h reprezinta inaltimea arborelui
PNod Colectie::minim(PNod p)
{
	while (p->st != nullptr)
		p = p->st;
	return p;
}

//Complexitate: 0(h) unde h reprezinta inaltimea arborelui
PNod Colectie::sterge_rec(PNod p, TElem elem, bool& sters)
{
	if (p == nullptr)
		return nullptr;
	else if (p->e > elem)
	{
		p->st = sterge_rec(p->st, elem, sters);
		return p;
	}
	else if (p->e < elem)
	{
		p->dr = sterge_rec(p->dr, elem, sters);
		return p;
	}
	//suntem pe pozitia elementului cautat
	else
	{
		if (p->st != nullptr && p->dr != nullptr)
		//suntem in cazul in care are subarbore stang si drept
		{
			//determinam minimul din subarborele drept al nodului de sters
			PNod temp = minim(p->dr);
			//se muta cheia in nodul sters
			p->e = temp->e;
			//sterg minimul
			bool n = false;
			p->dr = sterge_rec(p->dr, temp->e, n);
			//sters ia valoarea adevarat pt ca s-a sters elementul
			sters = true;
			return p;
		}
		else
		{
			PNod temp = p;
			PNod nou = nullptr;
			//nu exista subarbore stang
			if (temp->st == nullptr)
				nou = temp->dr;
			//nu exista subarbore drept
			else
				nou = temp->st;
			//sters ia valoarea adevarat pt ca s-a sters elementul
			sters = true;
			//dealoc nodul sters
			delete temp;
			return nou;
		}
	}
}

//Complexitate: 0(h) unde h reprezinta inaltimea arborelui
bool Colectie::sterge(TElem elem) {
	bool sters=false;
	rad=sterge_rec(rad, elem, sters);
	return sters;
}

//Complexitate: 0(h) unde h reprezinta inaltimea arborelui
bool Colectie::cauta_rec(PNod p,TElem elem) const
{
	if (p == nullptr)
		return false;
	else if (p->e == elem)
		return true;
	else if (p->e > elem)
		cauta_rec(p->st, elem);
	else
		cauta_rec(p->dr, elem);
}

//Complexitate: 0(h) unde h reprezinta inaltimea arborelui
bool Colectie::cauta(TElem elem) const {
	if(cauta_rec(rad,elem)==true)
		return true;
	return false;
}

int Colectie::nr_rec(PNod p, TElem elem) const
{
	if (p == nullptr)
		return 0;
	else if (p->st == nullptr && p->dr == nullptr)
		if (p->e == elem)
			return 1;
		else
			return 0;
	else if (p->st != nullptr && p->dr != nullptr)
		if(p->e==elem)
			return 1 + nr_rec(p->st,elem) + nr_rec(p->dr,elem);
		else
			return  nr_rec(p->st, elem) + nr_rec(p->dr, elem);
	else if (p->st != nullptr && p->dr == nullptr)
		if (p->e == elem)
			return 1 + nr_rec(p->st, elem);
		else
			return  nr_rec(p->st, elem);
	else if (p->st == nullptr && p->dr != nullptr)
		if (p->e == elem)
			return 1 + nr_rec(p->dr, elem);
		else
			return nr_rec(p->dr, elem);
}

int Colectie::nrAparitii(TElem elem) const {
	return nr_rec(rad, elem);
}

int Colectie::dim_rec(PNod p) const
{
	if (p == nullptr)
		return 0;
	else if (p->st == nullptr && p->dr == nullptr)
		return 1;
	else if (p->st != nullptr && p->dr != nullptr)
		return 1+dim_rec(p->st) + dim_rec(p->dr);
	else if (p->st != nullptr && p->dr == nullptr)
		return 1+dim_rec(p->st);
	else if (p->st == nullptr && p->dr != nullptr)
		return 1+dim_rec(p->dr);
}

int Colectie::dim() const
{
	return dim_rec(rad);
}


bool Colectie::vida() const 
{
	if (rad == nullptr)
		return true;
	else
		return false;
}

IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}

void Colectie::distrug_rec(PNod p)
{
	if (p != nullptr)
	{
		distrug_rec(p->stanga());
		distrug_rec(p->dreapta());
		delete p;
	}
}

Colectie::~Colectie() {
	distrug_rec(rad);
}

//Complexitate: O(nr*h), deoarece o operatie de adaugare are complexitate 0(h), iar in acest subalgoritm se efectueaza nr adaugari
void Colectie::adaugaAparitiiMultiple(int nr, TElem elem)
{
	if (nr < 0)
		throw exception();
	for (int i = 0; i < nr; i++)
		adauga(elem);
}