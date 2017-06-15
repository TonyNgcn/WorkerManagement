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
#endif
