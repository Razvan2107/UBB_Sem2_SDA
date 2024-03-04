#include "IteratorMultime.h"
#include "Multime.h"
#include <iostream>


IteratorMultime::IteratorMultime(const Multime& m) : multime(m) {
	curent = m.prim;
}


void IteratorMultime::prim() {
	curent = multime.prim;
}


void IteratorMultime::urmator() {
	curent = curent->urmator();
}


TElem IteratorMultime::element() const {
	return curent->element();
}

bool IteratorMultime::valid() const {
	return curent!=nullptr;
}
