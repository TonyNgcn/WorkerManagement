#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include <iomanip>
#include<vector>
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

class date
{
	int year;
	int month;
	int day;
public:
	date(int, int, int);
	friend istream& operator >>(istream &, date &);
	friend ostream& operator <<(ostream &, date &);
	void print()const;
	void input();
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
	basicInfo();
	int getNo()const;
	string getName()const;
	string getSex()const;
	int getDepartment()const;
	void getDate()const;
	double getSalary()const;
	virtual void input();
	void inputDepNo(int depNo);
	virtual void printSingle()const;
	virtual void printNoHead()const;
	istream& operator >>(istream);
	ostream& operator <<(ostream);
};

class manager :public basicInfo
{
public:
	manager();
	void input();
	void printSingle()const;
	void printNoHead()const;
	void calSalary();
};

class salesman :public basicInfo
{
	double saleAmount;
public:
	salesman();
	double getSaleAmount();
	void input();
	void printSingle()const;
	void printNoHead()const;
	void calSalary();
};

class salesmanager :public basicInfo
{
public:
	salesmanager();
	void input();
	void printSingle()const;
	void printNoHead()const;
	void calSalary();
};

class technician :public basicInfo
{
	int workHour;
public:
	technician();
	int getWorkHour();
	void input();
	void printSingle()const;
	void printNoHead()const;
	void calSalary();
};

class interFace
{
public:
	vector<department> department_v;
	vector<manager> manager_v;
	vector<salesman> salesman_v;
	vector<salesmanager> salesmanager_v;
	vector<technician> technician_v;
	void menu();
	void deleteDep();
	void getAllDep()const;
	void getDepName(int)const;
	void addDep();
	void addPerson();
	void addCountOfDep(int depNo);
	bool checkDepExist(int checkDepID)const;
	bool checkSalesManager(int checkDepID)const;

};