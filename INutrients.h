#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//������� ��������� ������� �������� �� ���������
class INutrients
{
public:
	INutrients() { };			//����������� ��� ��������� 
	virtual void Mix() = 0;		//����� ��������� ��������� � �����

};

