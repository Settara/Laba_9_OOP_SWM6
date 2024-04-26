#pragma once
#include "Decorator.h"
class DecoratorMax : public Decorator
{
public:
	// онструктор инициализирует указатель на IUnit
	DecoratorMax(IUnit* un) : Decorator(un) {}
	//«адача декоратора вывести сообщение "ћаксимально допустимое значение"
	void DoWrite() override;
};

