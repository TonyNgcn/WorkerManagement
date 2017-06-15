#pragma once
#include"includeAll.h"

#ifndef salesmanager_H
#define salesmanager_H
class salesmanager :public basicInfo
{
public:
	//�������ܣ����캯��
	salesmanager();

	//�������ܣ���������
	void input();

	//�������ܣ����һ��Ա����Ϣ
	void printSingle();

	//�������ܣ����һ��Ա����Ϣ���ޱ�ͷ��
	void printNoHead();

	//�������ܣ����㹤��
	void calSalary();

	//�������ܣ�û����
	bool changeSaleAmount();

	//�������ܣ�û����
	bool changeWorkTime();

	//�������ܣ��������������
	friend istream& operator >>(istream&, salesmanager &);

	//�������ܣ�������������
	friend ostream& operator <<(ostream&, salesmanager &);
};
#endif // !salesmanager_H

