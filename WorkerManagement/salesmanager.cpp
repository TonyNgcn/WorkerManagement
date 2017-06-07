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
	cout << "职务：销售经理" << endl
		<< "工资：" << fixed << salary << endl << endl;
}

void salesmanager::printNoHead() 
{
	calSalary();
	basicInfo::printNoHead();
	cout << "职务：销售经理" << ' '
		<< "工资：" << fixed << salary << endl;
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