#include "interface.h"
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
			i.getDepName();
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
	cout << "���Ա��" << endl;
	cout << "��ѡ��Ա���������ţ�" << endl;
	getAllDep();
	cout << "�����벿�ű�ţ�";
	int choice = 0;
	cin >> choice;
	while (!choice)
	{
		cout << "�������������ѡ��";
		cin >> choice;
	}
	if (!checkDepExist(choice))
	{
		cout << "�ò��Ų����ڣ�������Ӳ��ţ����򽫷���" << endl;
		system("pause");
		return;
	}
	int tempDepNo=choice;
	choice = 0;
	if (checkSalesManager(tempDepNo))
	{
		cout << "��ѡ��Ա����ְλ��\n1.����Ա\n2.����Ա\n3.����\n4.���۾���" << endl;
		cout << "������ѡ��1-4����";
		cin >> choice;
		while (choice < 1 || choice>4)
		{
			cout << "�������������ѡ��";
			cin >> choice;
		}
	}
	else
	{
		cout << "�ò����Ѵ������۾�������Ա����ְλ�����������۾���" << endl;
		cout << "��ѡ��Ա����ְλ��\n1.����Ա\n2.����Ա\n3.����" << endl;
		cout << "������ѡ��1-3����";
		cin >> choice;
		while (choice < 1 || choice>3)
		{
			cout << "�������������ѡ��";
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
		cout << "������󣬳��򽫷���" << endl;
		system("pause");
		return;
		break;
	}
	addCountOfDep(tempDepNo);
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

