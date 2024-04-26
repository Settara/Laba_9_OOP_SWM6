#include "HumiditySensor.h"

void HumiditySensor::GetInformation()
{
	Humidity = (int)((rand() / 32767.0) * (100)); //��������� ��������� ��������� �� 0 �� 100 ��������� 
}

int HumiditySensor::GiveInformation()
{
	return Humidity;
}

string HumiditySensor::GiveName()
{
	return SensorName;
}