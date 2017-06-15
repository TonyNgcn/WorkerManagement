#pragma once
#include"includeAll.h"
#ifndef salesman_H
#define salesman_H
class salesman :public basicInfo
{
	class salesman :public basicInfo
	{
		double saleAmount;   //销售额
	public:
		//函数功能：构造函数
		salesman();

		//函数功能：提取销售额
		double getSaleAmount();

		//函数功能：输入数据
		void input();

		//函数功能：输出一个员工数据
		void printSingle();

		//函数功能：输出一个员工数据（无表头）
		void printNoHead();

		//函数功能：计算工资
		void calSalary();

		//函数功能：更改销售额
		bool changeSaleAmount();

		//函数功能：没有用
		bool changeWorkTime();

		//函数功能：重载输入运算符
		friend istream& operator >>(istream&, salesman &);

		//函数功能：重载输出运算符
		friend ostream& operator <<(ostream&, salesman &);
	};
#endif