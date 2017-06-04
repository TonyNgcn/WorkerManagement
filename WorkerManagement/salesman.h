#pragma once
#include"person.h"
class salesman :public basicInfo
{
	double saleAmount;
public:
	salesman();
	double getSaleAmount();
	void input();
	void printSingle()const;
	void printNoHead()const;
	void calSalary();
};