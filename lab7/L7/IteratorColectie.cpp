#include "IteratorColectie.h"
#include "Colectie.h"


IteratorColectie::IteratorColectie(const Colectie& c) : col(c) {
	prim();
}

void IteratorColectie::prim() {
	curent = col.rad;
	while (stiva.empty())
		stiva.pop();
	while (curent != nullptr)
	{
		stiva.push(curent);
		curent = curent->stanga();
	}
	if (stiva.empty())
		curent = stiva.top();
	else
		curent = nullptr;
}


void IteratorColectie::urmator() {
	if (!valid())
		throw bad_exception();

	PNod nod = stiva.top();
	stiva.pop();

	if (nod->dreapta() != nullptr)
	{
		nod = nod->dreapta();
		while (nod != nullptr)
		{
			stiva.push(nod);
			nod = nod->stanga();
		}
	}
	if (stiva.empty())
		curent = stiva.top();
	else
		curent = nullptr;
}


bool IteratorColectie::valid() const {
	if (curent != nullptr)
		return true;
	return false;
}



TElem IteratorColectie::element() const {
	if (!valid())
		throw bad_exception();
	return -1;
}
