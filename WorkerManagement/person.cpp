#include "person.h"


date::date(int y=2017, int m=6, int d=1)
{
	year = y;
	month = m;
	day = 1;
}

istream& date::operator>>(istream in)
{
	in >> year >> month >> day;
	return in;
}

ostream& date::operator<<(ostream out)
{
	out << year << month << day;
	return out;
}

void date::print()
{
	cout << year << '-' << month << '-' << day;
}

int basicInfo::getNo()
{
	return no;
}

string basicInfo::getName()
{
	return name;
}

string basicInfo::getSex()
{
	return sex;
}

int basicInfo::getDepartment()
{
	return department;
}

workpost basicInfo::getPost()
{
	return post;
}

void basicInfo::getDate()
{
	birthday.print();
}

double basicInfo::getSalary()
{
	return salary;
}

istream& basicInfo::operator>>(istream in)
{
	//in >> no >> name >> sex >> department >> (int)post >> birthday >> salary;
	return in;
}

ostream& basicInfo::operator<<(ostream out)
{
	return out;
}


