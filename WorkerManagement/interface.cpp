#include "ALL.h"

void interFace::mainMenu()
{
	system("cls");
	cout << "Ա����Ϣ����ϵͳ" << endl
		<< "==============================" << endl;
	cout << "1.���Ӳ�����Ϣ��Ա����Ϣ" << endl
		<< "2.�޸Ĳ�����Ϣ��Ա����Ϣ" << endl
		<< "3.��ѯ������Ϣ��Ա����Ϣ" << endl
		<< "4.ɾ��������Ϣ��Ա����Ϣ" << endl
		<< "5.ͳ�Ʒ������Ż�Ա����Ϣ" << endl
		<< "6.������Ϣ���˳�ϵͳ" << endl;
	cout << "�������Ӧ��ţ�1-6����";
	int choice = 0;
	cin >> choice;
	cin.clear();
	cin.ignore(100, '\n');
	while (choice < 1 || choice>6)
	{
		cout << "�������������ѡ��";
		cin >> choice;
		cin.clear();
		cin.ignore(100, '\n');
	}
	if (choice == 1)
		addMenu();
	else if (choice == 2)
		changeMenu();
	else if (choice == 3)
		checkMenu();
	else if (choice == 4)
		deleteMenu();
	else if (choice == 5)
		analysisMenu();
	else
	{
		system("cls");
		cout << "Ա����Ϣ����ϵͳ����������Ϣ���˳�ϵͳ" << endl
			<< "===========================================" << endl;
		if (!vectorToFile())
		{
			cout << "�ļ����治�ɹ�" << endl;
			system("pause");
		}
		exit(0);
	}
}

void interFace::addMenu()
{
	while (1)
	{
		system("cls");
		cout << "Ա����Ϣ����ϵͳ�������Ӳ�����Ϣ��Ա����Ϣ" << endl
			<< "===========================================" << endl;
		cout << "ע�⣺���Ա��ǰ��Ҫ����Ӳ�����Ϣ" << endl
			<< "1.��Ӳ�����Ϣ" << endl
			<< "2.���Ա����Ϣ" << endl
			<< "3.������һ��˵�" << endl;
		cout << "�������Ӧ��ţ�1-3����";
		int choice = 0;
		cin >> choice;
		cin.clear();
		cin.ignore(100, '\n');
		while (choice < 1 || choice>3)
		{
			cout << "�������������ѡ��";
			cin >> choice;
			cin.clear();
			cin.ignore(100, '\n');
		}
		system("cls");
		if (choice == 1)
			addDep();
		else if (choice == 2)
			addPerson();
		else
			return;
	}
}

void interFace::changeMenu()
{
	while (1)
	{
		system("cls");
		cout << "Ա����Ϣ����ϵͳ�����޸Ĳ�����Ϣ��Ա����Ϣ" << endl
			<< "===========================================" << endl;
		cout << "ע�⣺Ա�����źͲ��ű�ž������޸�" << endl
			<< "1.�޸Ĳ�������" << endl
			<< "2.�޸�Ա����Ϣ" << endl
			<< "3.������һ��˵�" << endl;
		cout << "�������Ӧ��ţ�1-3����";
		int choice = 0;
		cin >> choice;
		cin.clear();
		cin.ignore(100, '\n');
		while (choice < 1 || choice>3)
		{
			cout << "�������������ѡ��";
			cin >> choice;
			cin.clear();
			cin.ignore(100, '\n');
		}
		system("cls");
		if (choice == 1)
			changeDepName();
		else if (choice == 2)
			changePersonInfo();
		else if (choice == 3)
			return;
	}
}

