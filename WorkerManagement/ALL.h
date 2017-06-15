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
	static bool bigger(const basicInfo *a,const basicInfo *b);

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

class interFace
{
public:
	//���Ŷ�����ʱ����
	department tempDep;

	//Ա������ָ����ʱ����
	basicInfo *tempPerson;
	
	//����Ա������ָ����ʱ����
	vector<basicInfo*> temp_v;

	//���沿�ŵ�����
	vector<department> department_v;

	//���澭�������
	vector<manager> manager_v;

	//��������Ա������
	vector<salesman> salesman_v;

	//�������۾��������
	vector<salesmanager> salesmanager_v;

	//���漼��Ա������
	vector<technician> technician_v;

	//�������ܣ����˵�
	void mainMenu();

	//�������ܣ��������ӵĲ˵�
	void addMenu();

	//�������ܣ������޸ĵĲ˵�
	void changeMenu();

	//�������ܣ����ڲ鿴�Ĳ˵�
	void checkMenu();

	//�������ܣ�����ɾ���Ĳ˵�
	void deleteMenu();

	//�������ܣ����ڷ����Ĳ˵�
	void analysisMenu();

	//�������ܣ��޸Ĳ�������
	void changeDepName();

	//�������ܣ��޸�Ա����Ϣ
	void changePersonInfo();

	//�������ܣ�����ȫ������
	void calAllSalary();

	//�������ܣ�����ȫ��ƽ������
	double calAverageSalary();

	//�������ܣ�ɾ������
	bool deleteDep(department);

	//�������ܣ�������в���
	void getAllDep()const;

	//�������ܣ�����ƶ����ŵ�����
	void getDepName(int)const;

	//�������ܣ����Ӳ���
	void addDep();

	//�������ܣ�����Ա��
	void addPerson();

	//�������ܣ�����ָ�����ŵ�Ա������
	void addCountOfDep(int depNo);

	//�������ܣ��жϸò����Ƿ����
	bool checkDepExist(int checkDepID)const;

	//�������ܣ��жϸò����Ƿ�������۾���
	bool checkSalesManager(int checkDepID)const;

	//�������ܣ����ݲ��ű�Ų��Ҳ���
	bool searchDep(int checkDepID);

	//�������ܣ����ݲ������Ʋ��Ҳ���
	bool searchDep(string checkDepName);
	
	//�������ܣ�����ҵ����ŵ���Ϣ
	void checkByDep();

	//�������ܣ������ֲ�ͬ��λ��Ա������һ������ָ�������
	void tempAll();

	//�������ܣ��Ի���ָ���������������
	void sortAll();

	//�������ܣ�������������Ա��
	bool searchByName(string checkName);

	//�������ܣ����ݹ��Ų���Ա��
	bool searchByNo(int checkNo);

	//�������ܣ����Ĺ�����λ
	void changeWorkPost();

	//�������ܣ����ٸò��ŵ�����
	void reduceDepCount(int depNo);

	//�������ܣ�ɾ��Ա��
	bool deletePerson();

	//�������ܣ������ݴ����������ļ�
	bool vectorToFile();

	//�������ܣ������ݴ��ļ���������
	bool fileToVector();

	//�������ܣ���ҳ��ʾԱ����Ϣ
	void printByPages();

	//�������ܣ���������Աƽ������
	double calSalesmanAverageSalary();

	//�������ܣ��������۾���ƽ������
	double calSalesmanagerAverageSalary();

	//�������ܣ����㼼��Աƽ������
	double calTechnicianAverageSalary();
};