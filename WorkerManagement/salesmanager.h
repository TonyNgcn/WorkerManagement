#pragma once
#include"person.h"
class salesmanager :public basicInfo
{
public:
	salesmanager();
	void input();
	void printSingle()const;
	void printNoHead()const;
	void calSalary();
};