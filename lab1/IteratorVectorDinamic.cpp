#include "IteratorVectorDinamic.h"
#include "VectorDinamic.h"


IteratorVectorDinamic::IteratorVectorDinamic(const VectorDinamic& _v) : vector(_v) {
	prim();
}



void IteratorVectorDinamic::prim() {
	elem_curent = vector.v;
}



bool IteratorVectorDinamic::valid() const {
	if (elem_curent < vector.v + vector.frecventa_curenta)
		return true;
	else
		return false;
}



TElem IteratorVectorDinamic::element() const {
	return *elem_curent;
}



void IteratorVectorDinamic::urmator() {
	elem_curent++;
}