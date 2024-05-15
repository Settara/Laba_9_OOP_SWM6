#pragma once
#include "ISensor.h"

//Класс реализует охранный датчик
class AlarmSensor : public ISensor
{
private:
	int Alarm; //Переменная хранит информацию был ли нарушен периметр
public:
	AlarmSensor() { SensorName = "AlarmSensor"; }	//Переопределение конструктора датчик принимает имя TemperatureSensor
	virtual void GetInformation() override;						//Переопределение метода сбора информации с измерительного устройства
	virtual int GiveInformation() override;						//Переопределение метода передачи информации собранной с измерительного устройства
	virtual string GiveName() override;							//Переопределение метода передачи информации об имени датчика
};

