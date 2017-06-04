#pragma once
#include"person.h"
class technician :public basicInfo
{
	int workHour;
public:
	technician();
	int getWorkHour();
	void input();
	void printSingle()const;
	void printNoHead()const;
	void calSalary();
};