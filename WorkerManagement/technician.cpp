#include "technician.h"

int technician::getWorkHour()
{
	return workHour;
}

void technician::calSalary()
{
	basicInfo::salary = workHour * 100;
}
