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
	in >> a.no >> a.name >> a.sex >> a.department >> a.birthday >> a.salary >> a.workPost;
	return in;
}

ostream & operator<<(ostream &out, manager &a)
{
	out << a.no << a.name << a.sex << a.department << a.birthday << a.salary << a.workPost;
	return out;
}
