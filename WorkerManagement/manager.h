#pragma once
#include"includeAll.h"
#ifndef manager_H
#define manager_H
class manager :public basicInfo
{
public:
	//函数功能：构造函数
	manager();

	//函数功能：输入
	void input();

	//函数功能：输出一个员工数据
	void printSingle();

	//函数功能：输出员工员工数据（无表头）
	void printNoHead();

	//函数功能：计算员工工资
	void calSalary();

	//函数功能：没有用
	bool changeSaleAmount();

	//函数功能：没有用
	bool changeWorkTime();

	//函数功能：重载输入运算符
	friend istream& operator >>(istream&, manager &);

	//函数功能：重载输出运算符
	friend ostream& operator <<(ostream&, manager &);
};

#endif // !manager_H

