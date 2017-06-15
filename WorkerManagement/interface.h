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
	//部门对象临时变量
	department tempDep;

	//员工基类指针临时变量
	basicInfo *tempPerson;

	//储存员工基类指针临时容器
	vector<basicInfo*> temp_v;

	//保存部门的容器
	vector<department> department_v;

	//保存经理的容器
	vector<manager> manager_v;

	//保存销售员的容器
	vector<salesman> salesman_v;

	//保存销售经理的容器
	vector<salesmanager> salesmanager_v;

	//保存技术员的容器
	vector<technician> technician_v;

	//函数功能：主菜单
	void mainMenu();

	//函数功能：用于增加的菜单
	void addMenu();

	//函数功能：用于修改的菜单
	void changeMenu();

	//函数功能：用于查看的菜单
	void checkMenu();

	//函数功能：用于删除的菜单
	void deleteMenu();

	//函数功能：用于分析的菜单
	void analysisMenu();

	//函数功能：修改部门名称
	void changeDepName();

	//函数功能：修改员工信息
	void changePersonInfo();

	//函数功能：计算全部工资
	void calAllSalary();

	//函数功能：计算全体平均工资
	double calAverageSalary();

	//函数功能：删除部门
	bool deleteDep(department);

	//函数功能：输出所有部门
	void getAllDep()const;

	//函数功能：输出制定部门的名称
	void getDepName(int)const;

	//函数功能：增加部门
	void addDep();

	//函数功能：增加员工
	void addPerson();

	//函数功能：增加指定部门的员工数量
	void addCountOfDep(int depNo);

	//函数功能：判断该部门是否存在
	bool checkDepExist(int checkDepID)const;

	//函数功能：判断该部门是否存在销售经理
	bool checkSalesManager(int checkDepID)const;

	//函数功能：根据部门编号查找部门
	bool searchDep(int checkDepID);

	//函数功能：根据部门名称查找部门
	bool searchDep(string checkDepName);

	//函数功能：输出找到部门的信息
	void checkByDep();

	//函数功能：把四种不同岗位的员工放入一个基类指针的容器
	void tempAll();

	//函数功能：对基类指针的容器进行排序
	void sortAll();

	//函数功能：根据姓名查找员工
	bool searchByName(string checkName);

	//函数功能：根据工号查找员工
	bool searchByNo(int checkNo);

	//函数功能：更改工作岗位
	void changeWorkPost();

	//函数功能：减少该部门的人数
	void reduceDepCount(int depNo);

	//函数功能：删除员工
	bool deletePerson();

	//函数功能：把数据从容器读入文件
	bool vectorToFile();

	//函数功能：把数据从文件读入容器
	bool fileToVector();

	//函数功能：分页显示员工信息
	void printByPages();

	//函数功能：计算销售员平均工资
	double calSalesmanAverageSalary();

	//函数功能：计算销售经理平均工资
	double calSalesmanagerAverageSalary();

	//函数功能：计算技术员平均工资
	double calTechnicianAverageSalary();
};
#endif
