#pragma once
#include"includeAll.h"
#ifndef department_H
#define department_H
class department
{
	string depName;   //部门名称
	int depNo;        //部门编号
	int count;        //部门人数
public:
	//函数功能：提取部门名称
	string getDepName()const;

	//函数功能：提取部门编号
	int getDepNo()const;

	//函数功能：输出部门名称、编号
	void printAllDep()const;

	//函数功能：输出该部门名称、编号、人数
	void getDepInfo()const;

	//函数功能：输入部门编号、名称
	void input();

	//函数功能：部门人数加一
	bool addCount();

	//函数功能：提取部门人数
	int getCount()const;

	//函数功能：构造函数
	department();

	//函数功能：修改部门名称
	bool changeDepName();

	//函数功能：部门人数减一
	bool reduceCount();

	//函数功能：检查部门名称是否重复
	bool checkDepName(string toCheck);

	//函数功能：检查部门编号是否重复
	bool checkDepNo(int toCheck);

	//函数功能：计算该部门平均工资
	double calAverageSalary();

	//函数功能：重载输入运算符
	friend istream& operator >>(istream&, department &);

	//函数功能：重载输出运算符
	friend ostream& operator <<(ostream&, department &);
};
#endif // !department_H

