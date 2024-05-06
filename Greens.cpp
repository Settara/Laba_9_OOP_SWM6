#include "Greens.h"

void Greens::setPlantsName(string* name)  
{
	this->PlantsName = name;
}

string Greens::getPlantsName()
{
	return *(this->PlantsName);
}

Greens* Greens::clone() const
{
	return new Greens(*this);
}