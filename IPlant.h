#pragma once
#include "ISeed.h"

//��������� ��� ������������ ��������
class IPlant
{
public:
	virtual void TakePlant(ISeed* seed) = 0;	//����� �������� �� ��������� ��������
};