void interFace::checkMenu()
{
	while (1)
	{
		system("cls");
		cout << "Ա����Ϣ����ϵͳ������ѯ������Ϣ��Ա����Ϣ" << endl
			<< "===========================================" << endl;
		cout << "1.�鿴���в���" << endl
			<< "2.���ݲ��ű�Ų�ѯ����Ա����Ϣ" << endl
			<< "3.���ݲ������ֲ�ѯ����Ա����Ϣ" << endl
			<< "4.��ҳ��ѯ����Ա����Ϣ�������ʸߵ������" << endl
			<< "5.��ѯ��������Ա��Ϣ" << endl
			<< "6.��ѯ���м���Ա��Ϣ" << endl
			<< "7.��ѯ�������۾�����Ϣ" << endl
			<< "8.��ѯ���о�����Ϣ" << endl
			<< "9.������һ��˵�" << endl;
		cout << "�������Ӧ��ţ�1-9����";
		int choice = 0;
		cin >> choice;
		cin.clear();
		cin.ignore(100, '\n');
		while (choice < 1 || choice>9)
		{
			cout << "�������������ѡ��";
			cin >> choice;
			cin.clear();
			cin.ignore(100, '\n');
		}
		system("cls");
		if (choice == 1)
		{
			for (auto &i : department_v)
				i.getDepInfo();
		}
		else if (choice == 2)
		{
			cout << "������Ҫ��ѯ�Ĳ��ű��,����0���أ�";
			choice = -1;
			cin >> choice;
			cin.clear();
			cin.ignore(100, '\n');
			if (!choice)
				return;
			while (choice < 0 || !searchDep(choice))
			{
				cout << "�������������ѡ��";
				cin >> choice;
				cin.clear();
				cin.ignore(100, '\n');
			}
			system("cls");
			tempDep.getDepInfo();
			tempAll();
			for (auto &i : temp_v)
			{
				//��һ����ͷ
				if (i->getDepartment() == tempDep.getDepNo())
				{
					i->printNoHead();
				}
			}
		}
		else if (choice == 3)
		{
			string depNameToCheck;
			cin >> depNameToCheck;
			if (!searchDep(depNameToCheck))
			{
				cout << "�Ҳ����ò��ţ���˶�" << endl;
			}
			else
			{
				system("cls");
				tempDep.getDepInfo();
				tempAll();
				for (auto &i : temp_v)
				{
					//��һ����ͷ
					if (i->getDepartment() == tempDep.getDepNo())
					{
						i->printNoHead();
					}
				}
			}
		}
		else if (choice == 4)
		{
			printByPages();
		}
		else if (choice == 5)
		{
			//��һ����ͷ
			for (auto &i : salesman_v)
				i.printNoHead();
			cout << "=========================" << endl;
			cout << "ȫ����Ϣ����ʾ��ȫ" << endl;
		}
		else if (choice == 6)
		{
			//��һ����ͷ
			for (auto &i : technician_v)
				i.printNoHead();
			cout << "=========================" << endl;
			cout << "ȫ����Ϣ����ʾ��ȫ" << endl;
		}
		else if (choice == 7)
		{
			//��һ����ͷ
			for (auto &i : salesmanager_v)
				i.printNoHead();
			cout << "=========================" << endl;
			cout << "ȫ����Ϣ����ʾ��ȫ" << endl;	
		}
		else if (choice == 8)
		{
			//��һ����ͷ
			for (auto &i : manager_v)
				i.printNoHead();
			cout << "=========================" << endl;
			cout << "ȫ����Ϣ����ʾ��ȫ" << endl;
		}
		else if (choice == 9)
		{
			return;
		}
		system("pause");
	}
}

