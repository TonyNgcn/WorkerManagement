#pragma once
#include"person.h"
class salesmanager :public basicInfo
{
	void input();
	void printSingle()const;
	void printNoHead()const;
	void calSalary();
};