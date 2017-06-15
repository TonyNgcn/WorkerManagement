#pragma once
#include"includeAll.h"
#ifndef manager_H
#define manager_H
class manager :public basicInfo
{
public:
	//�������ܣ����캯��
	manager();

	//�������ܣ�����
	void input();

	//�������ܣ����һ��Ա������
	void printSingle();

	//�������ܣ����Ա��Ա�����ݣ��ޱ�ͷ��
	void printNoHead();

	//�������ܣ�����Ա������
	void calSalary();

	//�������ܣ�û����
	bool changeSaleAmount();

	//�������ܣ�û����
	bool changeWorkTime();

	//�������ܣ��������������
	friend istream& operator >>(istream&, manager &);

	//�������ܣ�������������
	friend ostream& operator <<(ostream&, manager &);
};

#endif // !manager_H

