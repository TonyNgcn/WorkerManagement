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
	cout << "���۶";
	cin >> saleAmount;
}

void salesman::printSingle() const
{
	basicInfo::printSingle();
	cout << "ְ������Ա" << endl
		<< "���۶" << saleAmount << endl
		<< "���ʣ�" << salary << endl;
}

void salesman::printNoHead() const
{
	basicInfo::printNoHead();
	cout << "ְ������Ա" << ' '
		<< "���۶" << saleAmount << ' '
		<< "���ʣ�" << salary << endl;
}

void salesman::calSalary()
{
	basicInfo::salary = saleAmount*0.04;
}