void interFace::deleteMenu()
{
	while (1)
	{
		system("cls");
		cout << "Ա����Ϣ����ϵͳ����ɾ��������Ϣ��Ա����Ϣ" << endl
			<< "===========================================" << endl;
		cout << "ע�⣺ɾ�����Ż�ͬ��ɾ���ò��ŵ�Ա����Ϣ" << endl;
		cout << "1.ɾ��������Ϣ" << endl
			<< "2.ɾ��Ա����Ϣ" << endl
			<< "3.������һ��" << endl;
		cout << "�������Ӧ��ţ�1-3����";
		int choice = 0;
		cin >> choice;
		cin.clear();
		cin.ignore(100, '\n');
		while (choice < 1 || choice>3)
		{
			cout << "�������������ѡ��";
			cin >> choice;
			cin.clear();
			cin.ignore(100, '\n');
		}
		system("cls");
		if (choice == 1)
		{
			cout << "������Ҫɾ���Ĳ��ű��,����0���أ�";
			choice = -1;
			cin >> choice;
			cin.clear();
			cin.ignore(100, '\n');
			if (!choice)
				return;
			while (choice < 0 || !searchDep(choice))
			{
				cout << "�������������ѡ��";
				cin >> choice;
				cin.clear();
				cin.ignore(100, '\n');
			}
			system("cls");
			tempDep.getDepInfo();
			tempAll();
			for (auto &i : temp_v)
			{
				//��һ����ͷ
				if (i->getDepartment() == tempDep.getDepNo())
				{
					i->printNoHead();
				}
			}
			cout << "=========================================" << endl;
			cout << "ȷ��ɾ���ò��ż�����Ա����Ϣ���밴1ȷ����";
			choice = 0;
			cin >> choice;
			cin.clear();
			cin.ignore(100, '\n');
			if (choice == 1)
				if (deleteDep(tempDep))
					cout << "ɾ���ɹ�" << endl;
				else
					cout << "ɾ��ʧ��" << endl;
		}
		else if (choice == 2)
		{
			cout << "Ŀǰ����ͨ��Ա�����Ż�����������Ҫ�޸ĵ�Ա��" << endl
				<< "1-����  2-����" << endl;
			cout << "��ѡ���Ӧ��ţ�����0���Է�����һ�㣺";
			choice = -1;
			cin >> choice;
			cin.clear();
			cin.ignore(100, '\n');
			while (choice < 0 || choice>2)
			{
				cout << "�������������ѡ��";
				cin >> choice;
				cin.clear();
				cin.ignore(100, '\n');
			}
			system("cls");
			if (!choice)
				continue;
			else if (choice == 1)
			{
				cout << "������Ա��������";
				string name;
				cin >> name;
				if (!searchByName(name))
				{
					cout << "����������󣬳���᷵��";
					system("pause");
					continue;
				}
			}
			else if (choice == 2)
			{
				cout << "������Ա�����ţ�";
				int no = 0;
				cin >> no;
				if (!searchByNo(no) || !no)
				{
					cout << "����������󣬳��򽫷���";
					system("pause");
					continue;
				}
			}
			system("cls");
			tempPerson->printSingle();
			cout << "ȷ��ɾ����Ա������Ϣ���밴1ȷ����";
			choice = 0;
			cin >> choice;
			cin.clear();
			cin.ignore(100, '\n');
			if (choice == 1)
				if (deletePerson())
					cout << "ɾ���ɹ�" << endl;
				else
					cout << "ɾ��ʧ��" << endl;
		}
		else if(choice==3)
			return;
	}
}

