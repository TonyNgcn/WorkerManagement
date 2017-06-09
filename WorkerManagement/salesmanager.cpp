#include "ALL.h"
extern interFace inter;
void salesmanager::input()
{
	basicInfo::input();
}

void salesmanager::printSingle() 
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
	cout << "ְ�����۾���" << endl
		<< "���ʣ�" << fixed << salary << endl << endl;
}

void salesmanager::printNoHead() 
{
	calSalary();
	cout << setw(-5) << no << ' ' << setw(-8) << name << ' ' << setw(-3) << sex << ' ';
	inter.getDepName(department);
	cout << ' ';
	birthday.print();
	cout << endl;
	cout << "ְ�����۾���" << ' '
		<< "���ʣ�" << fixed << salary << endl;
}

void salesmanager::calSalary()
{
	double totalAmount = 0;
	for (auto &i : inter.salesman_v)
	{
		if (i.getDepartment() == department)
		{
			totalAmount += i.getSaleAmount();
		}
	}
	salary = 5000 + totalAmount*0.005;
}

istream & operator>>(istream &in, salesmanager &a)
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
	in >> noToInput >> nameToInput >> sexToInput >> depToInput >> yearToInput >> monthToInput >> dayToInput >> salaryToInput >> workPostToInput;
	a.birthday.setDate(yearToInput, monthToInput, dayToInput);
	a.no = noToInput;
	a.name = nameToInput;
	a.sex = sexToInput;
	a.department = depToInput;
	a.salary = salaryToInput;
	a.workPost = workPostToInput;
	return in;
}

ostream & operator<<(ostream &out, salesmanager &a)
{
	out << a.no << ' ' << a.name << ' ' << a.sex << ' ' << a.department << ' ' << a.birthday << ' ' << a.salary << ' ' << a.workPost;
	return out;
}

salesmanager::salesmanager()
{
	workPost = 3;
	salary = 0;
}