#pragma once
#include "GreenhousePlants.h"

//Класс представляет зелень
class Greens : public GreenhousePlants
{
private:
	//Приватный конструктор копирования в котором копируется поле PlantsName
	Greens(const Greens& donor)
	{
		this->PlantsName = donor.PlantsName;
	};
public:
	Greens() {}
	//В деструкторе удаляем указатель PlantsName
	~Greens() 
	{
		delete this->PlantsName;
	}

	void setPlantsName(string* name) override; //Метод установки имени 
	string getPlantsName() override;		   //Метод получает имя
	Greens* clone() const;					   //Метод возвращает указатель на экземпляр зелени
}; 

