#include "IDynamicDatabase.h"

IDynamicDatabase::IDynamicDatabase(string DinamicDatabaseName)
{
	this->DinamicDatabaseName = DinamicDatabaseName;
}

void IDynamicDatabase::SetTemperatureCurrent(ISensor* sensor)
{
	sensor->GetInformation();
	TemperatureCurrent = sensor->GiveInformation();
}

void IDynamicDatabase::SetHumidityCurrent(ISensor* sensor)
{
	sensor->GetInformation();
	HumidityCurrent = sensor->GiveInformation();
}

void IDynamicDatabase::SetLightingCurrent(ISensor* sensor)
{
	sensor->GetInformation();
	LightingCurrent = sensor->GiveInformation();
}

int IDynamicDatabase::GetTemperatureCurrent()
{
	return TemperatureCurrent;
}

int IDynamicDatabase::GetHumidityCurrent()
{
	return HumidityCurrent;
}

int IDynamicDatabase::GetLightingCurrent()
{
	return LightingCurrent;
}

void IDynamicDatabase::SetHumusQuantity(int quantity)
{
	HumusQuantity = quantity;
}

void IDynamicDatabase::SetPeatQuantity(int quantity)
{
	PeatQuantity = quantity;
}

int IDynamicDatabase::GetHumusQuantity()
{
	return HumusQuantity;
}

int IDynamicDatabase::GetPeatQuantityt()
{
	return PeatQuantity;
}