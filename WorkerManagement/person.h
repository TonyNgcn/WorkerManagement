#pragma once
#include<iostream>
#include<string>
using namespace std;

enum workpost { salesman, technician, salesmanager, manager };

class date
{
	int year;
	int month;
	int day;
public:
	date(int,int,int);
	istream& operator >>(istream);
	ostream& operator <<(ostream);
	void print();
};
class basicInfo
{
	int no;
	string name;
	string sex;
	int department;
	enum workpost post;
	date birthday;
	double salary;
public:
	int getNo();
	string getName();
	string getSex();
	int getDepartment();
	enum workpost getPost();
	void getDate();
	double getSalary();
	virtual void input();
	virtual void print();
	istream& operator >>(istream);
	ostream& operator <<(ostream);
};