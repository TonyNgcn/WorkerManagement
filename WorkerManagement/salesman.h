#pragma once
#include"includeAll.h"
#ifndef salesman_H
#define salesman_H
class salesman :public basicInfo
{
	class salesman :public basicInfo
	{
		double saleAmount;   //���۶�
	public:
		//�������ܣ����캯��
		salesman();

		//�������ܣ���ȡ���۶�
		double getSaleAmount();

		//�������ܣ���������
		void input();

		//�������ܣ����һ��Ա������
		void printSingle();

		//�������ܣ����һ��Ա�����ݣ��ޱ�ͷ��
		void printNoHead();

		//�������ܣ����㹤��
		void calSalary();

		//�������ܣ��������۶�
		bool changeSaleAmount();

		//�������ܣ�û����
		bool changeWorkTime();

		//�������ܣ��������������
		friend istream& operator >>(istream&, salesman &);

		//�������ܣ�������������
		friend ostream& operator <<(ostream&, salesman &);
	};
#endif