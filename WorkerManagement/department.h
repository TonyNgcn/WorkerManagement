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
	static int count;
public:
	string getDepName()const;
	int getDepNo()const;
	int getCount()const;
};