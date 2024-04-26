#pragma once
#include "ISensor.h"

//����� ������� �����
class LightingSensor : public ISensor
{
private:
	int Lighting; //������������ � ������ 
public:
	LightingSensor() { SensorName = "LightingSensor"; } //��������������� ������������ ������ ��������� ��� LightingSensor
	virtual void GetInformation() override;				//��������������� ������ ����� ���������� � �������������� ����������
	virtual int GiveInformation() override;				//��������������� ������ �������� ���������� ��������� � �������������� ����������
	virtual string GiveName() override;					//��������������� ������ �������� ���������� �� ����� �������
};

