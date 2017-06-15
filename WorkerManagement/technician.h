#pragma once
#include"includeAll.h"
#ifndef technician_H
#define technician_H
class technician :public basicInfo
{
	int workHour;   //����ʱ��
public:
	//�������ܣ����캯��
	technician();

	//�������ܣ���ȡ����ʱ��
	int getWorkHour();

	//�������ܣ���������
	void input();

	//�������ܣ����һ��Ա����Ϣ
	void printSingle();

	//�������ܣ����һ��Ա����Ϣ���ޱ�ͷ��
	void printNoHead();

	//�������ܣ����㹤��
	void calSalary();

	//�������ܣ��޸Ĺ���ʱ��
	bool changeWorkTime();

	//�������ܣ�û����
	bool changeSaleAmount();

	//�������ܣ��������������
	friend istream& operator >>(istream&, technician &);

	//�������ܣ�������������
	friend ostream& operator <<(ostream&, technician &);
};
#endif