#include "ALL.h"
interFace inter;
int main()
{
	inter.addDep();
	inter.addDep();
	for (int i = 0; i < 3; i++)
		inter.addPerson();
	for (auto i : inter.salesman_v)
	{
		i.printSingle();
	}
	for (auto i : inter.salesmanager_v)
	{
		i.printSingle();
	}
	return 0;
}