#include "DecoratorMax.h"

void DecoratorMax::DoWrite()
{
	cout << endl << "����������� ���������� ��������:";
	Decorator::DoWrite();
	cout << " = ";
}