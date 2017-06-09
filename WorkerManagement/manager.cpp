#include "ALL.h"
extern interFace inter;
manager::manager()
{
	salary = 8000;
	workPost = 4;
}

void manager::input()
{
	basicInfo::input();
}

void manager::printSingle()
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
	cout << "ְ�񣺾���" << endl
		<< "���ʣ�" << salary << endl << endl;
}

void manager::printNoHead() 
{
	calSalary();
	cout << setw(-5) << no << ' ' << setw(-8) << name << ' ' << setw(-3) << sex << ' ';
	inter.getDepName(department);
	cout << ' ';
	birthday.print();
	cout << endl;
	cout << "ְ�񣺾���" << ' '
		<< "���ʣ�" << fixed << salary << endl;
}

void manager::calSalary()
{
	basicInfo::salary = 8000;
}

istream & operator>>(istream &in, manager &a)
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

ostream & operator<<(ostream &out, manager &a)
{
	out << a.no << ' ' << a.name << ' ' << a.sex << ' ' << a.department << ' ' << a.birthday << ' ' << a.salary << ' ' << a.workPost;
	return out;
}
