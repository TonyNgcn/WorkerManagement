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
	cin.ignore();
	while (workHour < 0)
	{
		cout << "�����������������" << endl;
		cout << "����ʱ�䣺";
		cin >> workHour;
		cin.clear();
		cin.ignore();
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
