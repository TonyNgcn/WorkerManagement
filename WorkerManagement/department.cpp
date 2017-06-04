#include "department.h"

string department::getDepName() const
{
	return depName;
}

int department::getDepNo() const
{
	return depNo;
}

void department::printAllDep() const
{
	cout << depNo << '-' << depName << endl;
}

void department::input()
{
	cout << "部门编号：";
	int noToInput = 0;
	cin >> noToInput;
	while (!noToInput)
	{
		cout << "部门编号输入错误，请重新输入" << endl;
		cout << "部门编号：";
		cin >> noToInput;
	}
	cout << "部门名称";
	cin >> depName;
}
