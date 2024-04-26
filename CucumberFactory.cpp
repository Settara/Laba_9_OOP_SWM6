#include "CucumberFactory.h"

ISeed* CucumberFactory::CreateSeed()
{
	return new CucumberSeed();
}

IPlant* CucumberFactory::CreatePlant()
{
	return new CucumberPlant();
}