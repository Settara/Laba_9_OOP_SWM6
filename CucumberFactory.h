#pragma once
#include "IFactory.h"
class CucumberFactory : public IFactory
{
public:
	ISeed* CreateSeed() override;	//Метод создаем семечко огурца
	IPlant* CreatePlant() override; //Метод создает растение огурец
};

