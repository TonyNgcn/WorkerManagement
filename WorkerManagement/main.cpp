#include "ALL.h"
interFace inter;
int main()
{
	inter.addDep();
	for (int i = 0; i < 3; i++)
		inter.addPerson();
	inter.sortAndPrintAll();
	inter.vectorToFile();
	return 0;
}