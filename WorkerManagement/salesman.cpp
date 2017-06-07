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
	cout << "销售额：";
	cin >> saleAmount;
}

void salesman::printSingle() 
{
	calSalary();
	basicInfo::printSingle();
	cout << "职务：销售员" << endl
		<< "销售额：" << saleAmount << endl
		<< "工资：" << fixed << salary << endl << endl;
}

void salesman::printNoHead() 
{
	calSalary();
	basicInfo::printNoHead();
	cout << "职务：销售员" << ' '
		<< "销售额：" << saleAmount << ' '
		<< "工资：" << fixed << salary << endl;
}

void salesman::calSalary()
{
	basicInfo::salary = saleAmount*0.04;
}
