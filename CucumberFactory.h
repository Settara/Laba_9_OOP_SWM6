#pragma once
#include "IFactory.h"
class CucumberFactory : public IFactory
{
public:
	ISeed* CreateSeed() override;	//����� ������� ������� ������
	IPlant* CreatePlant() override; //����� ������� �������� ������
};