void interFace::analysisMenu()
{
	while(1)
	{
		system("cls");
		cout << "Ա����Ϣ����ϵͳ������ѯ������Ϣ��Ա����Ϣ" << endl
			<< "===========================================" << endl;
		cout << "1.ͳ�Ʋ���ʾĳ�����ŵ�ƽ���¹��ʡ�����¹��ʡ�����¹���" << endl
			<< "2.ͳ�Ʋ���ʾĳ�����ų���������ƽ���¹��ʵ�������Ա����Ϣ" << endl
			<< "3.ͳ�Ʋ���ʾ����Ա���е�����¹��ʺ�����¹���Ա������Ϣ" << endl
			<< "4.ͳ�Ʋ���ʾ����Ա������ƽ���¹��ʵ�������Ա����Ϣ" << endl
			<< "5.�鿴����λ��ƽ������" << endl
			<< "6.������һ��˵�" << endl;
		cout << "�������Ӧ��ţ�1-6����";
		int choice = 0;
		cin >> choice;
		cin.clear();
		cin.ignore(100, '\n');
		while (choice < 1 || choice>6)
		{
			cout << "�������������ѡ��";
			cin >> choice;
			cin.clear();
			cin.ignore(100, '\n');
		}
		system("cls");
		if (choice == 1)
		{
			cout << "������Ҫ��ѯ�Ĳ��ű��,����0���أ�";
			choice = -1;
			cin >> choice;
			cin.clear();
			cin.ignore(100, '\n');
			double maxSalary = 0;
			double minSalary = 0;
			if (!choice)
				continue;
			while (choice < 0 || !searchDep(choice))
			{
				cout << "�������������ѡ��";
				cin >> choice;
				cin.clear();
				cin.ignore(100, '\n');
			}
			system("cls");
			if (tempDep.getCount() == 0)
			{
				cout << "�ò���Ϊ��" << endl;
				system("pause");
				continue;
			}
			tempDep.getDepInfo();
			tempAll();
			calAllSalary();
			for (auto &i : temp_v)
			{
				if (i->getDepartment() == tempDep.getDepNo())
				{
					maxSalary = i->getSalary();
					minSalary = i->getSalary();
					break;
				}
			}
			for (auto &i : temp_v)
			{
				if (i->getDepartment() == tempDep.getDepNo())
				{
					if(maxSalary < i->getSalary())
						maxSalary = i->getSalary();
					if (minSalary > i->getSalary())
						minSalary = i->getSalary();
				}
			}
			cout << "ƽ�����ʣ�" << tempDep.calAverageSalary() << endl
				<< "��͹��ʣ�" << minSalary << endl
				<< "��߹��ʣ�" << maxSalary << endl;
		}
		if (choice == 2)
		{
			cout << "������Ҫ��ѯ�Ĳ��ű��,����0���أ�";
			choice = -1;
			cin >> choice;
			cin.clear();
			cin.ignore(100, '\n');
			if (!choice)
				continue;
			int count = 0;
			while (choice < 0 || !searchDep(choice))
			{
				cout << "�������������ѡ��";
				cin >> choice;
				cin.clear();
				cin.ignore(100, '\n');
			}
			system("cls");
			if (tempDep.getCount() == 0)
			{
				cout << "�ò���Ϊ��" << endl;
				system("pause");
				continue;
			}
			tempDep.getDepInfo();
			tempAll();
			calAllSalary();
			double averageSalary = tempDep.calAverageSalary();
			for (auto &i : temp_v)
			{
				//��һ����ͷ
				if (i->getDepartment() == tempDep.getDepNo())
				{
					if (i->getSalary() >= averageSalary)
					{
						i->printNoHead();
						count++;
					}
				}
			}
			cout << "==========================================" << endl;
			cout << "ȫ����Ϣ����ʾ��ȫ,����ƽ�����ʵ�������" << count << endl;
		}
		else if (choice == 3)
		{
			double maxSalary = 0;
			double minSalary = 0;
			tempAll();
			calAllSalary();
			for (auto &i : temp_v)
			{
				maxSalary = i->getSalary();
				minSalary = i->getSalary();
				break;
			}
			for (auto &i : temp_v)
			{
				if (maxSalary < i->getSalary())
					maxSalary = i->getSalary();
				if (minSalary > i->getSalary())
					minSalary = i->getSalary();
			}
			cout << "ƽ�����ʣ�" << calAverageSalary() << endl
				<< "��͹��ʣ�" << minSalary << endl
				<< "��߹��ʣ�" << maxSalary << endl;
		}
		else if (choice == 4)
		{
			int count = 0;
			tempAll();
			calAllSalary();
			double averageSalary = tempDep.calAverageSalary();
			//��һ����ͷ
			for (auto &i : temp_v)
			{
				if (i->getSalary() >= averageSalary)
				{
					count++;
					i->printNoHead();
				}
			}
			cout << "==========================================" << endl;
			cout << "ȫ����Ϣ����ʾ��ȫ,����ƽ�����ʵ�������" << count << endl;
		}
		else if (choice == 5)
		{
			cout << "����Աƽ�����ʣ�" << calSalesmanAverageSalary() << endl
				<< "����Աƽ�����ʣ�" << calTechnicianAverageSalary() << endl
				<< "���۾���ƽ�����ʣ�" << calSalesmanagerAverageSalary() << endl
				<< "����ƽ�����ʣ�8000" << endl;
		}
		else if(choice==6)
			return;
		system("pause");
	}
}

void interFace::changeDepName()
{
	while(1)
	{
		system("cls");
		getAllDep();
		cout << "������Ҫ�޸ĵĲ��ű��,����0���أ�";
		int choice = -1;
		cin >> choice;
		cin.clear();
		cin.ignore(100, '\n');
		if (!choice)
			return;
		while (choice < 0 || !searchDep(choice))
		{
			cout << "�������������ѡ��";
			cin >> choice;
			cin.clear();
			cin.ignore(100, '\n');
		}
		system("cls");
		for(auto &i:department_v)
		{
			if (i.getDepNo() == tempDep.getDepNo())
			{
				i.changeDepName();
				cout << "�޸ĳɹ�" << endl;
				break;
			}
		}
	}

}

