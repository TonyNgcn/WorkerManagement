#include "person.h"

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



void basicInfo::getDate()const
{
	birthday.print();
}

double basicInfo::getSalary()const
{
	return salary;
}

istream& basicInfo::operator>>(istream in)
{
	in >> no >> name >> sex >> department >>  birthday >> salary;
	return in;
}

ostream& basicInfo::operator<<(ostream out)
{
	out << no << name << sex << department <<  birthday << salary;
	return out;
}
