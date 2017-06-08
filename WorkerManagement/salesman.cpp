#include "ALL.h"
extern interFace inter;
salesman::salesman()
{
	workPost = 1;
	salary = 0;
	saleAmount = -1;
}

double salesman::getSaleAmount()
{
	return saleAmount;
}

void salesman::input()
{
	basicInfo::input();
	cout << "���۶";
	saleAmount = -1;
	cin >> saleAmount;
	cin.clear();
	cin.ignore();
	while (saleAmount < 0)
	{
		cout << "�����������������" << endl;
		cout << "���۶";
		cin >> saleAmount;
		cin.clear();
		cin.ignore();
	}
}

void salesman::printSingle() 
{
	calSalary();
	cout << "Ա���ţ�" << no << endl
		<< "������" << name << endl
		<< "�Ա�" << sex << endl
		<< "���ţ�";
	inter.getDepName(department);
	cout << endl << "��������:";
	birthday.print();
	cout << endl;
	cout << "ְ������Ա" << endl
		<< "���۶" << fixed << saleAmount << endl
		<< "���ʣ�" << fixed << salary << endl << endl;
}

void salesman::printNoHead() 
{
	calSalary();
	cout << setw(-5) << no << ' ' << setw(-8) << name << ' ' << setw(-3) << sex << ' ';
	inter.getDepName(department);
	cout << ' ';
	birthday.print();
	cout << endl;
	cout << "ְ������Ա" << ' '
		<< "���۶" << saleAmount << ' '
		<< "���ʣ�" << fixed << salary << endl;
}

void salesman::calSalary()
{
	basicInfo::salary = saleAmount*0.04;
}
