#pragma once
#include "IUnit.h"

//Декоратор который выводит тип данных на экран
class Decorator : public IUnit
{
private:
	IUnit* Unit;
public:
	//Конструктор инициализирует указатель на IUnit
	Decorator(IUnit* un) : Unit(un) {}
	//Задача декоратора запустить функцию DoWrite у хранящегося у него указателя
	virtual void DoWrite() override;
};

