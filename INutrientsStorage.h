#pragma once
#include "INutrients.h"

//��������� ��� FactoryMethod ������� ����� ��������� ���������
class INutrientsStorage
{
public:
	virtual INutrients* create() = 0;
};

