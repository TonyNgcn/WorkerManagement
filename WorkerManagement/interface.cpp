#include "interface.h"

void interFace::getAllDep()const
{
	for (auto i : department_v)
		i.printAllDep;
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
	switch (choice)
	{
	case 1:

	}
}

