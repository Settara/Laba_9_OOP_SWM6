#include "DecoratorMin.h"

void DecoratorMin::DoWrite()
{
	cout << endl << "Минимально допустимое значение:";
	Decorator::DoWrite();
	cout << " = ";
}