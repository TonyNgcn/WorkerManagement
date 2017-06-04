#pragma once
#include"person.h"
class technician :public basicInfo
{
	int workHour;
public:
	int getWorkHour();
	void input();
	void printSingle()const;
	void printNoHead()const;
	void calSalary();
};