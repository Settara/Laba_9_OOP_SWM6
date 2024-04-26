#pragma once
#include "ISensor.h"

//����� ������� �����������
class TemperatureSensor : public ISensor
{
private:
	int Temperature; //����������� � ���������
public:
	TemperatureSensor() { SensorName = "TemperatureSensor"; }	//��������������� ������������ ������ ��������� ��� TemperatureSensor
	virtual void GetInformation() override;						//��������������� ������ ����� ���������� � �������������� ����������
	virtual int GiveInformation() override;						//��������������� ������ �������� ���������� ��������� � �������������� ����������
	virtual string GiveName() override;							//��������������� ������ �������� ���������� �� ����� �������
};

