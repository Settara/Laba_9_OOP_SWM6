#include "TemperatureSensorCelsius.h"

int TemperatureSensorCelsius::GetTemperature()
{
	Temperature = (int)((rand() / 32767.0) * (50)); //��������� ��������� ����������� �� 0 �� 50 �������� �������
	return Temperature;
}

