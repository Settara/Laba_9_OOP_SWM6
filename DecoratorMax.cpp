#include "DecoratorMax.h"

void DecoratorMax::DoWrite()
{
	cout << endl << "Максимально допустимое значение:";
	Decorator::DoWrite();
	cout << " = ";
}