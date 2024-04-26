#pragma once
#include "IUnit.h"

//Класс отвечает за вывод в консоль типа данных
class UnitType : public IUnit
{
private:
	string Message;
public:
	//Коснутруктор запоминает тип данных для дальнейшего вывода
	UnitType(string mes)
	{
		Message = mes;
	};
	//Переопределение метода вывода на экран
	void DoWrite() override;
};

