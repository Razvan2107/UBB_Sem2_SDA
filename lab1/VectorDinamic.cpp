#include "VectorDinamic.h"
#include "IteratorVectorDinamic.h"
#include <exception>
#include<iostream>


void VectorDinamic::redim() {
	dimensiune_max = dimensiune_max * 2;
	int* vaux = new int[dimensiune_max];
	for (int i = 0; i < frecventa_curenta; i++)
		vaux[i] = v[i];
	delete[] v;
	v = vaux;
}


VectorDinamic::VectorDinamic(int cp) {
	dimensiune_max = cp;
}



VectorDinamic::~VectorDinamic() {
	delete[] v;
}



int VectorDinamic::dim() const {
	return frecventa_curenta;
}



TElem VectorDinamic::element(int i) const {
	return v[i];
}



void VectorDinamic::adaugaSfarsit(TElem e) {
	if (frecventa_curenta == dimensiune_max)
		redim();
	v[frecventa_curenta++] = e;
}




TElem VectorDinamic::modifica(int i, TElem e) {
	int valoare_veche = v[i];
	v[i] = e;
	return valoare_veche;
}


TElem VectorDinamic::sterge(int i) {
	int valoare_stearsa = v[i];
	for (int j = i; j < frecventa_curenta; j++)
		v[j] = v[j + 1];
	frecventa_curenta--;
	return valoare_stearsa;
}

IteratorVectorDinamic VectorDinamic::iterator() {
	return IteratorVectorDinamic(*this);
}
void VectorDinamic::print_elem() {
	for (int i = 0; i < frecventa_curenta; i++)
		std::cout << v[i] << " ";
}