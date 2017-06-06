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
	cout << "销售额：";
	cin >> saleAmount;
}

void salesman::printSingle() const
{
	basicInfo::printSingle();
	cout << "职务：销售员" << endl
		<< "销售额：" << saleAmount << endl
		<< "工资：" << salary << endl;
}

void salesman::printNoHead() const
{
	basicInfo::printNoHead();
	cout << "职务：销售员" << ' '
		<< "销售额：" << saleAmount << ' '
		<< "工资：" << salary << endl;
}

void salesman::calSalary()
{
	basicInfo::salary = saleAmount*0.04;
}
