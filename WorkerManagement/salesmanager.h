#pragma once
#include"includeAll.h"

#ifndef salesmanager_H
#define salesmanager_H
class salesmanager :public basicInfo
{
public:
	salesmanager();
	void input();
	void printSingle()const;
	void printNoHead()const;
	void calSalary();
};
#endif // !salesmanager_H

