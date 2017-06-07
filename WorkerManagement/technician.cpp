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
	cout << "工作时间：";
	cin >> workHour;
}

void technician::printSingle() 
{
	calSalary();
	basicInfo::printSingle();
	cout << "职务：技术员" << endl
		<< "工作时间（小时）：" << workHour << endl
		<< "工资：" << fixed << salary << endl << endl;
}

void technician::printNoHead() 
{
	calSalary();
	basicInfo::printNoHead();
	cout << "职务：技术员" << ' '
		<< "工作时间（小时）：" << workHour << ' '
		<< "工资：" << fixed << salary << endl;
}

void technician::calSalary()
{
	basicInfo::salary = workHour * 100;
}
