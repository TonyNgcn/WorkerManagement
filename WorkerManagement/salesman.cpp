#include "salesman.h"

salesman::salesman()
{
}

double salesman::getSaleAmount()
{
	return saleAmount;
}

void salesman::input()
{
	basicInfo::input();
	cout << "ÏúÊÛ¶î£º";
	cin >> saleAmount;
}

void salesman::calSalary()
{
	basicInfo::salary = saleAmount*0.04;
}
