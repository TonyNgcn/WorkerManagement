#pragma once
#include"person.h"
class manager :public basicInfo
{
public:
	manager();
	void input();
	void printSingle()const;
	void printNoHead()const;
	void calSalary();
};