#pragma once
#include "R.h"

//����� ������� ������ 
class IIS
{
private:
	R* Reservoir;	  //���� ������ ��������� �� ���������
	string SystemType;//���� ������ ��� �������
public:
	//������� ������ ��������������� ���������� �������� ���������� � ���������� ��� ���������� ������
	IIS(R* Reservoir)
	{
		this->Reservoir = Reservoir;
		this->SystemType = Reservoir->GiveName();
	}
	bool StartWatering(int quantity);
	string GiveSystemType();
};

