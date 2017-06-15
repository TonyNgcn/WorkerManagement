#pragma once
#include"includeAll.h"
#ifndef person_H
#define person_H
class date
{
	int year;    //��
	int month;   //��
	int day;     //��
public:
	//�������ܣ����캯��
	date(int, int, int);

	//�������ܣ��Ѵ�������ֱ��¼��
	void setDate(int, int, int);

	//�������ܣ��������������
	friend istream& operator >>(istream &, date &);

	//�������ܣ�������������
	friend ostream& operator <<(ostream &, date &);

	//�������ܣ������������
	void print()const;

	//�������ܣ�������������
	void input();
};

class basicInfo
{
protected:
	int no;        //Ա������
	string name;   //����
	string sex;    //�Ա�
	int department;//���ű��
	date birthday; //��������
	double salary; //���¹���
	int workPost;  //1-����Ա 2-����Ա 3-���۾��� 4-����
public:
	//�������ܣ����캯��
	basicInfo();

	//�������ܣ���ȡ����
	int getNo()const;

	//�������ܣ���ȡ����
	string getName()const;

	//�������ܣ���ȡ�Ա�
	string getSex()const;

	//�������ܣ���ȡ���ű��
	int getDepartment()const;

	//�������ܣ���ȡ������λ���
	int getWorkPost()const;

	//�������ܣ������������
	void getDate()const;

	//�������ܣ���ȡ��������
	date getBirthday()const;

	//�������ܣ���ȡ���¹���
	double getSalary()const;

	//�������ܣ��麯������������
	virtual void input();

	//�������ܣ����ò��ű��
	void inputDepNo(int depNo);

	//�������ܣ����麯�����������Ա����Ϣ
	virtual void printSingle() = 0;

	//�������ܣ����麯����������Ա����Ϣ���ޱ�ͷ��
	virtual void printNoHead() = 0;

	//�������ܣ����麯�������㹤��
	virtual void calSalary() = 0;

	//�������ܣ��������������
	friend istream& operator >>(istream&, basicInfo &);

	//�������ܣ�������������
	friend ostream& operator <<(ostream&, basicInfo &);

	//�������ܣ�������������
	bool operator ==(basicInfo &a)const;

	//�������ܣ��ȽϹ��ʶ���
	static bool bigger(const basicInfo *a, const basicInfo *b);

	//�������ܣ����Ա�����Ƿ��ظ�
	bool checkNo(int toCheck)const;

	//�������ܣ��޸�����
	bool changeName();

	//�������ܣ����麯�����޸Ĺ���ʱ��
	virtual bool changeWorkTime() = 0;

	//�������ܣ����麯�����޸����۶�
	virtual bool changeSaleAmount() = 0;

	//�������ܣ��޸��Ա�
	bool changeSex();

	//�������ܣ��޸ĳ�������
	bool changeBirthday();

	//�������ܣ��޸Ĳ��ű��
	bool changeDep(int depToChange);

	//�������ܣ���������Ƿ�Ϸ�
	bool checkName(string toCheck)const;

	//�������ܣ�������֪��Ϣ
	bool setBasicInfo(int, string, string, int, date);
};
#endif // !person_H