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
	cout << "职务：经理" << endl
		<< "工资：" << salary << endl << endl;
}

void manager::printNoHead() 
{
	calSalary();
	basicInfo::printNoHead();
	cout << "职务：经理" << ' '
		<< "工资：" << fixed << salary << endl;
}

void manager::calSalary()
{
	basicInfo::salary = 8000;
}