void interFace::changePersonInfo()
{
	cout << "Ŀǰ����ͨ��Ա�����Ż�����������Ҫ�޸ĵ�Ա��" << endl
		<< "1-����  2-����" << endl;
	cout << "��ѡ���Ӧ��ţ�����0���Է�����һ�㣺";
	int choice = -1;
	cin >> choice;
	cin.clear();
	cin.ignore(100, '\n');
	while (choice < 0 || choice>2)
	{
		cout << "�������������ѡ��";
		cin >> choice;
		cin.clear();
		cin.ignore(100, '\n');
	}
	system("cls");
	if (!choice)
		return;
	else if (choice == 1)
	{
		cout << "������Ա��������";
		string name;
		cin >> name;
		if (!searchByName(name))
		{
			cout << "����������󣬳���᷵��";
			system("pause");
			return;
		}
	}
	else
	{
		cout << "������Ա�����ţ�";
		int no = 0;
		cin >> no;
		if(!searchByNo(no)||!no)
		{
			cout << "����������󣬳��򽫷���";
			system("pause");
			return;
		}
	}
	system("cls");
	while (1)
	{
		tempPerson->printSingle();
		cout << "ѡ��Ҫ�޸ĵ���Ŀ" << endl;
		cout << "1-����  2-�Ա�  3-��������  4-����  5-��λ  ";
		if (tempPerson->getWorkPost() == 1)
			cout << "6-���۶�" << endl;
		else if (tempPerson->getWorkPost() == 2)
			cout << "6-����ʱ��" << endl;
		else
			cout << endl;
		cout << "��ѡ������0���أ���";
		system("cls");
		choice = -1;
		cin >> choice;
		cin.clear();
		cin.ignore(100, '\n');
		while (choice < 0 || choice>6)
		{
			cout << "�������������ѡ��";
			cin >> choice;
			cin.clear();
			cin.ignore(100, '\n');
		}
		if (!choice)
			return;
		if (choice == 1)
			tempPerson->changeName();
		else if (choice == 2)
			tempPerson->changeSex();
		else if (choice == 3)
			tempPerson->changeBirthday();
		else if (choice == 4)
		{
			getAllDep();
			bool exist = false;
			cout << "�����벿�ű�ţ�";
			choice = -1;
			cin >> choice;
			cin.clear();
			cin.ignore(100, '\n');
			while (choice < 1 || !searchDep(choice))
			{
				cout << "�������������ѡ��";
				cin >> choice;
				cin.clear();
				cin.ignore(100, '\n');
			}
			system("cls");
			if (!choice)
				return;
			for (auto &i : department_v)
			{
				if (i.getDepNo() == tempDep.getDepNo())
				{
					exist = true;
					break;
				}
			}
			if (!exist)
			{
				cout << "�ò��Ų����ڣ����򽫷���";
				system("pause");
				return;
			}
			else
				tempPerson->changeDep(choice);
		}
		else if (choice == 5)
			changeWorkPost();
		else if (choice == 6)
		{
			if (tempPerson->getWorkPost() == 1)
				tempPerson->changeSaleAmount();
			else if (tempPerson->getWorkPost() == 2)
				tempPerson->changeWorkTime();
			else
			{
				cout << "������󣬳��򽫷���";
				system("pause");
				return;
			}
		}
	}
}

void interFace::calAllSalary()
{
	tempAll();
	for (auto &i : temp_v)
	{
		i->calSalary();
	}
}

double interFace::calAverageSalary()
{
	calAllSalary();
	double averageSalary = 0;
	for (auto &i : temp_v)
	{
		averageSalary += i->getSalary();
	}
	averageSalary /= temp_v.size();
	return averageSalary;
}

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

void interFace::sortAll()
{
	tempAll();
	sort(temp_v.begin(), temp_v.end());
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
	int depPerson = tempPerson->getWorkPost();
	for (auto &i : department_v)
	{
		if (tempPerson->getDepartment() == i.getDepNo())
		{
			i.reduceCount();
			break;
		}
	}
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
	system("cls");
	return true;
}

