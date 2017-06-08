#include "ALL.h"
extern interFace inter;
salesman::salesman()
{
	workPost = 1;
	salary = 0;
	saleAmount = -1;
}

double salesman::getSaleAmount()
{
	return saleAmount;
}

void salesman::input()
{
	basicInfo::input();
	cout << "销售额：";
	saleAmount = -1;
	cin >> saleAmount;
	cin.clear();
	cin.ignore();
	while (saleAmount < 0)
	{
		cout << "输入错误，请重新输入" << endl;
		cout << "销售额：";
		cin >> saleAmount;
		cin.clear();
		cin.ignore();
	}
}

void salesman::printSingle() 
{
	calSalary();
	cout << "员工号：" << no << endl
		<< "姓名：" << name << endl
		<< "性别" << sex << endl
		<< "部门：";
	inter.getDepName(department);
	cout << endl << "出生日期:";
	birthday.print();
	cout << endl;
	cout << "职务：销售员" << endl
		<< "销售额：" << fixed << saleAmount << endl
		<< "工资：" << fixed << salary << endl << endl;
}

void salesman::printNoHead() 
{
	calSalary();
	cout << setw(-5) << no << ' ' << setw(-8) << name << ' ' << setw(-3) << sex << ' ';
	inter.getDepName(department);
	cout << ' ';
	birthday.print();
	cout << endl;
	cout << "职务：销售员" << ' '
		<< "销售额：" << saleAmount << ' '
		<< "工资：" << fixed << salary << endl;
}

void salesman::calSalary()
{
	basicInfo::salary = saleAmount*0.04;
}
