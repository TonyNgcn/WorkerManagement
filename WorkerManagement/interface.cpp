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
	cout << "���Ա��" << endl;
	cout << "��ѡ��Ա����������" << endl;
	getAllDep();
	cout << "�����벿�ű�ţ�";
	int choice = 0;
	cin >> choice;
	cin.clear();
	cin.ignore(100, '\n');
	while (!choice)
	{
		cout << "�������������ѡ��";
		cin >> choice;
		cin.clear();
		cin.ignore(100, '\n');
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
		cin.clear();
		cin.ignore(100,'\n');
		while (choice < 1 || choice>4)
		{
			cout << "�������������ѡ��";
			cin >> choice;
			cin.clear();
			cin.ignore(100,'\n');
		}
	}
	else
	{
		cout << "�ò����Ѵ������۾�������Ա����ְλ�����������۾���" << endl;
		cout << "��ѡ��Ա����ְλ��\n1.����Ա\n2.����Ա\n3.����" << endl;
		cout << "������ѡ��1-3����";
		cin >> choice;
		cin.clear();
		cin.ignore(100,'\n');
		while (choice < 1 || choice>3)
		{
			cout << "�������������ѡ��";
			cin >> choice;
			cin.clear();
			cin.ignore(100,'\n');
		}
	}
	if (choice == 1)
	{
		salesman obj1;
		obj1.input();
		obj1.inputDepNo(tempDepNo);
		salesman_v.push_back(obj1);
	}
	else if (choice == 2)
	{
		technician obj2;
		obj2.input();
		obj2.inputDepNo(tempDepNo);
		technician_v.push_back(obj2);
	}
	else if (choice == 3)
	{
		manager obj3;
		obj3.input();
		obj3.inputDepNo(tempDepNo);
		manager_v.push_back(obj3);
	}
	else if (choice == 4)
	{
		salesmanager obj4;
		obj4.input();
		obj4.inputDepNo(tempDepNo);
		salesmanager_v.push_back(obj4);
	}
	else
	{
		cout << "������󣬳��򽫷���" << endl;
		system("pause");
		return;
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

bool interFace::searchDep(int checkDepID)
{
	for (auto &i : department_v)
	{
		if (i.getDepNo() == checkDepID)
		{
			tempDep = i;
			return true;
		}
	}
	return false;
}

bool interFace::searchDep(string checkDepName) 
{
	for (auto &i : department_v)
	{
		if (i.getDepName() == checkDepName)
		{
			tempDep = i;
			return true;
		}
	}
	return false;
}

void interFace::checkByDep()
{
	cout << "�������ƣ�" << tempDep.getDepNo() << '-' << tempDep.getDepName() << endl;
	cout << "����������" << tempDep.getCount() << endl<<endl;

	for (auto &i : salesman_v)
	{
		if(i.getDepartment()==tempDep.getDepNo())
			i.printNoHead();
	}
	for (auto &i : technician_v)
	{
		if (i.getDepartment() == tempDep.getDepNo())
			i.printNoHead();
	}
	for (auto &i : salesmanager_v)
	{
		if (i.getDepartment() == tempDep.getDepNo())
			i.printNoHead();
	}
	for (auto &i : manager_v)
	{
		if (i.getDepartment() == tempDep.getDepNo())
			i.printNoHead();
	}

}

void interFace::tempAll()
{
	temp_v.swap(vector<basicInfo*>());
	for (auto &i : technician_v)
	{
		temp_v.push_back(&i);
	}
	for (auto &i : salesman_v)
	{
		temp_v.push_back(&i);
	}
	for (auto &i : salesmanager_v)
	{
		temp_v.push_back(&i);
	}
	for (auto &i : manager_v)
	{
		temp_v.push_back(&i);
	}
}

void interFace::sortAndPrintAll()
{
	tempAll();
	sort(temp_v.begin(), temp_v.end());
	//��һ����ͷ
	for (auto &i : temp_v)
	{
		i->printNoHead();
	}
	temp_v.swap(vector<basicInfo*>());

}

bool interFace::searchByName(string checkName)
{
	bool found = true;
	tempAll();
	for (auto &i : temp_v)
	{
		if (i->getName() == checkName)
		{
			tempPerson = i;
			found = true;
		}
	}
	temp_v.swap(vector<basicInfo*>());
	return found;
}

bool interFace::searchByNo(int checkNo)
{
	bool found = false;
	tempAll();
	for (auto &i : temp_v)
	{
		if (i->getNo() == checkNo)
		{
			tempPerson = i;
			found = true;
		}		
	}
	temp_v.swap(vector<basicInfo*>());
	return found;
}

void interFace::changeWorkPost()
{
	cout << "������Ҫ�޸ĵ��ĸ�λ��ţ�1-����Ա 2-����Ա 3-���۾��� 4-����0���أ���";
	int choose = -1;
	cin >> choose;
	cin.clear();
	cin.ignore(100,'\n');
	while (choose < 1 && choose>4)
	{
		if (!choose)
		{
			return;
		}
		cout << "�����������������" << endl;
		cout << "��λ��ţ�����0���أ���";
		cin >> choose;
		cin.clear();
		cin.ignore(100,'\n');
	}
	if (choose == tempPerson->getWorkPost())
		return;
	if (choose == 1)
	{
		salesman obj1;
		obj1.setBasicInfo(tempPerson->getNo(), tempPerson->getName(), tempPerson->getSex(), tempPerson->getDepartment(), tempPerson->getBirthday());
		deletePerson();
		salesman_v.push_back(obj1);
	}
	if (choose == 2)
	{
		technician obj2;
		obj2.setBasicInfo(tempPerson->getNo(), tempPerson->getName(), tempPerson->getSex(), tempPerson->getDepartment(), tempPerson->getBirthday());
		deletePerson();
		technician_v.push_back(obj2);
	}
	if (choose == 3)
	{
		if (!checkSalesManager(tempPerson->getDepartment()))
		{
			cout << "�ò����������۾������򽫲����޸ģ�ֱ�ӷ���";
			system("pause");
			return;
		}
		salesmanager obj3;
		obj3.setBasicInfo(tempPerson->getNo(), tempPerson->getName(), tempPerson->getSex(), tempPerson->getDepartment(), tempPerson->getBirthday());
		deletePerson();
		salesmanager_v.push_back(obj3);
	}
	if (choose == 4)
	{
		manager obj4;
		obj4.setBasicInfo(tempPerson->getNo(), tempPerson->getName(), tempPerson->getSex(), tempPerson->getDepartment(), tempPerson->getBirthday());
		deletePerson();
		manager_v.push_back(obj4);
	}
}

void interFace::reduceDepCount(int depNo)
{
	for (auto &i : department_v)
	{
		if (i.getDepNo() == depNo)
			i.reduceCount();
	}
}

bool interFace::deletePerson()
{
	int depPerson = tempPerson->getDepartment();
	if (depPerson == 1)
	{
		for (vector<salesman>::iterator it = salesman_v.begin(); it != salesman_v.end(); it++)
		{
			if (it->getNo() == tempPerson->getNo())
			{
				it = salesman_v.erase(it);
				return true;
			}
		}
	}
	else if (depPerson == 2)
	{
		for (vector<technician>::iterator it = technician_v.begin(); it != technician_v.end(); it++)
		{
			if (it->getNo() == tempPerson->getNo())
			{
				it = technician_v.erase(it);
				return true;
			}
		}
	}
	else if (depPerson == 3)
	{
		for (vector<salesmanager>::iterator it = salesmanager_v.begin(); it != salesmanager_v.end(); it++)
		{
			if (it->getNo() == tempPerson->getNo())
			{
				it = salesmanager_v.erase(it);
				return true;
			}
		}
	}
	else if (depPerson == 4)
	{
		for (vector<manager>::iterator it = manager_v.begin(); it != manager_v.end(); it++)
		{
			if (it->getNo() == tempPerson->getNo())
			{
				it = manager_v.erase(it);
				return true;
			}
		}
	}
	return false;
}

bool interFace::vectorToFile()
{
	system("cls");
	cout << "��������д���ļ��У����Ժ󡭡�" << endl;
	int countSalesman = 0;
	int countSalesmanager = 0;
	int countTechnician = 0;
	int countManager = 0;
	int countDep = 0;
	ofstream salesman_f("salesman.dat");
	for (auto &i : salesman_v)
	{
		salesman_f << i << endl;
		countSalesman++;
	}
	salesman_f.close();
	ofstream technician_f("technician.dat");
	for (auto &i : technician_v)
	{
		technician_f << i << endl;
		countTechnician++;
	}
	technician_f.close();
	ofstream salesmanager_f("salesmanager.dat");
	for (auto &i : salesmanager_v)
	{
		salesmanager_f << i << endl;
		countSalesmanager++;
	}
	salesmanager_f.close();
	ofstream manager_f("manager.dat");
	for (auto &i : manager_v)
	{
		manager_f << i << endl;
		countManager++;
	}
	manager_f.close();
	ofstream department_f("department.dat");
	for (auto &i : department_v)
	{
		department_f << i << endl;
		countDep++;
	}
	department_f.close();
	cout << "����д��ɹ�������" << countDep << "�����ţ�" << countSalesman << "������Ա��" << countTechnician << "������Ա��" << countSalesmanager << "�����۾���" << countManager << "������" << endl;
	system("pause");
	return true;
}

bool interFace::fileToVector()
{
	system("cls");
	cout << "�������ڴ��ļ���ȡ�У����Ժ󡭡�" << endl;
	int countSalesman = 0;
	int countSalesmanager = 0;
	int countTechnician = 0;
	int countManager = 0;
	int countDep = 0;
	ifstream department_f("department.dat");
	if (!department_f)
		NULL;
	else
	{
		while (!department_f.eof())
		{
			department dep;
			department_f >> dep;
			countDep++;
			department_v.push_back(dep);
			if (department_f.eof())
			{
				countDep--;
				department_v.pop_back();
				break;
			}
		}
		department_f.close();
	}


	ifstream salesman_f("salesman.dat");
	if (!salesman_f)
		NULL;
	else
	{
		while (!salesman_f.eof())
		{
			salesman person;
			salesman_f >> person;
			countSalesman++;
			salesman_v.push_back(person);
			if (salesman_f.eof())
			{
				countSalesman--;
				salesman_v.pop_back();
				break;
			}
		}
		salesman_f.close();
	}	


	ifstream technician_f("technician.dat");
	if (!technician_f)
		NULL;
	else
	{
		while (!technician_f.eof())
		{
			technician person;
			technician_f >> person;
			countTechnician++;
			technician_v.push_back(person);
			if (technician_f.eof())
			{
				countTechnician--;
				technician_v.pop_back();
				break;
			}
		}
		technician_f.close();
	}


	ifstream salesmanager_f("salesmanager.dat");
	if (!salesmanager_f)
		NULL;
	else
	{
		while (!salesmanager_f.eof())
		{
			salesmanager person;
			salesmanager_f >> person;
			countSalesmanager++;
			salesmanager_v.push_back(person);
			if (salesmanager_f.eof())
			{
				countSalesmanager--;
				salesmanager_v.pop_back();
				break;
			}
		}
		salesmanager_f.close();
	}


	ifstream manager_f("manager.dat");
	if (!manager_f)
		NULL;
	else
	{
		while (!manager_f.eof())
		{
			manager person;
			manager_f >> person;
			countManager++;
			manager_v.push_back(person);
			if (manager_f.eof())
			{
				countManager--;
				manager_v.pop_back();
				break;
			}
		}
		manager_f.close();
	}

	cout << "���ݶ�ȡ�ɹ�������" << countDep << "�����ţ�" << countSalesman << "������Ա��" << countTechnician << "������Ա��" << countSalesmanager << "�����۾���" << countManager << "������" << endl;
	system("pause");
	return true;
}
