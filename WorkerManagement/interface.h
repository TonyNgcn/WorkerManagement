#pragma once
#include<iostream>
#include<string>
#include"department.h"
#include"manager.h"
#include"salesman.h"
#include"salesmanager.h"
#include"technician.h"
using namespace std;

class interFace
{
public:
	vector<department> department_v;
	vector<manager> manager_v;
	vector<salesman> salesman_v;
	vector<salesmanager> salesmanager_v;
	vector<technician> technician_v;
	void menu();
	void getAllDep()const;
	void addDep();
	void addPerson();


};
