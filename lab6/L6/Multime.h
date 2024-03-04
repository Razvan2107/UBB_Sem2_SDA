#pragma once

#define MAX 10 //numarul maxim de locatii din tabela
typedef int TElem;

class IteratorMultime;

class Nod; //referire a clasei Nod
typedef Nod* PNod; //se defineste tipul PNod ca fiind adresa unui Nod dintr-o lista inlantuita

class Nod
{
private:
	TElem e;
	PNod urm;
public:
	friend class Multime;
	friend class IteratorMultime;
	//constructor
	Nod(TElem e, PNod urm);
};

class Multime {
	friend class IteratorMultime;

private:
	//reprezentare folosind o Tabela de Dispersie - rezolvare coliziuni prin liste
	int m; //numarul de locatii din tabela de dispersie
	PNod l[MAX]; //listele independente - vector static
	int d(TElem e); //functia de dispersie

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
	bool cauta(TElem elem);


	//intoarce numarul de elemente din multime;
	int dim() const;

	//verifica daca multimea e vida;
	bool vida() const;

	//returneaza un iterator pe multime
	IteratorMultime iterator() const;

	// destructorul multimii
	~Multime();

	//adauga toaate elementele din multimea b in multimea curenta
	void reuniune(const Multime& b);
};




