#include "IteratorLI.h"
#include "LI.h"
#include <exception>
using namespace std;

IteratorLI::IteratorLI(const LI& li) : lista(li) {
    curent = li.prim;
}

void IteratorLI::prim() {
    curent = lista.prim;
}

void IteratorLI::urmator() {
    if (curent == -1)
         throw std::exception("Iterator invalid!");
    else
        curent = lista.urm[curent];;
}

bool IteratorLI::valid() const {
    return curent != -1;
}

TElem IteratorLI::element() const {
    if (curent == -1)
        throw std::exception("NU");
    return lista.vector[curent];
}
