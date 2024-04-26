#pragma once
#include "Decorator.h"
class DecoratorMin : public Decorator
{
public:
	//����������� �������������� ��������� �� IUnit
	DecoratorMin(IUnit* un) : Decorator(un) {}
	//������ ���������� ������� ��������� "���������� ���������� ��������"
	void DoWrite() override;
};

