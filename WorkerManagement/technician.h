#pragma once
#include"includeAll.h"
#ifndef technician_H
#define technician_H
class technician :public basicInfo
{
	int workHour;   //工作时间
public:
	//函数功能：构造函数
	technician();

	//函数功能：提取工作时间
	int getWorkHour();

	//函数功能：输入数据
	void input();

	//函数功能：输出一个员工信息
	void printSingle();

	//函数功能：输出一个员工信息（无表头）
	void printNoHead();

	//函数功能：计算工资
	void calSalary();

	//函数功能：修改工作时间
	bool changeWorkTime();

	//函数功能：没有用
	bool changeSaleAmount();

	//函数功能：重载输入运算符
	friend istream& operator >>(istream&, technician &);

	//函数功能：重载输出运算符
	friend ostream& operator <<(ostream&, technician &);
};
#endif