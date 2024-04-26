#pragma once
#include "TomatoSeed.h"
#include "CucumberSeed.h"
#include "TomatoPlant.h"
#include "CucumberPlant.h"

//��������� ������� ������� ���������� ������ � ��������
class IFactory
{
public:
	virtual ISeed* CreateSeed() = 0;	//����� ������� �������
	virtual IPlant * CreatePlant() = 0; //����� ������� ��������
};

