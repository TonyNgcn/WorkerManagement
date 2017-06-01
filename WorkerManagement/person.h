#pragma once
#include<iostream>
#include<string>
using namespace std;

class date
{
	int year;
	int month;
	int day;
public:
	date(int,int,int);
	friend istream& operator >>(istream &,date &);
	friend ostream& operator <<(ostream &,date &);
	void print()const;
};
class basicInfo
{
protected:
	int no;
	string name;
	string sex;
	int department;
	date birthday;
	double salary;
public:
	int getNo()const;
	string getName()const;
	string getSex()const;
	int getDepartment()const;
	void getDate()const;
	double getSalary()const;
	virtual void input();
	virtual void print()const;
	istream& operator >>(istream);
	ostream& operator <<(ostream);
};