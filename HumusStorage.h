#pragma once
#include "INutrientsStorage.h"
#include "Humus.h"

//����� ��������� FactoryMethod ��� ������
class HumusStorage : public INutrientsStorage
{
public:
	INutrients* create() override;
};

