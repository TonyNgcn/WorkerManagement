#include "ALL.h"
interFace inter;
int main()
{
	inter.addDep();
	inter.addDep();
	for (int i = 0; i < 3; i++)
		inter.addPerson();
	inter.sortAndPrintAll();
	return 0;
}