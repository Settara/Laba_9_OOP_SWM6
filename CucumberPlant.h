#pragma once
#include "IPlant.h"

//����� �������� ������
class CucumberPlant : public IPlant
{
	void TakePlant(ISeed* seed) override;
};

