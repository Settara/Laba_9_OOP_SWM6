#pragma once
#include "IPlant.h"

//Класс растение помидор
class TomatoPlant : public IPlant
{
	void TakePlant(ISeed* seed) override;
};

