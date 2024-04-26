#pragma once
#include "Decorator.h"
class DecoratorMax : public Decorator
{
public:
	//����������� �������������� ��������� �� IUnit
	DecoratorMax(IUnit* un) : Decorator(un) {}
	//������ ���������� ������� ��������� "����������� ���������� ��������"
	void DoWrite() override;
};

