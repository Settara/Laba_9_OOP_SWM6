#pragma once
#include <iostream>
#include <string>
using namespace std;

//������� ������������ ����� ��� ����������, ��� ���������� �������� �� ���������� �� ������
class IUnit
{
public:
	//������ ��� ������ ������� ����� ���-�� �������� �� �������
	virtual void DoWrite() = 0;
	virtual ~IUnit() {};
};

