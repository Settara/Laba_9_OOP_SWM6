#pragma once
#include "INutrients.h"

//����� ��������� ��������� �����
class Humus : public INutrients
{
public:
	Humus() { }	//��������������� ������������ 
	void Mix() override; //����� ��������� ��������� � �����
};

