#include "ALL.h"

void interFace::mainMenu()
{
	system("cls");
	cout << "员工信息管理系统" << endl
		<< "==============================" << endl;
	cout << "1.增加部门信息或员工信息" << endl
		<< "2.修改部门信息或员工信息" << endl
		<< "3.查询部门信息或员工信息" << endl
		<< "4.删除部门信息或员工信息" << endl
		<< "5.统计分析部门或员工信息" << endl
		<< "6.保存信息并退出系统" << endl;
	cout << "请输入对应序号（1-6）：";
	int choice = 0;
	cin >> choice;
	cin.clear();
	cin.ignore(100, '\n');
	while (choice < 1 || choice>6)
	{
		cout << "输入错误，请重新选择：";
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
		cout << "员工信息管理系统——保存信息并退出系统" << endl
			<< "===========================================" << endl;
		if (!vectorToFile())
		{
			cout << "文件保存不成功" << endl;
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
		cout << "员工信息管理系统——增加部门信息或员工信息" << endl
			<< "===========================================" << endl;
		cout << "注意：添加员工前需要先添加部门信息" << endl
			<< "1.添加部门信息" << endl
			<< "2.添加员工信息" << endl
			<< "3.返回上一层菜单" << endl;
		cout << "请输入对应序号（1-3）：";
		int choice = 0;
		cin >> choice;
		cin.clear();
		cin.ignore(100, '\n');
		while (choice < 1 || choice>3)
		{
			cout << "输入错误，请重新选择：";
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
		cout << "员工信息管理系统——修改部门信息或员工信息" << endl
			<< "===========================================" << endl;
		cout << "注意：员工工号和部门编号均不可修改" << endl
			<< "1.修改部门名字" << endl
			<< "2.修改员工信息" << endl
			<< "3.返回上一层菜单" << endl;
		cout << "请输入对应序号（1-3）：";
		int choice = 0;
		cin >> choice;
		cin.clear();
		cin.ignore(100, '\n');
		while (choice < 1 || choice>3)
		{
			cout << "输入错误，请重新选择：";
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
		cout << "员工信息管理系统——查询部门信息或员工信息" << endl
			<< "===========================================" << endl;
		cout << "1.查看已有部门" << endl
			<< "2.根据部门编号查询部门员工信息" << endl
			<< "3.根据部门名字查询部门员工信息" << endl
			<< "4.分页查询所有员工信息（按工资高低输出）" << endl
			<< "5.查询所有销售员信息" << endl
			<< "6.查询所有技术员信息" << endl
			<< "7.查询所有销售经理信息" << endl
			<< "8.查询所有经理信息" << endl
			<< "9.返回上一层菜单" << endl;
		cout << "请输入对应序号（1-9）：";
		int choice = 0;
		cin >> choice;
		cin.clear();
		cin.ignore(100, '\n');
		while (choice < 1 || choice>9)
		{
			cout << "输入错误，请重新选择：";
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
			cout << "请输入要查询的部门编号,输入0返回：";
			choice = -1;
			cin >> choice;
			cin.clear();
			cin.ignore(100, '\n');
			if (!choice)
				return;
			while (choice < 0 || !searchDep(choice))
			{
				cout << "输入错误，请重新选择：";
				cin >> choice;
				cin.clear();
				cin.ignore(100, '\n');
			}
			system("cls");
			tempDep.getDepInfo();
			tempAll();
			for (auto &i : temp_v)
			{
				//差一个表头
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
				cout << "找不到该部门，请核对" << endl;
			}
			else
			{
				system("cls");
				tempDep.getDepInfo();
				tempAll();
				for (auto &i : temp_v)
				{
					//差一个表头
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
			//差一个表头
			for (auto &i : salesman_v)
				i.printNoHead();
			cout << "=========================" << endl;
			cout << "全部信息已显示完全" << endl;
		}
		else if (choice == 6)
		{
			//差一个表头
			for (auto &i : technician_v)
				i.printNoHead();
			cout << "=========================" << endl;
			cout << "全部信息已显示完全" << endl;
		}
		else if (choice == 7)
		{
			//差一个表头
			for (auto &i : salesmanager_v)
				i.printNoHead();
			cout << "=========================" << endl;
			cout << "全部信息已显示完全" << endl;	
		}
		else if (choice == 8)
		{
			//差一个表头
			for (auto &i : manager_v)
				i.printNoHead();
			cout << "=========================" << endl;
			cout << "全部信息已显示完全" << endl;
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
		cout << "员工信息管理系统——删除部门信息或员工信息" << endl
			<< "===========================================" << endl;
		cout << "注意：删除部门会同步删除该部门的员工信息" << endl;
		cout << "1.删除部门信息" << endl
			<< "2.删除员工信息" << endl
			<< "3.返回上一层" << endl;
		cout << "请输入对应序号（1-3）：";
		int choice = 0;
		cin >> choice;
		cin.clear();
		cin.ignore(100, '\n');
		while (choice < 1 || choice>3)
		{
			cout << "输入错误，请重新选择：";
			cin >> choice;
			cin.clear();
			cin.ignore(100, '\n');
		}
		system("cls");
		if (choice == 1)
		{
			cout << "请输入要删除的部门编号,输入0返回：";
			choice = -1;
			cin >> choice;
			cin.clear();
			cin.ignore(100, '\n');
			if (!choice)
				return;
			while (choice < 0 || !searchDep(choice))
			{
				cout << "输入错误，请重新选择：";
				cin >> choice;
				cin.clear();
				cin.ignore(100, '\n');
			}
			system("cls");
			tempDep.getDepInfo();
			tempAll();
			for (auto &i : temp_v)
			{
				//差一个表头
				if (i->getDepartment() == tempDep.getDepNo())
				{
					i->printNoHead();
				}
			}
			cout << "=========================================" << endl;
			cout << "确定删除该部门及所有员工信息，请按1确定：";
			choice = 0;
			cin >> choice;
			cin.clear();
			cin.ignore(100, '\n');
			if (choice == 1)
				if (deleteDep(tempDep))
					cout << "删除成功" << endl;
				else
					cout << "删除失败" << endl;
		}
		else if (choice == 2)
		{
			cout << "目前可以通过员工工号或姓名查找你要修改的员工" << endl
				<< "1-姓名  2-工号" << endl;
			cout << "请选择对应编号，输入0可以返回上一层：";
			choice = -1;
			cin >> choice;
			cin.clear();
			cin.ignore(100, '\n');
			while (choice < 0 || choice>2)
			{
				cout << "输入错误，请重新选择：";
				cin >> choice;
				cin.clear();
				cin.ignore(100, '\n');
			}
			system("cls");
			if (!choice)
				continue;
			else if (choice == 1)
			{
				cout << "请输入员工姓名：";
				string name;
				cin >> name;
				if (!searchByName(name))
				{
					cout << "姓名输入错误，程序会返回";
					system("pause");
					continue;
				}
			}
			else if (choice == 2)
			{
				cout << "请输入员工工号：";
				int no = 0;
				cin >> no;
				if (!searchByNo(no) || !no)
				{
					cout << "工号输入错误，程序将返回";
					system("pause");
					continue;
				}
			}
			system("cls");
			tempPerson->printSingle();
			cout << "确定删除该员工的信息，请按1确定：";
			choice = 0;
			cin >> choice;
			cin.clear();
			cin.ignore(100, '\n');
			if (choice == 1)
				if (deletePerson())
					cout << "删除成功" << endl;
				else
					cout << "删除失败" << endl;
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
		cout << "员工信息管理系统——查询部门信息或员工信息" << endl
			<< "===========================================" << endl;
		cout << "1.统计并显示某个部门的平均月工资、最低月工资、最高月工资" << endl
			<< "2.统计并显示某个部门超出本部门平均月工资的人数与员工信息" << endl
			<< "3.统计并显示所有员工中的最低月工资和最高月工资员工的信息" << endl
			<< "4.统计并显示所有员工超出平均月工资的人数与员工信息" << endl
			<< "5.查看各岗位的平均工资" << endl
			<< "6.返回上一层菜单" << endl;
		cout << "请输入对应序号（1-6）：";
		int choice = 0;
		cin >> choice;
		cin.clear();
		cin.ignore(100, '\n');
		while (choice < 1 || choice>6)
		{
			cout << "输入错误，请重新选择：";
			cin >> choice;
			cin.clear();
			cin.ignore(100, '\n');
		}
		system("cls");
		if (choice == 1)
		{
			cout << "请输入要查询的部门编号,输入0返回：";
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
				cout << "输入错误，请重新选择：";
				cin >> choice;
				cin.clear();
				cin.ignore(100, '\n');
			}
			system("cls");
			if (tempDep.getCount() == 0)
			{
				cout << "该部门为空" << endl;
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
			cout << "平均工资：" << tempDep.calAverageSalary() << endl
				<< "最低工资：" << minSalary << endl
				<< "最高工资：" << maxSalary << endl;
		}
		if (choice == 2)
		{
			cout << "请输入要查询的部门编号,输入0返回：";
			choice = -1;
			cin >> choice;
			cin.clear();
			cin.ignore(100, '\n');
			if (!choice)
				continue;
			int count = 0;
			while (choice < 0 || !searchDep(choice))
			{
				cout << "输入错误，请重新选择：";
				cin >> choice;
				cin.clear();
				cin.ignore(100, '\n');
			}
			system("cls");
			if (tempDep.getCount() == 0)
			{
				cout << "该部门为空" << endl;
				system("pause");
				continue;
			}
			tempDep.getDepInfo();
			tempAll();
			calAllSalary();
			double averageSalary = tempDep.calAverageSalary();
			for (auto &i : temp_v)
			{
				//差一个表头
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
			cout << "全部信息已显示完全,超过平均工资的人数是" << count << endl;
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
			cout << "平均工资：" << calAverageSalary() << endl
				<< "最低工资：" << minSalary << endl
				<< "最高工资：" << maxSalary << endl;
		}
		else if (choice == 4)
		{
			int count = 0;
			tempAll();
			calAllSalary();
			double averageSalary = tempDep.calAverageSalary();
			//差一个表头
			for (auto &i : temp_v)
			{
				if (i->getSalary() >= averageSalary)
				{
					count++;
					i->printNoHead();
				}
			}
			cout << "==========================================" << endl;
			cout << "全部信息已显示完全,超过平均工资的人数是" << count << endl;
		}
		else if (choice == 5)
		{
			cout << "销售员平均工资：" << calSalesmanAverageSalary() << endl
				<< "技术员平均工资：" << calTechnicianAverageSalary() << endl
				<< "销售经理平均工资：" << calSalesmanagerAverageSalary() << endl
				<< "经理平均工资：8000" << endl;
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
		cout << "请输入要修改的部门编号,输入0返回：";
		int choice = -1;
		cin >> choice;
		cin.clear();
		cin.ignore(100, '\n');
		if (!choice)
			return;
		while (choice < 0 || !searchDep(choice))
		{
			cout << "输入错误，请重新选择：";
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
				cout << "修改成功" << endl;
				break;
			}
		}
	}

}

void interFace::changePersonInfo()
{
	cout << "目前可以通过员工工号或姓名查找你要修改的员工" << endl
		<< "1-姓名  2-工号" << endl;
	cout << "请选择对应编号，输入0可以返回上一层：";
	int choice = -1;
	cin >> choice;
	cin.clear();
	cin.ignore(100, '\n');
	while (choice < 0 || choice>2)
	{
		cout << "输入错误，请重新选择：";
		cin >> choice;
		cin.clear();
		cin.ignore(100, '\n');
	}
	system("cls");
	if (!choice)
		return;
	else if (choice == 1)
	{
		cout << "请输入员工姓名：";
		string name;
		cin >> name;
		if (!searchByName(name))
		{
			cout << "姓名输入错误，程序会返回";
			system("pause");
			return;
		}
	}
	else
	{
		cout << "请输入员工工号：";
		int no = 0;
		cin >> no;
		if(!searchByNo(no)||!no)
		{
			cout << "工号输入错误，程序将返回";
			system("pause");
			return;
		}
	}
	system("cls");
	while (1)
	{
		tempPerson->printSingle();
		cout << "选择要修改的项目" << endl;
		cout << "1-姓名  2-性别  3-出生日期  4-部门  5-岗位  ";
		if (tempPerson->getWorkPost() == 1)
			cout << "6-销售额" << endl;
		else if (tempPerson->getWorkPost() == 2)
			cout << "6-工作时间" << endl;
		else
			cout << endl;
		cout << "请选择（输入0返回）：";
		system("cls");
		choice = -1;
		cin >> choice;
		cin.clear();
		cin.ignore(100, '\n');
		while (choice < 0 || choice>6)
		{
			cout << "输入错误，请重新选择：";
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
			cout << "请输入部门编号：";
			choice = -1;
			cin >> choice;
			cin.clear();
			cin.ignore(100, '\n');
			while (choice < 1 || !searchDep(choice))
			{
				cout << "输入错误，请重新选择：";
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
				cout << "该部门不存在，程序将返回";
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
				cout << "输入错误，程序将返回";
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
	cout << "添加员工" << endl;
	cout << "请选择员工所属部门" << endl;
	getAllDep();
	cout << "请输入部门编号：";
	int choice = 0;
	cin >> choice;
	cin.clear();
	cin.ignore(100, '\n');
	while (!choice)
	{
		cout << "输入错误，请重新选择：";
		cin >> choice;
		cin.clear();
		cin.ignore(100, '\n');
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
		cin.clear();
		cin.ignore(100,'\n');
		while (choice < 1 || choice>4)
		{
			cout << "输入错误，请重新选择：";
			cin >> choice;
			cin.clear();
			cin.ignore(100,'\n');
		}
	}
	else
	{
		cout << "该部门已存在销售经理，所以员工的职位不可以是销售经理" << endl;
		cout << "请选择员工的职位：\n1.销售员\n2.技术员\n3.经理" << endl;
		cout << "请输入选择（1-3）：";
		cin >> choice;
		cin.clear();
		cin.ignore(100,'\n');
		while (choice < 1 || choice>3)
		{
			cout << "输入错误，请重新选择：";
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
		cout << "输入错误，程序将返回" << endl;
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
	cout << "部门名称：" << tempDep.getDepNo() << '-' << tempDep.getDepName() << endl;
	cout << "部门人数：" << tempDep.getCount() << endl<<endl;

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
	cout << "请输入要修改到的岗位编号（1-销售员 2-技术员 3-销售经理 4-经理，0返回）：";
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
		cout << "输入错误，请重新输入" << endl;
		cout << "岗位编号（输入0返回）：";
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
			cout << "该部门已有销售经理，程序将不作修改，直接返回";
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
	cout << "数据正在写入文件中，请稍后……" << endl;
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
	cout << "数据写入成功，共有" << countDep << "个部门，" << countSalesman << "个销售员，" << countTechnician << "个技术员，" << countSalesmanager << "个销售经理，" << countManager << "个经理。" << endl;
	system("pause");
	return true;
}

bool interFace::fileToVector()
{
	system("cls");
	cout << "数据正在从文件读取中，请稍后……" << endl;
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

	cout << "数据读取成功，共有" << countDep << "个部门，" << countSalesman << "个销售员，" << countTechnician << "个技术员，" << countSalesmanager << "个销售经理，" << countManager << "个经理。" << endl;
	system("pause");
	system("cls");
	return true;
}

void interFace::printByPages()
{
	sortAll();
	if (!temp_v.size())
		{
		cout << "无数据，请先添加数据" << endl;
		system("pause");
		}
	cout << "共读取" << temp_v.size() << "条记录。" << endl;
	cout << "记录会按照工资从高到低排序，请输入你希望一页打印几条记录" << endl;
	cout << "输入一个大于0，小于或等于" << temp_v.size() << "的整数：";
	int numToPrint=0;
	int choice = 0;
	cin >> numToPrint;
	cin.clear();
	cin.ignore(100, '\n');
	while (!numToPrint || numToPrint > temp_v.size())
	{
		cout << "输入错误，请重新输入：";
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
	//差一个表头
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
			cout << endl << "全部信息已显示完全" << endl;
			system("pause");
			system("cls");
			temp_v.swap(vector<basicInfo*>());
			return;
		}
		else
		{
EndPage:
			cout << endl << "该页已显示完全" << endl;
			cout << "1-上一页   2-返回" << endl;
			cout << "请选择（1-2）：";
			int choice = 0;
			cin >> choice;
			cin.clear();
			cin.ignore(100, '\n');
			while (choice < 1 || choice>2)
			{
				cout << "输入错误，请重新选择：";
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
	cout << endl << "该页已显示完全" << endl;
	cout << "1-下一页   2-返回" << endl;
	cout << "请选择（1-2）：";
	choice = 0;		
	cin >> choice;
	cin.clear();
	cin.ignore(100, '\n');
	while (choice < 1 || choice>2)
	{
		cout << "输入错误，请重新选择：";
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
		cout << endl << "该页已显示完全" << endl;
		cout << "1-上一页   2-下一页   3-返回" << endl;
		cout << "请选择（1-3）：";
		choice = 0;
		cin >> choice;
		cin.clear();
		cin.ignore(100, '\n');
		while (choice < 1 || choice>3)
		{
			cout << "输入错误，请重新选择：";
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
