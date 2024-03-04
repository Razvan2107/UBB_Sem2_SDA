#include "Multime.h"
#include "IteratorMultime.h"

#include <iostream>
#include <math.h>


Nod::Nod(TElem e, PNod urm)
{
	this->e = e;
	this->urm = urm;
}

int Multime::d(TElem e)
{
	//dispersia prin diviziune
	return  abs(e) % m;
}

Multime::Multime() {
	m = MAX; //initializam m cu o valoare predefinita
	//daca va fi cazul, se poate redimensiona tabela si sa se redisperseze elementele
	//se intializeaza listele inlantuite ca fiind vide
	for (int i = 0; i < m; i++)
		l[i] = nullptr;
}

//Complexitate: 0(1)
//Worst Case: 0(n)
bool Multime::adauga(TElem elem) {
	//locatia de dispersie a cheii
	int i = d(elem);
	//verificam daca elementul exista
	PNod p = l[i];
	if (p!=nullptr)
		while (p != nullptr)
		{
			if (p->e == elem)
				return false;
			p = p->urm;
		}
	//se creeaza un nod
	PNod nou = new Nod(elem, nullptr);
	//se adauga in capul listei inlantuite de la locatia i
	nou->urm = l[i];
	l[i] = nou;
	return true;
}

//Complexitate: 
//Best Case: 0(1) cand elementul care se va sterge e primul
//Worst Case: 0(n) cand elementul care se va sterge e ultimul, parcurgandu se toate elementele
//Average Case: 0(n)
bool Multime::sterge(TElem elem) {
	//locatia de dispersie a cheii
	int i = d(elem);
	//lista i e vida
	if (l[i] == nullptr)
		return false;
	//lista i are un singur element
	if(l[i]->urm == nullptr)
		if (l[i]->e == elem)
		{
			l[i] = nullptr;
			return true;
		}
	//primul e elementul cautat
	if (l[i]->e == elem)
	{
		l[i] = l[i]->urm;
		return true;
	}
	//lista i are mai mult de un element
	PNod ant = l[i], p=l[i]->urm;
	while (p != nullptr)
	{
		if (p->e == elem && p->urm!=nullptr)
		{
			ant->urm = p->urm;
			return true;
		}
		else if (p->e == elem && p->urm == nullptr)
		{
			ant->urm = nullptr;
			return true;
		}
		ant = p;
		p = p->urm;
	}
	return false;
}

//Complexitate:
//Best case: 0(1) cand elementul cautat e primul
//Worst case: 0(n) cand elemntul cautat e ultimul, unde n reprezinta lungimea listei de dispersie a cheii
//Average case: 0(n)
bool Multime::cauta(TElem elem){
	//locatia de dispersie a cheii
	int i = d(elem);
	//verificam daca elementul exista
	PNod p = l[i];
	while (p != nullptr)
	{
		if (p->e == elem)
			return true;
		p = p->urm;
	}
	return false;
}

//Complexitate: 0(n*m) unde n e lungimea listei de dispersie a cheii si m numarul de locatii din tabela de dispersie
int Multime::dim() const {
	//parcurgem fiecare lista inlantuita si crestem contorul pentru fiecare element existent
	int nr = 0;
	for (int i = 0; i < m; i++)
	{
		PNod p = l[i];
		while (p != nullptr)
		{
			nr++;
			p = p->urm;
		}
	}
	return nr;
}

//Complexitate: 0(1)
bool Multime::vida() const {
	//verificam daca fiecare lista e vida
	for (int i = 0; i < m; i++)
		if (l[i] != nullptr)
			return false;
	return true;
}

//Complexitate: 0(1)
Multime::~Multime() {
	//se elibereaza memoria alocata listelor
	for (int i = 0; i < m; i++)
		//se elibereaza memoria pentru lista i
		while (l[i] != nullptr)
		{
			PNod p = l[i];
			l[i] = l[i]->urm;
			delete p;
		}
}

IteratorMultime Multime::iterator() const {
	return IteratorMultime(*this);
}

//Complexitate: 0(n) unde n este numarul de elemente al multimii b
void Multime::reuniune(const Multime& b)
{
	for (int i = 0; i < b.m; i++)
	{
		PNod p = b.l[i];
		while (p != nullptr)
			adauga(p->e), p=p->urm;
	}
}
