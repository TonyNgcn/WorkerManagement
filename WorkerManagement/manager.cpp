#include "manager.h"

manager::manager()
{
}

void manager::input()
{
	basicInfo::input();
}

void manager::printSingle() const
{
	basicInfo::printSingle();
	cout << "ְ�񣺾���" << endl
		<< "���ʣ�" << salary << endl;
}

void manager::printNoHead() const
{
	basicInfo::printNoHead();
	cout << "ְ�񣺾���" << ' '
		<< "���ʣ�" << salary << endl;
}

void manager::calSalary()
{
	basicInfo::salary = 8000;
}