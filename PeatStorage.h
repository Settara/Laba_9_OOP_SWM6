#pragma once
#include "INutrientsStorage.h"
#include "Peat.h"

//����� ��������� FactoryMethod ��� �����
class PeatStorage : public INutrientsStorage
{
public:
	INutrients* create() override;
};

