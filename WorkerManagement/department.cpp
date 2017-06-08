#include "ALL.h"
extern interFace inter;
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
	cin.clear();
	cin.ignore(100,'\n');
	while (!noToInput || !checkDepNo(noToInput))
	{
		cout << "部门编号输入错误或与已有编号重复，请重新输入" << endl;
		cout << "部门编号：";
		cin >> noToInput;
		cin.clear();
		cin.ignore(100,'\n');
	}
	depNo = noToInput;
	cout << "部门名称：";
	cin >> depName;
	while(!checkDepName(depName))
	{
		cout << "部门名称：";
		cin >> depName;
	}
	system("pause");
	system("cls");
}

bool department::addCount()
{
	if (++count)
		return true;
	return false;
}

int department::getCount() const
{
	return count;
}

department::department()
{
	depName = "No Name";
	depNo = 0;
	count = 0;
}

bool department::reduceCount()
{
	if (--count)
		return true;
	return false;
}

bool department::checkDepName(string toCheck)
{
	if (toCheck.size() < 2 && toCheck.size() > 10)
	{
		cout << "名字过长或过短，请重新输入" << endl;
		return false;
	}
	return true;
}

bool department::checkDepNo(int toCheck)
{
	for (auto &i : inter.department_v)
	{
		if (toCheck == i.getDepNo())
			return false;
	}
	return true;
}

istream & operator>>(istream &in, department &a)
{
	in >> a.depNo >> a.depName >> a.count;
	return in;
}

ostream & operator<<(ostream &out, department &a)
{
	out << a.depNo << a.depName << a.count;
	return out;
}
