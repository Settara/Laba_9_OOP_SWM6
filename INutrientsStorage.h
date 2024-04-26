#pragma once
#include "INutrients.h"

//Интерфейс для FactoryMethod который будет создавать удобрения
class INutrientsStorage
{
public:
	virtual INutrients* create() = 0;
};

