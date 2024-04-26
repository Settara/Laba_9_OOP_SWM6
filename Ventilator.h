#pragma once
#include "IAO.h"

//����� ��� �����������
class Ventilator : public IAO
{
public:
	Ventilator() { ObjectName = "Ventilator"; }			//��������������� ������������ ������ ��������� ��� Ventilator
	virtual void Start() override;						//��������������� ������ ������� ������ �������
	virtual void Finish() override;						//��������������� ������ ���������� ������ �������
	virtual bool GetCondition() override;				//��������������� ������ ��������� ���������� � ��������� �������
	virtual string GiveName() override;					//��������������� ������ �������� ���������� �� ����� �������
};

