#include "CucumberPlant.h"

void CucumberPlant::TakePlant(ISeed* seed)
{
	seed->TakeSeed();
	cout << "�������� ������" << endl;
}