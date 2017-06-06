#pragma once
#include"includeAll.h"
#ifndef department_H
#define department_H
class department
{
	string depName;
	int depNo;
	int count;
public:
	string getDepName()const;
	int getDepNo()const;
	void printAllDep()const;
	void input();
	bool addCount();
	int getCount()const;
	department();
};
#endif // !department_H

