#pragma once
#include "Characteristic.h"
#include "ISensor.h"

//Класс динамической базы данных
class IDynamicDatabase
{
private:
	string DinamicDatabaseName;	 //Поле хранит имя базы данных
	int TemperatureCurrent;		 //Поле хранит текущее значение температуры
	int HumidityCurrent;		 //Поле хранит текущее значение влажности 
	int LightingCurrent;		 //Поле хранит текущее значение освещения
	int HumusQuantity;			 //Поле хранит имеющиеся количество гумуса
	int PeatQuantity;			 //Поле хранит имеющиеся количество торфа

public:
	IDynamicDatabase(string DynamicDatabaseName);//Констуктор устанавливает имя базы данных
	void SetTemperatureCurrent(ISensor* sensor); //Метод опрашивает датчик и устанавливает значения поля TemperatureCurrent
	void SetHumidityCurrent(ISensor* sensor);	 //Метод опрашивает датчик и устанавливает значения поля HumidityCurrent
	void SetLightingCurrent(ISensor* sensor);	 //Метод опрашивает датчик и устанавливает значения поля LightingCurrent
	int GetTemperatureCurrent();				 //Метод возвращает значения поля TemperatureCurrent
	int GetHumidityCurrent();					 //Метод возвращает значения поля HumidityCurrent
	int GetLightingCurrent();					 //Метод возвращает значения поля LightingCurrent

	void SetHumusQuantity(int quantity);		 //Метод устанавливает значения поля HumusQuantity
	void SetPeatQuantity(int quantity);			 //Метод устанавливает значения поля PeatQuantity
	int GetHumusQuantity();						 //Метод возвращает значения поля HumusQuantity
	int GetPeatQuantityt();						 //Метод возвращает значения поля PeatQuantity
};