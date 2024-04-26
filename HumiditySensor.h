#pragma once
#include "ISensor.h"

//����� ������� ���������
class HumiditySensor : public ISensor
{
private:
	int Humidity; //��������� � ��������� 
public:
	HumiditySensor() { SensorName = "HumiditySensor"; } //��������������� ������������ ������ ��������� ��� HumiditySensor
	virtual void GetInformation() override;				//��������������� ������ ����� ���������� � �������������� ����������
	virtual int GiveInformation() override;				//��������������� ������ �������� ���������� ��������� � �������������� ����������
	virtual string GiveName() override;					//��������������� ������ �������� ���������� �� ����� �������
};

