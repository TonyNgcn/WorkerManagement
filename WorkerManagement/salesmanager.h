#pragma once
#include"includeAll.h"

#ifndef salesmanager_H
#define salesmanager_H
class salesmanager :public basicInfo
{
public:
	//函数功能：构造函数
	salesmanager();

	//函数功能：输入数据
	void input();

	//函数功能：输出一个员工信息
	void printSingle();

	//函数功能：输出一个员工信息（无表头）
	void printNoHead();

	//函数功能：计算工资
	void calSalary();

	//函数功能：没有用
	bool changeSaleAmount();

	//函数功能：没有用
	bool changeWorkTime();

	//函数功能：重载输入运算符
	friend istream& operator >>(istream&, salesmanager &);

	//函数功能：重载输出运算符
	friend ostream& operator <<(ostream&, salesmanager &);
};
#endif // !salesmanager_H

