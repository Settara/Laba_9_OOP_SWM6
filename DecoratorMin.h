#pragma once
#include "Decorator.h"
class DecoratorMin : public Decorator
{
public:
	// онструктор инициализирует указатель на IUnit
	DecoratorMin(IUnit* un) : Decorator(un) {}
	//«адача декоратора вывести сообщение "ћинимально допустимое значение"
	void DoWrite() override;
};

