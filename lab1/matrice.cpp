#include "matrice.h"

#include <exception>
#include <iostream>

using namespace std;


//Complexitate: 0(n) - unde n este size-ul curent (numarul de elemente din matrice)
void Matrice::redim() {
	capacitate_maxima = capacitate_maxima * 2;
	int* a = new int[capacitate_maxima];
	int* b = new int[capacitate_maxima];
	for (int i = 0; i < size; i++)
		a[i] = v_col[i], b[i] = valoare[i];
	v_col = a, valoare = b;
}


//Complexitate: 0(n) - unde n este capacitatea maxima
Matrice::Matrice(int m, int n) {
	if (m <= 0 || n <= 0)
		throw exception("NU");
	else
	{
		linii = m;
		coloane = n;
		capacitate_maxima;
		size = -1;
		v_col = new int[capacitate_maxima];
		v_lin = new int[linii + 1];
		valoare = new int[capacitate_maxima];
		for (int i = 0; i <= linii; i++)
			v_lin[i] = 1;
		for (int i = 0; i <= capacitate_maxima; i++)
			v_col[i] = NULL_TELEMENT, valoare[i] = NULL_TELEMENT;
	}
}


//Complexitate: 0(1)
int Matrice::nrLinii() const {
	return linii;
}


//Complexitate: 0(1)
int Matrice::nrColoane() const {
	return coloane;
}


//Complexitate: 0(i) - numarul de linii
TElem Matrice::element(int i, int j) const {
	if (i<0 || i>=linii || j<0 || j>=coloane)
		throw exception("NU");
	else
	{
		int nr_elemente = v_lin[i + 1] - v_lin[i];
		int nr_elemente_pana_la_i = 0;
		for (int k = 0; k < i; k++)
			nr_elemente_pana_la_i += v_lin[k + 1] - v_lin[k];
		int val = -1;
		for (int l = nr_elemente_pana_la_i; l < nr_elemente + nr_elemente_pana_la_i; l++)
			if (v_col[l] == j)
			{
				val = valoare[l];
				break;
			}
		if (val == -1)	return NULL_TELEMENT;
		else	return val;
	}
}



//Complexitate - 0(max(nr_linii,new_size - size)) unde new_size - size reprezinta numarul de elemente adaugate, cu o linie mai mare decat cea unde incercam sa adaugam
TElem Matrice::modifica(int i, int j, TElem e) {
	if (i < 0 || i >=linii || j < 0 || j >=coloane)
		throw exception("NU");
	else
	{
		if (size == capacitate_maxima)
			redim();
		for (int k = i + 1; k <=linii; k++)
			v_lin[k]++;
		size++;

		int new_size = size;
		for (int l = i + 1; l <linii; l++)
			new_size += v_lin[l + 1] - v_lin[l];
		if (new_size == size)
		{
			if (valoare[size] != NULL_TELEMENT)
			{
				for (int k = i + 1; k <= linii; k++)
					v_lin[k]--;
				size--;
				v_col[size] = j;
				int val_veche = valoare[size];
				valoare[size] = e;
				return val_veche;
			}
			else
			{
				v_col[new_size] = v_col[size];
				valoare[new_size] = valoare[size];
				int val_veche = valoare[new_size];
				v_col[size] = j;
				valoare[size] = e;
			}
		}
		else
		{
			if (valoare[size] != NULL_TELEMENT)
			{
				for (int k = i + 1; k <= linii; k++)
					v_lin[k]--;
				size--;
				int val_veche = valoare[size];
				v_col[size] = j;
				valoare[size] = e;
				return val_veche;
			}
			else
			{
				int cate_pozitii = size;
				while (new_size > size)
				{
					v_col[cate_pozitii] = v_col[cate_pozitii - 1];
					valoare[cate_pozitii] = valoare[cate_pozitii - 1];
					new_size--;
					cate_pozitii--;
				}
				v_col[cate_pozitii] = j;
				valoare[cate_pozitii] = e;
			}
		}
	}
}


//Complexitate - 0(i) unde i este este linia pe care se va face operatia
int Matrice::numarElementeNenule(int linie) const
{
	if (linie <= 0 || linie >= linii)
		throw exception("NU");
	else
	{
		for (int i = 0; i < linii; i++)
			if (i == linie)
			{
				return v_lin[i + 1] - v_lin[i];
			}
		return 0;
	}
}