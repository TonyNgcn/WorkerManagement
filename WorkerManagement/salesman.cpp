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
	cin.ignore(100,'\n');
	while (saleAmount < 0)
	{
		cout << "输入错误，请重新输入" << endl;
		cout << "销售额：";
		cin >> saleAmount;
		cin.clear();
		cin.ignore(100,'\n');
	}
}

void salesman::printSingle() 
{
	calSalary();
	cout << "员工号：" << no << endl
		<< "姓名：" << name << endl
		<< "性别：" << sex << endl
		<< "部门：";
	inter.getDepName(department);
	cout << endl << "出生日期:";
	birthday.print();
	cout << endl;
	cout << "职务：销售员" << endl
		<< "销售额：" << setprecision(2) << fixed << saleAmount << endl
		<< "工资：" << setprecision(2) << fixed << salary << endl << endl;
}

void salesman::printNoHead() 
{
	calSalary();
	cout << setw(3) << no << ' ' << setw(7) << name << ' ' << setw(3) << sex << ' ';
	inter.getDepName(department);
	cout << ' ';
	birthday.print();
	//cout << endl;
	cout << " 职务：销售员" << ' '
		<< "销售额：" << setprecision(2) << fixed << saleAmount << ' '
		<< "工资：" << setprecision(2) << fixed << salary << endl;
}

void salesman::calSalary()
{
	basicInfo::salary = saleAmount*0.04;
}

bool salesman::changeSaleAmount()
{
	cout << "销售额：";
	double saleAmountToChange = -1;
	cin >> saleAmountToChange;
	cin.clear();
	cin.ignore(100, '\n');
	while (saleAmountToChange<0)
	{
		cout << "输入错误，请重新输入销售额：";
		cin >> saleAmountToChange;
		cin.clear();
		cin.ignore(100, '\n');
	}
	saleAmount = saleAmountToChange;
	return true;
}

bool salesman::changeWorkTime()
{
	return false;
}

istream & operator>>(istream &in, salesman &a)
{
	int noToInput;
	string nameToInput;
	string sexToInput;
	int depToInput;
	int yearToInput;
	int monthToInput;
	int dayToInput;
	double salaryToInput;
	int workPostToInput;
	double salesAmountToInput;
	in >> noToInput >> nameToInput >> sexToInput >> depToInput >> yearToInput >> monthToInput >> dayToInput >> salaryToInput >> workPostToInput >> salesAmountToInput;
	a.birthday.setDate(yearToInput, monthToInput, dayToInput);
	a.no = noToInput;
	a.name = nameToInput;
	a.sex = sexToInput;
	a.department = depToInput;
	a.salary = salaryToInput;
	a.workPost = workPostToInput;
	a.saleAmount = salesAmountToInput;
	return in;
}

ostream & operator<<(ostream &out, salesman &a)
{
	out << a.no << ' ' << a.name << ' ' << a.sex << ' ' << a.department << ' ' << a.birthday << ' ' << a.salary << ' ' << a.workPost << ' ' << a.saleAmount;
	return out;
}
