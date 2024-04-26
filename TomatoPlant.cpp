#include "TomatoPlant.h"

void TomatoPlant::TakePlant(ISeed* seed)
{
	seed->TakeSeed();
	cout << "Посадили помидор" << endl;
}