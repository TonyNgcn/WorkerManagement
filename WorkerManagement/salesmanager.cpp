#include "ALL.h"
extern interFace inter;
void salesmanager::input()
{
	basicInfo::input();
}

void salesmanager::printSingle() 
{
	calSalary();
	basicInfo::printSingle();
	cout << "ְ�����۾���" << endl
		<< "���ʣ�" << fixed << salary << endl << endl;
}

void salesmanager::printNoHead() 
{
	calSalary();
	basicInfo::printNoHead();
	cout << "ְ�����۾���" << ' '
		<< "���ʣ�" << fixed << salary << endl;
}

void salesmanager::calSalary()
{
	double totalAmount = 0;
	for (auto &i : inter.salesman_v)
	{
		if (i.getDepartment() == department)
		{
			totalAmount += i.getSaleAmount();
		}
	}
	salary = 5000 + totalAmount*0.005;
}

salesmanager::salesmanager()
{

}