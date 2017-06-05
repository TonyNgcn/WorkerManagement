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
	cout << "���ű�ţ�";
	int noToInput = 0;
	cin >> noToInput;
	while (!noToInput)
	{
		cout << "���ű�������������������" << endl;
		cout << "���ű�ţ�";
		cin >> noToInput;
	}
	depNo = noToInput;
	cout << "�������ƣ�";
	cin >> depName;
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
