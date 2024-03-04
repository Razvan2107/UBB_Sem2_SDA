//TAD Colectie cu elemente de tip TComparabil - reprezentare prin perechi de forma (element, frecventa), folosind un ABC reprezentat inlantuit cu alocare dinamica
#include <iostream>
#include "TestExtins.h"
#include "TestScurt.h"
#include <assert.h>
#include "Colectie.h"
using namespace std;

void TestCerinta()
{
	Colectie c;
	c.adauga(5);
	c.adauga(1);
	c.adauga(10);
	c.adauga(7);
	c.adauga(1);
	c.adauga(11);
	c.adauga(-3);
	assert(c.dim() == 7);

	c.adaugaAparitiiMultiple(3, 8);
	assert(c.dim() == 10);

	c.adaugaAparitiiMultiple(0, 56);
	assert(c.dim() == 10);

	try
	{
		c.adaugaAparitiiMultiple(-3, 80);
		assert(false);
	}
	catch (exception&)
	{
		assert(true);
	}
	assert(c.dim() == 10);

	c.adaugaAparitiiMultiple(20, 4);
	assert(c.dim() == 30);
}

int main() {
	TestCerinta();
		testAll();
		testAllExtins();
	cout << "End";
}
