#include "ALL.h"
extern interFace inter;
technician::technician()
{
	workHour = -1;
	salary = 0;
	workPost = 2;
}

int technician::getWorkHour()
{
	return workHour;
}

void technician::input()
{
	basicInfo::input();
	workHour = -1;
	cout << "工作时间：";
	cin >> workHour;
	cin.clear();
	cin.ignore(100,'\n');
	while (workHour < 0)
	{
		cout << "输入错误，请重新输入" << endl;
		cout << "工作时间：";
		cin >> workHour;
		cin.clear();
		cin.ignore(100,'\n');
	}
}

void technician::printSingle() 
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
	cout << "职务：技术员" << endl
		<< "工作时间（小时）：" << workHour << endl
		<< "工资：" << fixed << salary << endl << endl;
}

void technician::printNoHead() 
{
	calSalary();
	cout << setw(-5) << no << ' ' << setw(-8) << name << ' ' << setw(-3) << sex << ' ';
	inter.getDepName(department);
	cout << ' ';
	birthday.print();
	cout << endl;
	cout << "职务：技术员" << ' '
		<< "工作时间（小时）：" << workHour << ' '
		<< "工资：" << fixed << salary << endl;
}

void technician::calSalary()
{
	basicInfo::salary = workHour * 100;
}

bool technician::changeWorkTime()
{
	cout << "工作时间：";
	int workHourToChange = -1;
	cin >> workHourToChange;
	cin.clear();
	cin.ignore(100, '\n');
	while (workHourToChange<0)
	{
		cout << "输入错误，请重新输入工作时间：";
		cin >> workHourToChange;
		cin.clear();
		cin.ignore(100, '\n');
	}
	workHour = workHourToChange;
	return true;
}

bool technician::changeSaleAmount()
{
	return false;
}

istream & operator>>(istream &in, technician &a)
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
	int workHourToInput;
	in >> noToInput >> nameToInput >> sexToInput >> depToInput >> yearToInput >> monthToInput >> dayToInput >> salaryToInput >> workPostToInput >> workHourToInput;
	a.birthday.setDate(yearToInput, monthToInput, dayToInput);
	a.no = noToInput;
	a.name = nameToInput;
	a.sex = sexToInput;
	a.department = depToInput;
	a.salary = salaryToInput;
	a.workPost = workPostToInput;
	a.workHour = workHourToInput;
	return in;
}

ostream & operator<<(ostream &out, technician &a)
{
	out << a.no << ' ' << a.name << ' ' << a.sex << ' ' << a.department << ' ' << a.birthday << ' ' << a.salary << ' ' << a.workPost << ' ' << a.workHour;
	return out;
}
