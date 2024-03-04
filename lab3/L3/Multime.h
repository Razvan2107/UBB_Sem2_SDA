#pragma once

//#define NULL_TELEM -1
typedef int TElem;

class IteratorMultime;

class Nod;

typedef Nod* PNod;

class Nod
{
private:
	TElem e;
	PNod urm;

public:
	friend class Multime;

	//constructor
	Nod(TElem e, PNod urm);
	TElem element();
	PNod urmator();
};

class Multime {
	friend class IteratorMultime;

private:
	/* aici e reprezentarea */
	PNod prim;

public:
	//constructorul implicit
	Multime();

	//adauga un element in multime
	//returneaza adevarat daca elementul a fost adaugat (nu exista deja in multime)
	bool adauga(TElem e);

	//sterge un element din multime
	//returneaza adevarat daca elementul a existat si a fost sters
	bool sterge(TElem e);

	//verifica daca un element se afla in multime
	bool cauta(TElem elem) const;


	//intoarce numarul de elemente din multime;
	int dim() const;

	//verifica daca multimea e vida;
	bool vida() const;

	//returneaza un iterator pe multime
	IteratorMultime iterator() const;

	// destructorul multimii
	~Multime();

	//reuniune a multimii curente si o multime oarecare
	void reuniune(const Multime& b);
};




