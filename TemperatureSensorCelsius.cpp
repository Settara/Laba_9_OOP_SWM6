#include "TemperatureSensorCelsius.h"

int TemperatureSensorCelsius::GetTemperature()
{
	Temperature = (int)((rand() / 32767.0) * (50)); //Генерация случайной температуры от 0 до 50 градусов Цельсия
	return Temperature;
}

