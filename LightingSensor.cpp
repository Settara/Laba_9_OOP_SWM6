#include "LightingSensor.h"

void LightingSensor::GetInformation()
{
	Lighting = (int)((rand() / 32767.0) * (2000)); //��������� ��������� ������������ �� 0 �� 2000 ������ 
}

int LightingSensor::GiveInformation()
{
	return Lighting;
}

string LightingSensor::GiveName()
{
	return SensorName;
}