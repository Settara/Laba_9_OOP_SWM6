#include "TemperatureSensor.h"

void TemperatureSensor::GetInformation()
{
	Temperature = (int)((rand() / 32767.0) * (50)) + 273; //��������� ��������� ����������� �� 0 �� 50 ��������(�������) � ���������
}

int TemperatureSensor::GiveInformation()
{
	return Temperature;
}

string TemperatureSensor::GiveName()
{
	return SensorName;
}