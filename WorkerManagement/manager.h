#pragma once
#include"includeAll.h"
#ifndef manager_H
#define manager_H
class manager :public basicInfo
{
public:
	manager();
	void input();
	void printSingle()const;
	void printNoHead()const;
	void calSalary();
};
#endif // !manager_H

