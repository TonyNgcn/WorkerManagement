#pragma once
#include"includeAll.h"
#ifndef salesman_H
#define salesman_H
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
#endif