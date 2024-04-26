#pragma once

#include <chrono>
#include <thread>
#include "IDynamicDatabase.h"
#include "ProxyDatabase.h"
#include "IAO.h"
#include "IIS.h"
#include "DecoratorMin.h"
#include "DecoratorMax.h"
#include "Composite.h"
#include "Iterator.h"
#include "HumusStorage.h"
#include "PeatStorage.h"
#include "TomatoFactory.h"
#include "CucumberFactory.h"

using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

//Класс управления теплицей
class IGMS
{
private:
	int CurrentValue; //Поле содержит текущее значение параметра
	int Counter;	  //Поле содержит счетчик сколько интераций проработает теплица
	bool Working;	  //Поле содержит информацию работает ли система или нет
public:
	IGMS()
	{
		Working = true;
	}
	IGMS(int count)
	{
		Working = true;
		Counter = count;
	}
	//Метод отвечает за логику работы теплицы
	void Management(IDynamicDatabase* DinBase, ProxyDatabase* Database, ISensor* Sensors[NSensors], IAO* Objects[NObjects], IIS* Systems[NSystem], Decorator* Decorators[NDecorators]);
};

