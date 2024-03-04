#include <assert.h>
#include <exception>

#include "TestExtins.h"
#include "LI.h"
#include "IteratorLI.h"

using namespace std;

void testCreare() {
    LI lista = LI();
    assert(lista.vida());
    IteratorLI it = lista.iterator();
    assert(!it.valid());
    try {
        it.urmator();
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }
    assert(lista.dim() == 0);
}

void testAdauga() {
    LI lista = LI();
    lista.adaugaSfarsit(1);
    assert(!lista.vida());
    assert(lista.dim() == 1);
    assert(lista.element(1) == 1);
    try {
        lista.element(2);
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }

    for (int i = 0; i <= 100; i++) {
        lista.adaugaSfarsit(i);
        lista.adauga(lista.dim() - 1, i);
        try {
            lista.adauga((i + 2) * 2, i);
            assert(false);
        }
        catch (exception&) {
            assert(true);
        }

        assert(lista.dim() == 2 * (i + 1) + 1);
    }
    int i = 3, v = 0;
    while (i <=lista.dim()) {
        assert(lista.element(i) == v);
        i++;
        i++;
        v++;
    }
}

void testModificaStergeCauta() {
    LI lista = LI();
    for (int i = 0; i <= 100; i++) {
        lista.adaugaSfarsit(i);
    }
    assert(lista.dim() == 101);
    
    assert(lista.cauta(50) == 51);
    assert(lista.cauta(100) == 101);
    assert(lista.sterge(101) == 100);
    try {
        lista.sterge(101);
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }
    assert(lista.dim() == 100);
    assert(lista.cauta(100) == -1);
    assert(lista.cauta(99) == 100);
    int v = 99;
    for (int i = 1; i <=100; i++) {
        lista.modifica(i, v);
        v--;
    }
    assert(lista.element(99) == 1);
    assert(lista.cauta(99) == 1);
    assert(lista.cauta(0) == 100);
    assert(lista.cauta(50) == 50);
    try {
        lista.modifica(v, v);
        assert(false);
    }
    catch (exception&) {
        assert(true);
    }
}

void testAllExtins() {
    testCreare();
    testAdauga();
    testModificaStergeCauta();
}