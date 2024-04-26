#pragma once
#include "IPlant.h"

//Класс растение огурец
class CucumberPlant : public IPlant
{
	void TakePlant(ISeed* seed) override;
};

