#include "AdapterForCelsius.h"

void AdapterForCelsius::GetInformation()
{
	Temperature = TempSensorCelsius->GetTemperature();
	Temperature = Temperature + 273;
}

int AdapterForCelsius::GiveInformation()
{
	return Temperature;
}

string AdapterForCelsius::GiveName()
{
	return SensorName;
}