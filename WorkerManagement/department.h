#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"person.h"
using namespace std;

class department
{
	string depName;
	int depNo;
	int count;
public:
	string getDepName()const;
	int getDepNo()const;
	void printAllDep()const;
	void input();
	bool addCount();
	int getCount()const;
	department();
};