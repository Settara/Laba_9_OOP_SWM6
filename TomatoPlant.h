#pragma once
#include "IPlant.h"

//����� �������� �������
class TomatoPlant : public IPlant
{
	void TakePlant(ISeed* seed) override;
};

