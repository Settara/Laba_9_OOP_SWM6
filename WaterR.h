#pragma once
#include "R.h"
class WaterR : public R
{
private:

public:
	//��������������� ������������ ��������� ��������� ��� WaterReservoir
	WaterR() {
		this->ReservoirName = "WaterReservoir";
		this->Fullness = 100;
	}
	virtual bool GiveWatering(int quantity) override;	//��������������� ������ ��� �������� ������� ���������� ��������
	virtual string GiveName() override;					//��������������� ������ �������� ���������� �� ����� �������
};

