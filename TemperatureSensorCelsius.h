#pragma once
#include <string>
using std::string;

//Класс датчика температуры который измеряет температуру в цельсиях
class TemperatureSensorCelsius
{
private:
	int Temperature; //Температура в Цельсиях  
public:
	//Поле инициализируется в конструкторе
	TemperatureSensorCelsius()
	{
		Temperature = 0;
	}
	//Возращаем поле 
	int GetTemperature();
};

