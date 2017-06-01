#pragma once
#include<iostream>
#include<string>
using namespace std;
class date
{
	int year;
	int month;
	int day;
};
class basicInfo
{
	int no;
	string name;
	string sex;
	int department;
	enum workspost post;
	date birthday;
	double salary;
};