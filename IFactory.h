#pragma once
#include "TomatoSeed.h"
#include "CucumberSeed.h"
#include "TomatoPlant.h"
#include "CucumberPlant.h"

//Интерфейс фабрики которая производит семена и растения
class IFactory
{
public:
	virtual ISeed* CreateSeed() = 0;	//Метод создаем семечко
	virtual IPlant * CreatePlant() = 0; //Метод создает растение
};

