#pragma once
#include "IAO.h"

//����� ��� ��������� ������������� �����
class Lamp : public IAO
{
public:
	Lamp() { ObjectName = "Lamp"; }			//��������������� ������������ ������ ��������� ��� Lamp
	virtual void Start() override;			//��������������� ������ ������� ������ �������
	virtual void Finish() override;			//��������������� ������ ���������� ������ �������
	virtual bool GetCondition() override;	//��������������� ������ ��������� ���������� � ��������� �������
	virtual string GiveName() override;		//��������������� ������ �������� ���������� �� ����� �������
};

