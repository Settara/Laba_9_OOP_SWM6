#include "HumusStorage.h"

INutrients* HumusStorage::create()
{
	return new Humus();
}
