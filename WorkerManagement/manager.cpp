#include "ALL.h"
extern interFace inter;
manager::manager()
{
	salary = 8000;
	workPost = 4;
}

void manager::input()
{
	basicInfo::input();
}

void manager::printSingle()
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
	cout << "职务：经理" << endl
		<< "工资：" << salary << endl << endl;
}

void manager::printNoHead() 
{
	calSalary();
	cout << setw(-5) << no << ' ' << setw(-8) << name << ' ' << setw(-3) << sex << ' ';
	inter.getDepName(department);
	cout << ' ';
	birthday.print();
	cout << endl;
	cout << "职务：经理" << ' '
		<< "工资：" << fixed << salary << endl;
}

void manager::calSalary()
{
	basicInfo::salary = 8000;
}

istream & operator>>(istream &in, manager &a)
{
	in >> a.no >> a.name >> a.sex >> a.department >> a.birthday >> a.salary >> a.workPost;
	return in;
}

ostream & operator<<(ostream &out, manager &a)
{
	out << a.no << a.name << a.sex << a.department << a.birthday << a.salary << a.workPost;
	return out;
}
