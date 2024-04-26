#pragma once
#include "INutrients.h"

//Паттерн Компоновщик
class Composite : public INutrients
{
private:
	vector<INutrients*> childs;				//Поле отвечает за хранение контейнера указателей на Nutrients
public:
	Composite() { }							//Переопределение конструктора 
	void Mix() override;					//Метод обходит все листья в контейнере и у каждого вызывает метод Mix
	void Add(INutrients* uk);				//Метод добавляет объект в контейнер
	void Remove(INutrients* uk);				//Метод удаляет объект из контейнера
	INutrients* GetChild(int node);			//Метод вовзращает по индексу объект

};

