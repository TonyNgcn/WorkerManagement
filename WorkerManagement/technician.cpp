#include "ALL.h"
extern interFace inter;
technician::technician()
{
}

int technician::getWorkHour()
{
	return workHour;
}

void technician::input()
{
	basicInfo::input();
	cout << "����ʱ�䣺";
	cin >> workHour;
}

void technician::printSingle() 
{
	calSalary();
	basicInfo::printSingle();
	cout << "ְ�񣺼���Ա" << endl
		<< "����ʱ�䣨Сʱ����" << workHour << endl
		<< "���ʣ�" << fixed << salary << endl << endl;
}

void technician::printNoHead() 
{
	calSalary();
	basicInfo::printNoHead();
	cout << "ְ�񣺼���Ա" << ' '
		<< "����ʱ�䣨Сʱ����" << workHour << ' '
		<< "���ʣ�" << fixed << salary << endl;
}

void technician::calSalary()
{
	basicInfo::salary = workHour * 100;
}
