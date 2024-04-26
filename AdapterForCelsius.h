#pragma once
#include "ISensor.h"
#include "TemperatureSensorCelsius.h" 

//Адаптер для класса датчика температуры в цельсиях
class AdapterForCelsius : public ISensor
{
private:
	TemperatureSensorCelsius* TempSensorCelsius;
	int Temperature;
public:
	//Инициализацию поля описываем в конструкторе
	AdapterForCelsius(TemperatureSensorCelsius* TSensorCelsius) :TempSensorCelsius(TSensorCelsius) {
		SensorName = "TemperatureSensor";
	}
	//Удаление поля опишем в деструкторе
	~AdapterForCelsius() {
		delete TempSensorCelsius;
	}

	virtual void GetInformation() override; //Переопределение метода передачи информации собранной с измерительного устройства
	virtual int GiveInformation() override; //Переопределение метода передачи информации собранной с измерительного устройства
	virtual string GiveName() override;		//Переопределение метода передачи информации об имени датчика
};

