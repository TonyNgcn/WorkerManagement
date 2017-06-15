#pragma once
#include"includeAll.h"
#ifndef person_H
#define person_H
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
	static bool bigger(const basicInfo *a, const basicInfo *b);

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
#endif // !person_H