#include "ALL.h"
extern interFace inter;
date::date(int y=2017, int m=6, int d=1)
{
	year = y;
	month = m;
	day = 1;
}

istream& operator>>(istream &in,date &d)
{
	in >> d.year >> d.month >> d.day;
	return in;
}

ostream& operator<<(ostream &out,date &d)
{
	out << d.year << d.month << d.day;
	return out;
}

void date::print()const
{
	cout << year << '-' << month << '-' << day;
}

void date::input()
{
	year = 0, month = 0, day = 0;
	cout << "年：";
	cin >> year;
	cin.clear();
	cin.ignore();
	while (year < 1917 && year>2017)
	{
		cout << "输入错误，请重新输入" << endl;
		cout << "年：";
		cin >> year;
		cin.clear();
		cin.ignore();
	}
	cout << "月：";
	cin >> month;
	cin.clear();
	cin.ignore();
	while (month < 1 && month>12)
	{
		cout << "输入错误，请重新输入" << endl;
		cout << "月：";
		cin >> month;
		cin.clear();
		cin.ignore();
	}
	cout << "日：";
	cin >> day;
	cin.clear();
	cin.ignore();
	while (day < 1 && day>31)
	{
		cout << "输入错误，请重新输入" << endl;
		cout << "日：";
		cin >> day;
		cin.clear();
		cin.ignore();
	}
}

basicInfo::basicInfo()
{
	salary = 0;
	no = 0;
}

int basicInfo::getNo()const
{
	return no;
}

string basicInfo::getName()const
{
	return name;
}

string basicInfo::getSex()const
{
	return sex;
}

int basicInfo::getDepartment()const
{
	return department;
}

int basicInfo::getWorkPost() const
{
	return workPost;
}

void basicInfo::getDate()const
{
	birthday.print();
}

date basicInfo::getBirthday() const
{
	return birthday;
}

double basicInfo::getSalary()const
{
	return salary;
}

void basicInfo::input()
{
	cout << "员工工号：";
	int noToInput=0;
	int sexToChoose = 0;
	cin >> noToInput;
	cin.clear();
	cin.ignore();
	while (!noToInput)
	{
		cout << "输入错误，请重新输入" << endl;
		cout << "员工工号：";
		cin >> noToInput;
		cin.clear();
		cin.ignore();
	}
	no = noToInput;
	cout << "员工姓名：";
	cin >> name;
	while (!checkName(name))
	{
		cin >> name;
	}
	cout << "员工性别（1-男，2-女）请输入编号：";
	cin >> sexToChoose;
	cin.clear();
	cin.ignore();
	while (sexToChoose < 1 && sexToChoose > 2)
	{
		cout << "输入错误，请重新输入" << endl;
		cout << "员工性别（1-男，2-女）请输入编号：";
		cin >> sexToChoose;
		cin.clear();
		cin.ignore();
	}
	if (sexToChoose == 1)
		sex = "男";
	else
		sex = "女";
	cout << "出生日期：" << endl;
	birthday.input();
}

void basicInfo::inputDepNo(int depNo)
{
	department = depNo;
}

istream& basicInfo::operator>>(istream in)
{
	in >> no >> name >> sex >> department >> birthday >> salary >> workPost;
	return in;
}

ostream& basicInfo::operator<<(ostream out)
{
	out << no << name << sex << department << birthday << salary << workPost;
	return out;
}

bool basicInfo::operator<(basicInfo & a) const
{
	return salary<a.salary;
}

bool basicInfo::changeName()
{
	cout << "请输入修改后的姓名：";
	string nameToChange;
	cin >> nameToChange;
	while (!checkName(nameToChange))
	{
		cout << "修改后的姓名：";
		cin >> nameToChange;
	}
	name = nameToChange;
	return true;
}

bool basicInfo::changeSex()
{
	if (sex == "男")
		sex = "女";
	else
		sex = "男";
	return true;
}

bool basicInfo::changeDep(int depToChange)
{
	if (workPost == 3)
	{
		cout << "销售经理不支持直接修改部门，请先转换成其他岗位" << endl;
		system("pause");
		return false;
	}
	for (auto &i : inter.department_v)
	{
		if (i.getDepNo() == department)
			i.reduceCount();
	}
	department = depToChange;
	for (auto &i : inter.department_v)
	{
		if (i.getDepNo() == department)
				i.addCount();
	}
	return true;
}


bool basicInfo::checkName(string toCheck)
{
	if (toCheck.size() < 2 && toCheck.size() > 10)
	{
		cout << "名字过长或过短，请重新输入" << endl;
		return false;
	}
	return true;
}

bool basicInfo::setBasicInfo(int noSet, string nameSet, string sexSet , int departmentSet, date birthdaySet)
{
	no = noSet;
	name = nameSet;
	department = departmentSet;
	sex = sexSet;
	birthday = birthdaySet;
}

bool basicInfo::operator==(basicInfo & a)const
{
	return no==a.no&&name==a.name;
}
