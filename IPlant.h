#pragma once
#include "ISeed.h"

//Интерфейс для высаживаемых растений
class IPlant
{
public:
	virtual void TakePlant(ISeed* seed) = 0;	//Метод отвечает за появление растения
};

