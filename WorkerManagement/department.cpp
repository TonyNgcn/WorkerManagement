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
	cout << "��������";
	cin >> depName;
}