void interFace::printByPages()
{
	sortAll();
	if (!temp_v.size())
		{
		cout << "�����ݣ������������" << endl;
		system("pause");
		}
	cout << "����ȡ" << temp_v.size() << "����¼��" << endl;
	cout << "��¼�ᰴ�չ��ʴӸߵ���������������ϣ��һҳ��ӡ������¼" << endl;
	cout << "����һ������0��С�ڻ����" << temp_v.size() << "��������";
	int numToPrint=0;
	int choice = 0;
	cin >> numToPrint;
	cin.clear();
	cin.ignore(100, '\n');
	while (!numToPrint || numToPrint > temp_v.size())
	{
		cout << "����������������룺";
		cin >> numToPrint;
		cin.clear();
		cin.ignore(100, '\n');
	}
	double totalPage = temp_v.size() / numToPrint;
	bool finished = false;
FirstPage:
	int numToCount = 0;
	int page = 1;
	int endOfCount = numToPrint - 1;
	//��һ����ͷ
	for (;numToCount!=temp_v.size(); numToCount++)
	{
		temp_v[numToCount]->printNoHead();
		if (numToCount == endOfCount)
		{
			numToCount++;
			finished = true;
			break;
		}
	}
	if (!finished || numToPrint == temp_v.size())
	{
		if (page == 1)
		{
			cout << endl << "ȫ����Ϣ����ʾ��ȫ" << endl;
			system("pause");
			system("cls");
			temp_v.swap(vector<basicInfo*>());
			return;
		}
		else
		{
EndPage:
			cout << endl << "��ҳ����ʾ��ȫ" << endl;
			cout << "1-��һҳ   2-����" << endl;
			cout << "��ѡ��1-2����";
			int choice = 0;
			cin >> choice;
			cin.clear();
			cin.ignore(100, '\n');
			while (choice < 1 || choice>2)
			{
				cout << "�������������ѡ��";
				cin >> choice;
				cin.clear();
				cin.ignore(100, '\n');
			}
			system("cls");
			if (choice == 1)
				goto FrontPage;
			else
			{
				temp_v.swap(vector<basicInfo*>());
				return;
			}
		}
	}
	cout << endl << "��ҳ����ʾ��ȫ" << endl;
	cout << "1-��һҳ   2-����" << endl;
	cout << "��ѡ��1-2����";
	choice = 0;		
	cin >> choice;
	cin.clear();
	cin.ignore(100, '\n');
	while (choice < 1 || choice>2)
	{
		cout << "�������������ѡ��";
		cin >> choice;
		cin.clear();
		cin.ignore(100, '\n');
	}
	system("cls");
	if (choice == 1)
	{
NextPage:
		page++;
		endOfCount += numToPrint;
NormalPage:
		finished = false;
		for (; numToCount != temp_v.size(); numToCount++)
		{
			temp_v[numToCount]->printNoHead();
			if (numToCount == endOfCount)
			{
				finished = true;
				numToCount++;
				break;
			}
		}
		if (!finished || page >= totalPage)
			goto EndPage;
		cout << endl << "��ҳ����ʾ��ȫ" << endl;
		cout << "1-��һҳ   2-��һҳ   3-����" << endl;
		cout << "��ѡ��1-3����";
		choice = 0;
		cin >> choice;
		cin.clear();
		cin.ignore(100, '\n');
		while (choice < 1 || choice>3)
		{
			cout << "�������������ѡ��";
			cin >> choice;
			cin.clear();
			cin.ignore(100, '\n');
		}
		system("cls");
		if (choice == 1)
		{
FrontPage:
			page--;
			endOfCount -= numToPrint;
			if (page == 1)
				goto FirstPage;
			else
			{
				numToCount -= numToPrint;
				goto NormalPage;
			}
		}
		else if (choice == 2)
			goto NextPage;
		else
		{
			temp_v.swap(vector<basicInfo*>());
			return;
		}
	}
	else
	{
		temp_v.swap(vector<basicInfo*>());
		return;
	}
}

double interFace::calSalesmanAverageSalary()
{
	double salesmanAverageSalary=0;
	for (auto &i : salesman_v)
	{
		i.calSalary();
		salesmanAverageSalary += i.getSalary();
	}
	salesmanAverageSalary /= salesman_v.size();
	return salesmanAverageSalary;
}

double interFace::calSalesmanagerAverageSalary()
{
	double salesmanagerAverageSalary=0;
	for (auto &i : salesmanager_v)
	{
		i.calSalary();
		salesmanagerAverageSalary += i.getSalary();
	}
	salesmanagerAverageSalary /= salesmanager_v.size();
	return salesmanagerAverageSalary;
}

double interFace::calTechnicianAverageSalary()
{
	double technicianAverageSalary=0;
	for (auto &i : technician_v)
	{
		i.calSalary();
		technicianAverageSalary += i.getSalary();
	}
	technicianAverageSalary /= technician_v.size();
	return  technicianAverageSalary;
}
