#include "technician.h"
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

void technician::printSingle() const
{
	basicInfo::printSingle();
	cout << "ְ�񣺼���Ա" << endl
		<< "����ʱ�䣨Сʱ����" << workHour << endl
		<< "���ʣ�" << salary << endl;
}

void technician::printNoHead() const
{
	basicInfo::printNoHead();
	cout << "ְ�񣺼���Ա" << ' '
		<< "����ʱ�䣨Сʱ����" << workHour << ' '
		<< "���ʣ�" << salary << endl;
}

void technician::calSalary()
{
	basicInfo::salary = workHour * 100;
}
