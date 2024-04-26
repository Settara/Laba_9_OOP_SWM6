#pragma once
#include <iostream>
using namespace std;

//Интерфейс для класса семян
class ISeed
{
public:
	virtual void TakeSeed() = 0;	//Метод отвечает за появление семечка
};

