#pragma once
#ifndef interface_H
#define interface_H
#include"includeAll.h"
#include"manager.h"
#include"salesman.h"
#include"technician.h"
#include"salesmanager.h"
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
#endif
