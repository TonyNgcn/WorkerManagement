#include "ALL.h"

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

void salesman::printSingle() 
{
	calSalary();
	basicInfo::printSingle();
	cout << "ְ������Ա" << endl
		<< "���۶" << saleAmount << endl
		<< "���ʣ�" << fixed << salary << endl << endl;
}

void salesman::printNoHead() 
{
	calSalary();
	basicInfo::printNoHead();
	cout << "ְ������Ա" << ' '
		<< "���۶" << saleAmount << ' '
		<< "���ʣ�" << fixed << salary << endl;
}

void salesman::calSalary()
{
	basicInfo::salary = saleAmount*0.04;
}
