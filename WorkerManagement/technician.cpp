#include "ALL.h"
extern interFace inter;
technician::technician()
{
	workHour = -1;
	salary = 0;
	workPost = 2;
}

int technician::getWorkHour()
{
	return workHour;
}

void technician::input()
{
	basicInfo::input();
	workHour = -1;
	cout << "����ʱ�䣺";
	cin >> workHour;
	cin.clear();
	cin.ignore(100,'\n');
	while (workHour < 0)
	{
		cout << "�����������������" << endl;
		cout << "����ʱ�䣺";
		cin >> workHour;
		cin.clear();
		cin.ignore(100,'\n');
	}
}

void technician::printSingle() 
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
	cout << "ְ�񣺼���Ա" << endl
		<< "����ʱ�䣨Сʱ����" << workHour << endl
		<< "���ʣ�" << fixed << salary << endl << endl;
}

void technician::printNoHead() 
{
	calSalary();
	cout << setw(-5) << no << ' ' << setw(-8) << name << ' ' << setw(-3) << sex << ' ';
	inter.getDepName(department);
	cout << ' ';
	birthday.print();
	cout << endl;
	cout << "ְ�񣺼���Ա" << ' '
		<< "����ʱ�䣨Сʱ����" << workHour << ' '
		<< "���ʣ�" << fixed << salary << endl;
}

void technician::calSalary()
{
	basicInfo::salary = workHour * 100;
}

bool technician::changeWorkTime()
{
	cout << "����ʱ�䣺";
	int workHourToChange = -1;
	cin >> workHourToChange;
	cin.clear();
	cin.ignore(100, '\n');
	while (workHourToChange<0)
	{
		cout << "����������������빤��ʱ�䣺";
		cin >> workHourToChange;
		cin.clear();
		cin.ignore(100, '\n');
	}
	workHour = workHourToChange;
	return true;
}

bool technician::changeSaleAmount()
{
	return false;
}

istream & operator>>(istream &in, technician &a)
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
	int workHourToInput;
	in >> noToInput >> nameToInput >> sexToInput >> depToInput >> yearToInput >> monthToInput >> dayToInput >> salaryToInput >> workPostToInput >> workHourToInput;
	a.birthday.setDate(yearToInput, monthToInput, dayToInput);
	a.no = noToInput;
	a.name = nameToInput;
	a.sex = sexToInput;
	a.department = depToInput;
	a.salary = salaryToInput;
	a.workPost = workPostToInput;
	a.workHour = workHourToInput;
	return in;
}

ostream & operator<<(ostream &out, technician &a)
{
	out << a.no << ' ' << a.name << ' ' << a.sex << ' ' << a.department << ' ' << a.birthday << ' ' << a.salary << ' ' << a.workPost << ' ' << a.workHour;
	return out;
}
