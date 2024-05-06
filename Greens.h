#pragma once
#include "GreenhousePlants.h"

//����� ������������ ������
class Greens : public GreenhousePlants
{
private:
	//��������� ����������� ����������� � ������� ���������� ���� PlantsName
	Greens(const Greens& donor)
	{
		this->PlantsName = donor.PlantsName;
	};
public:
	Greens() {}
	//� ����������� ������� ��������� PlantsName
	~Greens() 
	{
		delete this->PlantsName;
	}

	void setPlantsName(string* name) override; //����� ��������� ����� 
	string getPlantsName() override;		   //����� �������� ���
	Greens* clone() const;					   //����� ���������� ��������� �� ��������� ������
}; 

