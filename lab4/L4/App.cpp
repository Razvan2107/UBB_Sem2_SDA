#include <iostream>
#include <assert.h>

#include "TestScurt.h"
#include "TestExtins.h"
#include "LI.h"

void TestStergeIntre()
{
    LI lista = LI();
    lista.adaugaSfarsit(5);
    lista.adaugaSfarsit(6);
    lista.adaugaSfarsit(2);
    lista.adaugaSfarsit(1);
    lista.adaugaSfarsit(9);
    lista.stergeIntre(2, 4);
    assert(lista.dim() == 2);
}


int main() {
        testAll();
        testAllExtins();
    TestStergeIntre();
    std::cout << "Finished LI Tests!" << std::endl;
}