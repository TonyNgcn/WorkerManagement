#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include <iomanip>
#include<vector>
#include<algorithm>
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
	bool reduceCount();
	bool checkDepName(string toCheck);
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
	int workPost; //1-销售员 2-技术员 3-销售经理 4-经理
public:
	basicInfo();
	int getNo()const;
	string getName()const;
	string getSex()const;
	int getDepartment()const;
	int getWorkPost()const;
	void getDate()const;
	double getSalary()const;
	virtual void input();
	void inputDepNo(int depNo);
	virtual void printSingle() = 0;
	virtual void printNoHead() = 0;
	istream& operator >>(istream);
	ostream& operator <<(ostream);
	bool operator ==(basicInfo &a)const;
	bool operator <(basicInfo &a)const;
	bool changeName();
	bool changeSex();
	bool changeDep(int depToChange);
	bool checkName(string toCheck);
	

};

class manager :public basicInfo
{
public:
	manager();
	void input();
	void printSingle();
	void printNoHead();
	void calSalary();
};


class salesman :public basicInfo
{
	double saleAmount;
public:
	salesman();
	double getSaleAmount();
	void input();
	void printSingle();
	void printNoHead();
	void calSalary();
};

class salesmanager :public basicInfo
{
public:
	salesmanager();
	void input();
	void printSingle();
	void printNoHead();
	void calSalary();
};

class technician :public basicInfo
{
	int workHour;
public:
	technician();
	int getWorkHour();
	void input();
	void printSingle();
	void printNoHead();
	void calSalary();
};

class interFace
{
	department tempDep;
	basicInfo *tempPerson;
	vector<basicInfo*> temp_v;
public:
	vector<department> department_v;
	vector<manager> manager_v;
	vector<salesman> salesman_v;
	vector<salesmanager> salesmanager_v;
	vector<technician> technician_v;
	void menu();
	bool deleteDep(department);
	void getAllDep()const;
	void getDepName(int)const;
	void addDep();
	void addPerson();
	void addCountOfDep(int depNo);
	bool checkDepExist(int checkDepID)const;
	bool checkSalesManager(int checkDepID)const;
	bool searchDep(int checkDepID);
	bool searchDep(string checkDepName);
	void checkByDep();
	void tempAll();
	void sortAndPrintAll();
	bool searchByName(string checkName);
	bool searchByNo(int checkNo);
	void change();
	void reduceDepCount(int depNo);
};
