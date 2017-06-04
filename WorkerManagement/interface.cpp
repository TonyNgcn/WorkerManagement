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
	cout << "添加员工" << endl;
	cout << "请选择员工的职位：\n1.销售员\n2.技术员\n3.经理\n4.销售经理" << endl;
	cout << "请输入选择（1-4）：";
	int choice=0;
	cin >> choice;
	while (choice < 1 || choice>4)
	{
		cout << "输入错误，请重新选择：";
		cin >> choice;
	}
	switch (choice)
	{
	case 1:

	}
}

