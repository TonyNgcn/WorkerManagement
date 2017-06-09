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
	cout << "���ű�ţ�";
	int noToInput = 0;
	cin >> noToInput;
	cin.clear();
	cin.ignore(100,'\n');
	while (!noToInput || !checkDepNo(noToInput))
	{
		cout << "���ű���������������б���ظ�������������" << endl;
		cout << "���ű�ţ�";
		cin >> noToInput;
		cin.clear();
		cin.ignore(100,'\n');
	}
	depNo = noToInput;
	cout << "�������ƣ�";
	cin >> depName;
	while(!checkDepName(depName))
	{
		cout << "�������ƣ�";
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
		cout << "���ֹ�������̣�����������" << endl;
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

double department::calAverageSalary()
{
	double averageSalary = 0;
	int count = 0;
	inter.calAllSalary();
	for (auto i : inter.temp_v)
	{
		if (i->getDepartment() == depNo)
		{
			count++;
			averageSalary += i->getSalary();
		}
	}
	averageSalary /= count;
	return averageSalary;
}

istream & operator>>(istream &in, department &a)
{
	int noToInput;
	string nameToInput;
	int countToInput;
	in >> noToInput >> nameToInput >> countToInput;
	a.depNo = noToInput;
	a.depName = nameToInput;
	a.count = countToInput;
	return in;
}

ostream & operator<<(ostream &out, department &a)
{
	out << a.depNo<<' ' << a.depName<<' ' << a.count;
	return out;
}
