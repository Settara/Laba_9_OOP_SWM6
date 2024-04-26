#pragma once
#include "INutrientsStorage.h"
#include "Humus.h"

//Класс реализует FactoryMethod для гумуса
class HumusStorage : public INutrientsStorage
{
public:
	INutrients* create() override;
};

