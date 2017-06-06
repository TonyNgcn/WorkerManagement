#pragma once
#include"includeAll.h"
#ifndef technician_H
#define technician_H
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
#endif