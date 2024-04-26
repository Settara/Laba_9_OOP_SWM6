#pragma once
#include "IFactory.h"
class TomatoFactory : public IFactory
{
public:
	 ISeed* CreateSeed() override;	//Метод создаем семечко помидора
	 IPlant* CreatePlant() override; //Метод создает растение помидор
};

