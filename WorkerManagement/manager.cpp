#include "ALL.h"

manager::manager()
{
}

void manager::input()
{
	basicInfo::input();
}

void manager::printSingle()
{
	calSalary();
	basicInfo::printSingle();
	cout << "ְ�񣺾���" << endl
		<< "���ʣ�" << salary << endl << endl;
}

void manager::printNoHead() 
{
	calSalary();
	basicInfo::printNoHead();
	cout << "ְ�񣺾���" << ' '
		<< "���ʣ�" << fixed << salary << endl;
}

void manager::calSalary()
{
	basicInfo::salary = 8000;
}