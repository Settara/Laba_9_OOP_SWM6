#pragma once
#include "INutrientsStorage.h"
#include "Peat.h"

//Класс реализует FactoryMethod для торфа
class PeatStorage : public INutrientsStorage
{
public:
	INutrients* create() override;
};

