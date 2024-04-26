#pragma once
#include "R.h"
class FireR : public R
{
private:
	int ShelfLife; //���������� �������� �� ���� �������� ������������� ��������
public:
	//��������������� ������������ ��������� ��������� ��� FireReservoir
	FireR() {
		this->ReservoirName = "FireReservoir";
		this->Fullness = 75;
		this->ShelfLife = 5;
	}
	virtual bool GiveWatering(int quantity) override;	//��������������� ������ ��� �������� ������� ���������� ��������
	virtual string GiveName() override;					//��������������� ������ �������� ���������� �� ����� �������
};

