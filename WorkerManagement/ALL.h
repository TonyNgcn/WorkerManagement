#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include <iomanip>
#include<vector>
#include<algorithm>
using namespace std;

class department
{
	string depName;   //部门名称
	int depNo;        //部门编号
	int count;        //部门人数
public:
	//函数功能：提取部门名称
	string getDepName()const;

	//函数功能：提取部门编号
	int getDepNo()const;

	//函数功能：输出部门名称、编号
	void printAllDep()const;

	//函数功能：输出该部门名称、编号、人数
	void getDepInfo()const;

	//函数功能：输入部门编号、名称
	void input();

	//函数功能：部门人数加一
	bool addCount();

	//函数功能：提取部门人数
	int getCount()const;

	//函数功能：构造函数
	department();

	//函数功能：修改部门名称
	bool changeDepName();

	//函数功能：部门人数减一
	bool reduceCount();

	//函数功能：检查部门名称是否重复
	bool checkDepName(string toCheck);

	//函数功能：检查部门编号是否重复
	bool checkDepNo(int toCheck);

	//函数功能：计算该部门平均工资
	double calAverageSalary();

	//函数功能：重载输入运算符
	friend istream& operator >>(istream&, department &);

	//函数功能：重载输出运算符
	friend ostream& operator <<(ostream&, department &);
};

class date
{
	int year;    //年
	int month;   //月
	int day;     //日
public:
	//函数功能：构造函数
	date(int, int, int);

	//函数功能：已存在日期直接录入
	void setDate(int, int, int);

	//函数功能：重载输入运算符
	friend istream& operator >>(istream &, date &);

	//函数功能：重载输出运算符
	friend ostream& operator <<(ostream &, date &);

	//函数功能：输出日期数据
	void print()const;

	//函数功能：输入日期数据
	void input();
};

class basicInfo
{
protected:
	int no;        //员工工号
	string name;   //姓名
	string sex;    //性别
	int department;//部门编号
	date birthday; //出生日期
	double salary; //当月工资
	int workPost;  //1-销售员 2-技术员 3-销售经理 4-经理
public:
	//函数功能：构造函数
	basicInfo();

	//函数功能：提取工号
	int getNo()const;

	//函数功能：提取姓名
	string getName()const;

	//函数功能：提取性别
	string getSex()const;

	//函数功能：提取部门编号
	int getDepartment()const;

	//函数功能：提取工作岗位编号
	int getWorkPost()const;

	//函数功能：输出出生日期
	void getDate()const;

	//函数功能：提取出生日期
	date getBirthday()const;

	//函数功能：提取当月工资
	double getSalary()const;

	//函数功能：虚函数，输入数据
	virtual void input();

	//函数功能：设置部门编号
	void inputDepNo(int depNo);

	//函数功能：纯虚函数，输出单个员工信息
	virtual void printSingle() = 0;

	//函数功能：纯虚函数，输出多个员工信息（无表头）
	virtual void printNoHead() = 0;

	//函数功能：纯虚函数，计算工资
	virtual void calSalary() = 0;

	//函数功能：重载输入运算符
	friend istream& operator >>(istream&, basicInfo &);

	//函数功能：重载输出运算符
	friend ostream& operator <<(ostream&, basicInfo &);

	//函数功能：重载相等运算符
	bool operator ==(basicInfo &a)const;

	//函数功能：比较工资多少
	static bool bigger(const basicInfo *a,const basicInfo *b);

	//函数功能：检查员工号是否重复
	bool checkNo(int toCheck)const;

	//函数功能：修改姓名
	bool changeName();

	//函数功能：纯虚函数，修改工作时间
	virtual bool changeWorkTime() = 0;

	//函数功能：纯虚函数，修改销售额
	virtual bool changeSaleAmount() = 0;

	//函数功能：修改性别
	bool changeSex();

	//函数功能：修改出生日期
	bool changeBirthday();

	//函数功能：修改部门编号
	bool changeDep(int depToChange);

	//函数功能：检查姓名是否合法
	bool checkName(string toCheck)const;

	//函数功能：设置已知信息
	bool setBasicInfo(int, string, string, int, date);
};

class manager :public basicInfo
{
public:
	//函数功能：构造函数
	manager();

	//函数功能：输入
	void input();

	//函数功能：输出一个员工数据
	void printSingle();

	//函数功能：输出员工员工数据（无表头）
	void printNoHead();

	//函数功能：计算员工工资
	void calSalary();

	//函数功能：没有用
	bool changeSaleAmount();

	//函数功能：没有用
	bool changeWorkTime();

	//函数功能：重载输入运算符
	friend istream& operator >>(istream&, manager &);

	//函数功能：重载输出运算符
	friend ostream& operator <<(ostream&, manager &);
};


class salesman :public basicInfo
{
	double saleAmount;   //销售额
public:
	//函数功能：构造函数
	salesman();

	//函数功能：提取销售额
	double getSaleAmount();
	
	//函数功能：输入数据
	void input();

	//函数功能：输出一个员工数据
	void printSingle();

	//函数功能：输出一个员工数据（无表头）
	void printNoHead();

	//函数功能：计算工资
	void calSalary();	

	//函数功能：更改销售额
	bool changeSaleAmount();

	//函数功能：没有用
	bool changeWorkTime();

	//函数功能：重载输入运算符
	friend istream& operator >>(istream&, salesman &);

	//函数功能：重载输出运算符
	friend ostream& operator <<(ostream&, salesman &);
};

class salesmanager :public basicInfo
{
public:
	//函数功能：构造函数
	salesmanager();

	//函数功能：输入数据
	void input();

	//函数功能：输出一个员工信息
	void printSingle();

	//函数功能：输出一个员工信息（无表头）
	void printNoHead();

	//函数功能：计算工资
	void calSalary();

	//函数功能：没有用
	bool changeSaleAmount();

	//函数功能：没有用
	bool changeWorkTime();

	//函数功能：重载输入运算符
	friend istream& operator >>(istream&, salesmanager &);

	//函数功能：重载输出运算符
	friend ostream& operator <<(ostream&, salesmanager &);
};

class technician :public basicInfo
{
	int workHour;   //工作时间
public:
	//函数功能：构造函数
	technician();

	//函数功能：提取工作时间
	int getWorkHour();

	//函数功能：输入数据
	void input();

	//函数功能：输出一个员工信息
	void printSingle();

	//函数功能：输出一个员工信息（无表头）
	void printNoHead();

	//函数功能：计算工资
	void calSalary();

	//函数功能：修改工作时间
	bool changeWorkTime();

	//函数功能：没有用
	bool changeSaleAmount();

	//函数功能：重载输入运算符
	friend istream& operator >>(istream&, technician &);

	//函数功能：重载输出运算符
	friend ostream& operator <<(ostream&, technician &);
};

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