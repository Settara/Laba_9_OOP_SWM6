#pragma once
#include "IUnit.h"

//��������� ������� ������� ��� ������ �� �����
class Decorator : public IUnit
{
private:
	IUnit* Unit;
public:
	//����������� �������������� ��������� �� IUnit
	Decorator(IUnit* un) : Unit(un) {}
	//������ ���������� ��������� ������� DoWrite � ����������� � ���� ���������
	virtual void DoWrite() override;
};

