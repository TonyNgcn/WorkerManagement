#pragma once
#include"includeAll.h"
#ifndef department_H
#define department_H
class department
{
	string depName;   //��������
	int depNo;        //���ű��
	int count;        //��������
public:
	//�������ܣ���ȡ��������
	string getDepName()const;

	//�������ܣ���ȡ���ű��
	int getDepNo()const;

	//�������ܣ�����������ơ����
	void printAllDep()const;

	//�������ܣ�����ò������ơ���š�����
	void getDepInfo()const;

	//�������ܣ����벿�ű�š�����
	void input();

	//�������ܣ�����������һ
	bool addCount();

	//�������ܣ���ȡ��������
	int getCount()const;

	//�������ܣ����캯��
	department();

	//�������ܣ��޸Ĳ�������
	bool changeDepName();

	//�������ܣ�����������һ
	bool reduceCount();

	//�������ܣ���鲿�������Ƿ��ظ�
	bool checkDepName(string toCheck);

	//�������ܣ���鲿�ű���Ƿ��ظ�
	bool checkDepNo(int toCheck);

	//�������ܣ�����ò���ƽ������
	double calAverageSalary();

	//�������ܣ��������������
	friend istream& operator >>(istream&, department &);

	//�������ܣ�������������
	friend ostream& operator <<(ostream&, department &);
};
#endif // !department_H

