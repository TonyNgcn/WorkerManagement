#include "ALL.h"
interFace inter;
int main()
{
	//inter.addDep();
	inter.fileToVector();
	inter.addPerson();
	inter.addPerson();

	inter.printByPages();
	inter.vectorToFile();
	return 0;
}