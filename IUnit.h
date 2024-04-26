#pragma once
#include <iostream>
#include <string>
using namespace std;

//Базовый интерфейсный класс для декоратора, его наследники отвечают за прорисовку на экране
class IUnit
{
public:
	//шаблон для метода который будет что-то выводить на консоли
	virtual void DoWrite() = 0;
	virtual ~IUnit() {};
};

