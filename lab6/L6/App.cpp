//TAD Multime–reprezentare folosind o TD cu rezolvare coliziuni prin liste independente.

#include "TestExtins.h"
#include "TestScurt.h"
#include "Multime.h"
#include <iostream>
#include <assert.h>
using namespace std;

void TestCerinta()
{
	Multime a;
	for (int i = 0; i < 10; i++)
		a.adauga(i);
	assert(a.dim() == 10);

	Multime b;
	for (int i = 10; i < 15; i++)
		b.adauga(i);
	assert(b.dim() == 5);

	//fac reuniunea cu o multime care nu are niciun element in comun
	a.reuniune(b);
	assert(a.dim() == 15);

	Multime c;
	for (int i = 0; i < 5; i++)
		c.adauga(i);
	assert(c.dim() == 5);

	//fac reuniunea cu o multime care are toate elementele in comun
	a.reuniune(c);
	assert(a.dim() == 15);
}

int main() {
		
		TestCerinta();
		testAll();
		testAllExtins();

	cout << "That's all!" << endl;

}
