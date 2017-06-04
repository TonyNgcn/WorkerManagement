#include "technician.h"

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

void technician::calSalary()
{
	basicInfo::salary = workHour * 100;
}
