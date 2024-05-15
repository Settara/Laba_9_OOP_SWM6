#pragma once
#include "ISensor.h"

//����� ��������� �������� ������
class AlarmSensor : public ISensor
{
private:
	int Alarm; //���������� ������ ���������� ��� �� ������� ��������
public:
	AlarmSensor() { SensorName = "AlarmSensor"; }	//��������������� ������������ ������ ��������� ��� TemperatureSensor
	virtual void GetInformation() override;						//��������������� ������ ����� ���������� � �������������� ����������
	virtual int GiveInformation() override;						//��������������� ������ �������� ���������� ��������� � �������������� ����������
	virtual string GiveName() override;							//��������������� ������ �������� ���������� �� ����� �������
};

