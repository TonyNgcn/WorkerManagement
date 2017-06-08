#include "ALL.h"

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
	cin.ignore();
	while (!noToInput)
	{
		cout << "���ű�������������������" << endl;
		cout << "���ű�ţ�";
		cin >> noToInput;
		cin.clear();
		cin.ignore();
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
