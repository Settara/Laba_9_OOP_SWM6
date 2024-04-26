#include "TomatoFactory.h"

ISeed* TomatoFactory::CreateSeed()
{
	return new TomatoSeed();
}

IPlant* TomatoFactory::CreatePlant()
{
	return new TomatoPlant();
}