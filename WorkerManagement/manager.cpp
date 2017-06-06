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
	cout << "职务：经理" << endl
		<< "工资：" << salary << endl;
}

void manager::printNoHead() const
{
	basicInfo::printNoHead();
	cout << "职务：经理" << ' '
		<< "工资：" << salary << endl;
}

void manager::calSalary()
{
	basicInfo::salary = 8000;
}