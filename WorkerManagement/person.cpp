#include "ALL.h"
extern interFace inter;
date::date(int y=2017, int m=6, int d=1)
{
	year = y;
	month = m;
	day = 1;
}

void date::setDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}

istream& operator>>(istream &in,date &d)
{
	int y, m, da;
	in >> y >> m >> d;
	d.year = y;
	d.month = m;
	d.day = da;
	return in;
}

ostream& operator<<(ostream &out,date &d)
{
	out << d.year << ' ' << d.month << ' ' << d.day;
	return out;
}

void date::print()const
{
	cout << year << '-' << month << '-' << day;
}

void date::input()
{
	year = 0, month = 0, day = 0;
	cout << "�꣺";
	cin >> year;
	cin.clear();
	cin.ignore(100,'\n');
	while (year < 1917 || year>2017)
	{
		cout << "�����������������" << endl;
		cout << "�꣺";
		cin >> year;
		cin.clear();
		cin.ignore(100,'\n');
	}
	cout << "�£�";
	cin >> month;
	cin.clear();
	cin.ignore(100,'\n');
	while (month < 1 || month>12)
	{
		cout << "�����������������" << endl;
		cout << "�£�";
		cin >> month;
		cin.clear();
		cin.ignore(100,'\n');
	}
	cout << "�գ�";
	cin >> day;
	cin.clear();
	cin.ignore(100,'\n');
	while (day < 1 || day>31)
	{
		cout << "�����������������" << endl;
		cout << "�գ�";
		cin >> day;
		cin.clear();
		cin.ignore(100,'\n');
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
	cout << "Ա�����ţ�";
	int noToInput=0;
	int sexToChoose = 0;
	cin >> noToInput;
	cin.clear();
	cin.ignore(100,'\n');
	while (!noToInput || !checkNo(noToInput))
	{
		cout << "�������������й����ظ�������������" << endl;
		cout << "Ա�����ţ�";
		cin >> noToInput;
		cin.clear();
		cin.ignore(100,'\n');
	}
	no = noToInput;
	cout << "Ա��������";
	cin >> name;
	while (!checkName(name))
	{
		cout << "������";
		cin >> name;
	}
	cout << "Ա���Ա�1-�У�2-Ů���������ţ�";
	cin >> sexToChoose;
	cin.clear();
	cin.ignore(100,'\n');
	while (sexToChoose < 1 || sexToChoose > 2)
	{
		cout << "�����������������" << endl;
		cout << "Ա���Ա�1-�У�2-Ů���������ţ�";
		cin >> sexToChoose;
		cin.clear();
		cin.ignore(100,'\n');
	}
	if (sexToChoose == 1)
		sex = "��";
	else
		sex = "Ů";
	cout << "�������ڣ�" << endl;
	birthday.input();
}

void basicInfo::inputDepNo(int depNo)
{
	department = depNo;
}

istream& operator>>(istream &in, basicInfo &a)
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
	in >> noToInput >> nameToInput >> sexToInput >> depToInput >> yearToInput >> monthToInput >> dayToInput >> salaryToInput >> workPostToInput;
	a.birthday.setDate(yearToInput, monthToInput, dayToInput);
	a.no = noToInput;
	a.name = nameToInput;
	a.sex = sexToInput;
	a.department = depToInput;
	a.salary = salaryToInput;
	a.workPost = workPostToInput;
	return in;
}

ostream& operator<<(ostream &out, basicInfo &a)
{
	out << a.no << ' ' << a.name << ' ' << a.sex << ' ' << a.department << ' ' << a.birthday << ' ' << a.salary << ' ' << a.workPost;
	return out;
}

bool basicInfo::operator<(basicInfo & a) const
{
	return salary<a.salary;
}

bool basicInfo::checkNo(int toCheck) const
{
	for (auto &i : inter.salesman_v)
	{
		if (i.getNo() == toCheck)
			return false;
	}
	for (auto &i : inter.technician_v)
	{
		if (i.getNo() == toCheck)
			return false;
	}
	for (auto &i : inter.salesmanager_v)
	{
		if (i.getNo() == toCheck)
			return false;
	}
	for (auto &i : inter.manager_v)
	{
		if (i.getNo() == toCheck)
			return false;
	}
	return true;
}

bool basicInfo::changeName()
{
	cout << "�������޸ĺ��������";
	string nameToChange;
	cin >> nameToChange;
	while (!checkName(nameToChange))
	{
		cout << "�޸ĺ��������";
		cin >> nameToChange;
	}
	name = nameToChange;
	return true;
}

bool basicInfo::changeSex()
{
	if (sex == "��")
		sex = "Ů";
	else
		sex = "��";
	return true;
}

bool basicInfo::changeDep(int depToChange)
{
	if (workPost == 3)
	{
		cout << "���۾���֧��ֱ���޸Ĳ��ţ�����ת����������λ" << endl;
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


bool basicInfo::checkName(string toCheck)const
{
	if (toCheck.size() < 2 || toCheck.size() > 10)
	{
		cout << "���ֹ�������̣�����������" << endl;
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
	return true;
}

bool basicInfo::operator==(basicInfo & a)const
{
	return no==a.no&&name==a.name;
}
