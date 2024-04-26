#pragma once
#include "INutrients.h"

//Класс реализует удобрение гумус
class Humus : public INutrients
{
public:
	Humus() { }	//Переопределение конструктора 
	void Mix() override; //Метод добавляет удобрение в почву
};

