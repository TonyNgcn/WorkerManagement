#include "interface.h"

void interFace::getAllDep()const
{
	for (auto i : department_v)
		i.printAllDep();
}

void interFace::addDep()
{
	department newDep;
	newDep.input();
}

void interFace::addPerson()
{
	cout << "���Ա��" << endl;
	cout << "��ѡ��Ա����ְλ��\n1.����Ա\n2.����Ա\n3.����\n4.���۾���" << endl;
	cout << "������ѡ��1-4����";
	int choice=0;
	cin >> choice;
	while (choice < 1 || choice>4)
	{
		cout << "�������������ѡ��";
		cin >> choice;
	}
	
	salesman obj1;
	technician obj2;
	manager obj3;
	salesmanager obj4;
	switch (choice)
	{
	case 1:
		obj1.input();
		salesman_v.push_back(obj1);
		break;
	case 2:
		obj2.input();
		technician_v.push_back(obj2);
		break;
	case 3:
		obj3.input();
		manager_v.push_back(obj3);
		break;
	case 4:
		obj4.input();
		salesmanager_v.push_back(obj4);
		break;
	default:
		cout << "������󣬳��򽫷���" << endl;
		break;
	}
}

