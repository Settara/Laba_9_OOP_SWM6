#pragma once
#include "INutrients.h"

//Класс реализует удобрение торф
class Peat : public INutrients
{
public:
	Peat() { }	//Переопределение конструктора 
	void Mix() override; //Метод добавляет удобрение в почву
};

