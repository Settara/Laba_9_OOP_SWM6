#pragma once
#include "INutrients.h"

//����� ��������� ��������� ����
class Peat : public INutrients
{
public:
	Peat() { }	//��������������� ������������ 
	void Mix() override; //����� ��������� ��������� � �����
};

