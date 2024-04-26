#pragma once
#include "IFactory.h"
class TomatoFactory : public IFactory
{
public:
	 ISeed* CreateSeed() override;	//����� ������� ������� ��������
	 IPlant* CreatePlant() override; //����� ������� �������� �������
};

