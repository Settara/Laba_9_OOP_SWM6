#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Базовый интерфейс который отвечает за удобрения
class INutrients
{
public:
	INutrients() { };			//Конструктор без параметра 
	virtual void Mix() = 0;		//Метод добавляет удобрение в почву

};

