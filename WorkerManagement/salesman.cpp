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
	cin.ignore(100,'\n');
	while (saleAmount < 0)
	{
		cout << "�����������������" << endl;
		cout << "���۶";
		cin >> saleAmount;
		cin.clear();
		cin.ignore(100,'\n');
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
		<< "���۶" << setprecision(2) << fixed << saleAmount << endl
		<< "���ʣ�" << setprecision(2) << fixed << salary << endl << endl;
}

void salesman::printNoHead() 
{
	calSalary();
	cout << setw(3) << no << ' ' << setw(7) << name << ' ' << setw(3) << sex << ' ';
	inter.getDepName(department);
	cout << ' ';
	birthday.print();
	//cout << endl;
	cout << " ְ������Ա" << ' '
		<< "���۶" << setprecision(2) << fixed << saleAmount << ' '
		<< "���ʣ�" << setprecision(2) << fixed << salary << endl;
}

void salesman::calSalary()
{
	basicInfo::salary = saleAmount*0.04;
}

bool salesman::changeSaleAmount()
{
	cout << "���۶";
	double saleAmountToChange = -1;
	cin >> saleAmountToChange;
	cin.clear();
	cin.ignore(100, '\n');
	while (saleAmountToChange<0)
	{
		cout << "��������������������۶";
		cin >> saleAmountToChange;
		cin.clear();
		cin.ignore(100, '\n');
	}
	saleAmount = saleAmountToChange;
	return true;
}

bool salesman::changeWorkTime()
{
	return false;
}

istream & operator>>(istream &in, salesman &a)
{
	int noToInput;
	string nameToInput;
	string sexToInput;
	int depToInput;
	int yearToInput;
	int monthToInput;
	int dayToInput;
	double salaryToInput;
	int workPostToInput;
	double salesAmountToInput;
	in >> noToInput >> nameToInput >> sexToInput >> depToInput >> yearToInput >> monthToInput >> dayToInput >> salaryToInput >> workPostToInput >> salesAmountToInput;
	a.birthday.setDate(yearToInput, monthToInput, dayToInput);
	a.no = noToInput;
	a.name = nameToInput;
	a.sex = sexToInput;
	a.department = depToInput;
	a.salary = salaryToInput;
	a.workPost = workPostToInput;
	a.saleAmount = salesAmountToInput;
	return in;
}

ostream & operator<<(ostream &out, salesman &a)
{
	out << a.no << ' ' << a.name << ' ' << a.sex << ' ' << a.department << ' ' << a.birthday << ' ' << a.salary << ' ' << a.workPost << ' ' << a.saleAmount;
	return out;
}
