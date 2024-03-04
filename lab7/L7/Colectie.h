#pragma once

#define NULL_TELEM -1
typedef int TElem;

class IteratorColectie;

//referire a clasei Nod
class Nod;

//se defineste tipul PNod ca fiind adresa unui Nod
typedef Nod* PNod;

class Nod
{
private:
	TElem e;
	PNod st, dr;
public:
	friend class Colectie;

	//constructor
	Nod(TElem e, PNod st, PNod dr);
	TElem element();
	PNod stanga();
	PNod dreapta();
};


class Colectie
{
	friend class IteratorColectie;

private:
	PNod rad;
	PNod adauga_rec(PNod p, TElem e);
	PNod sterge_rec(PNod p, TElem e, bool& sters);
	PNod minim(PNod p);
	bool cauta_rec(PNod p, TElem e) const;
	int	dim_rec(PNod p) const;
	int nr_rec(PNod p, TElem elem) const;
	void distrug_rec(PNod);
public:
	//constructorul implicit
	Colectie();

	//adauga un element in colectie
	void adauga(TElem e);

	//sterge o aparitie a unui element din colectie
	//returneaza adevarat daca s-a putut sterge
	bool sterge(TElem e);

	//verifica daca un element se afla in colectie
	bool cauta(TElem elem) const;

	//returneaza numar de aparitii ale unui element in colectie
	int nrAparitii(TElem elem) const;


	//intoarce numarul de elemente din colectie;
	int dim() const;

	//verifica daca colectia e vida;
	bool vida() const;

	//returneaza un iterator pe colectie
	IteratorColectie iterator() const;

	// destructorul colectiei
	~Colectie();

	//adauga nr aparitii ale elementului elem in colectie
	//arunca exceptie in cazul in care nr este negativ
	void adaugaAparitiiMultiple(int nr, TElem elem);
};

