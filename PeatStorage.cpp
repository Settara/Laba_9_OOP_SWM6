#include "PeatStorage.h"

INutrients* PeatStorage::create()
{
	return new Peat();
}
