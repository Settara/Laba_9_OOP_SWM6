#include "DecoratorMin.h"

void DecoratorMin::DoWrite()
{
	cout << endl << "���������� ���������� ��������:";
	Decorator::DoWrite();
	cout << " = ";
}