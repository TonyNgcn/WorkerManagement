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
	cout << "�꣺";
	cin >> year;
	cin.clear();
	cin.ignore();
	while (year < 1917 && year>2017)
	{
		cout << "�����������������" << endl;
		cout << "�꣺";
		cin >> year;
		cin.clear();
		cin.ignore();
	}
	cout << "�£�";
	cin >> month;
	cin.clear();
	cin.ignore();
	while (month < 1 && month>12)
	{
		cout << "�����������������" << endl;
		cout << "�£�";
		cin >> month;
		cin.clear();
		cin.ignore();
	}
	cout << "�գ�";
	cin >> day;
	cin.clear();
	cin.ignore();
	while (day < 1 && day>31)
	{
		cout << "�����������������" << endl;
		cout << "�գ�";
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
	cout << "Ա�����ţ�";
	int noToInput=0;
	int sexToChoose = 0;
	cin >> noToInput;
	cin.clear();
	cin.ignore();
	while (!noToInput)
	{
		cout << "�����������������" << endl;
		cout << "Ա�����ţ�";
		cin >> noToInput;
		cin.clear();
		cin.ignore();
	}
	no = noToInput;
	cout << "Ա��������";
	cin >> name;
	while (!checkName(name))
	{
		cin >> name;
	}
	cout << "Ա���Ա�1-�У�2-Ů���������ţ�";
	cin >> sexToChoose;
	cin.clear();
	cin.ignore();
	while (sexToChoose < 1 && sexToChoose > 2)
	{
		cout << "�����������������" << endl;
		cout << "Ա���Ա�1-�У�2-Ů���������ţ�";
		cin >> sexToChoose;
		cin.clear();
		cin.ignore();
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


bool basicInfo::checkName(string toCheck)
{
	if (toCheck.size() < 2 && toCheck.size() > 10)
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
}

bool basicInfo::operator==(basicInfo & a)const
{
	return no==a.no&&name==a.name;
}
