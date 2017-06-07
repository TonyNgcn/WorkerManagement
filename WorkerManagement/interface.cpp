#include "ALL.h"

bool interFace::deleteDep(department delDep)
{
	for (vector<department>::iterator it=department_v.begin();it!=department_v.end();it++)
	{
		if ((*it).getDepNo() == delDep.getDepNo())
		{
			it = department_v.erase(it);
			for (vector<salesman>::iterator it = salesman_v.begin(); it != salesman_v.end(); it++)
			{
				if ((*it).getDepartment() == delDep.getDepNo())
				{
					it = salesman_v.erase(it);
				}
			}
			for (vector<salesmanager>::iterator it = salesmanager_v.begin(); it != salesmanager_v.end(); it++)
			{
				if ((*it).getDepartment() == delDep.getDepNo())
				{
					it = salesmanager_v.erase(it);
				}
			}
			for (vector<technician>::iterator it = technician_v.begin(); it != technician_v.end(); it++)
			{
				if ((*it).getDepartment() == delDep.getDepNo())
				{
					it = technician_v.erase(it);
				}
			}
			for (vector<manager>::iterator it = manager_v.begin(); it != manager_v.end(); it++)
			{
				if ((*it).getDepartment() == delDep.getDepNo())
				{
					it = manager_v.erase(it);
				}
			}
			return true;
		}
	}
	return false;
}

void interFace::getAllDep()const
{
	for (auto &i : department_v)
		i.printAllDep();
}

void interFace::getDepName(int depNo) const
{
	for (auto &i : department_v)
	{
		if (i.getDepNo() == depNo)
		{
			cout << i.getDepNo() << '-' << i.getDepName();
			break;
		}
	}
}

void interFace::addDep()
{
	department newDep;
	newDep.input();
	department_v.push_back(newDep);
}

void interFace::addPerson()
{
	cout << "添加员工" << endl;
	cout << "请选择员工所属部门" << endl;
	getAllDep();
	cout << "请输入部门编号：";
	int choice = 0;
	cin >> choice;
	while (!choice)
	{
		cout << "输入错误，请重新选择：";
		cin >> choice;
	}
	if (!checkDepExist(choice))
	{
		cout << "该部门不存在，请先添加部门，程序将返回" << endl;
		system("pause");
		return;
	}
	int tempDepNo=choice;
	choice = 0;
	if (checkSalesManager(tempDepNo))
	{
		cout << "请选择员工的职位：\n1.销售员\n2.技术员\n3.经理\n4.销售经理" << endl;
		cout << "请输入选择（1-4）：";
		cin >> choice;
		while (choice < 1 || choice>4)
		{
			cout << "输入错误，请重新选择：";
			cin >> choice;
		}
	}
	else
	{
		cout << "该部门已存在销售经理，所以员工的职位不可以是销售经理" << endl;
		cout << "请选择员工的职位：\n1.销售员\n2.技术员\n3.经理" << endl;
		cout << "请输入选择（1-3）：";
		cin >> choice;
		while (choice < 1 || choice>3)
		{
			cout << "输入错误，请重新选择：";
			cin >> choice;
		}
	}
	salesman obj1;
	technician obj2;
	manager obj3;
	salesmanager obj4;
	switch (choice)
	{
	case 1:
		obj1.input();
		obj1.inputDepNo(tempDepNo);
		salesman_v.push_back(obj1);
		break;
	case 2:
		obj2.input();
		obj2.inputDepNo(tempDepNo);
		technician_v.push_back(obj2);
		break;
	case 3:
		obj3.input();
		obj3.inputDepNo(tempDepNo);
		manager_v.push_back(obj3);
		break;
	case 4:
		obj4.input();
		obj4.inputDepNo(tempDepNo);
		salesmanager_v.push_back(obj4);
		break;
	default:
		cout << "输入错误，程序将返回" << endl;
		system("pause");
		return;
		break;
	}
	addCountOfDep(tempDepNo);
	system("pause");
	system("cls");
}

void interFace::addCountOfDep(int depNo)
{
	for (auto &i : department_v)
	{
		if (i.getDepNo() == depNo)
			i.addCount();
	}
}

bool interFace::checkDepExist(int checkDepID) const
{
	for (auto &i : department_v)
	{
		if (i.getDepNo() == checkDepID)
			return true;
	}
	return false;
}

bool interFace::checkSalesManager(int checkDepID) const
{
	for (auto &i : salesmanager_v)
	{
		if (i.getDepartment() == checkDepID)
			return false;
	}
	return true;
}

bool interFace::searchDep(int checkDepID, department &temp)
{
	for (auto &i : department_v)
	{
		if (i.getDepNo() == checkDepID)
		{
			temp = i;
			return true;
		}
	}
	return false;
}

bool interFace::searchDep(string checkDepName , department &temp) 
{
	for (auto &i : department_v)
	{
		if (i.getDepName() == checkDepName)
		{
			temp = i;
			return true;
		}
	}
	return false;
}

void interFace::checkByDep(department & temp)
{
	cout << "部门名称：" << temp.getDepNo() << '-' << temp.getDepName() << endl;
	cout << "部门人数：" << temp.getCount() << endl<<endl;

	for (auto &i : salesman_v)
	{
		if(i.getDepartment()==temp.getDepNo())
			i.printNoHead();
	}
	for (auto &i : technician_v)
	{
		if (i.getDepartment() == temp.getDepNo())
			i.printNoHead();
	}
	for (auto &i : salesmanager_v)
	{
		if (i.getDepartment() == temp.getDepNo())
			i.printNoHead();
	}
	for (auto &i : manager_v)
	{
		if (i.getDepartment() == temp.getDepNo())
			i.printNoHead();
	}

}

