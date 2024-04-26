#pragma once
#include <string>
using std::string;

//��������� ��� ����������� �������
class IAO
{
protected:
	string ObjectName;  //���������� �������� ��� ������� 
	bool Condition;		//���������� �������� ���������� �������� �� ������ � ������ ������
public:
	IAO() //����������� ��� ��������� ������������� ��� ������� ��� ���������� � ������������� �������������� ��������� �� ��������
	{
		ObjectName = "ObjectName";
		Condition = false;
	};
	IAO(string ObjectName) //����������� ������������� ��� ������� � ������������� �������������� ��������� �� ��������
	{
		this->ObjectName = ObjectName;
		this->Condition = false;
	};
	virtual void Start() = 0;		//����� ��������� ������ �������
	virtual void  Finish() = 0;		//����� ��������� ������ �������
	virtual bool GetCondition() = 0;//����� ��������� �������� ���������� � ��������� �������
	virtual string GiveName() = 0;	//����� �������� ���������� �� ����� ���� ������

};

