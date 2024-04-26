#pragma once
#include "ISensor.h"
#include "TemperatureSensorCelsius.h" 

//������� ��� ������ ������� ����������� � ��������
class AdapterForCelsius : public ISensor
{
private:
	TemperatureSensorCelsius* TempSensorCelsius;
	int Temperature;
public:
	//������������� ���� ��������� � ������������
	AdapterForCelsius(TemperatureSensorCelsius* TSensorCelsius) :TempSensorCelsius(TSensorCelsius) {
		SensorName = "TemperatureSensor";
	}
	//�������� ���� ������ � �����������
	~AdapterForCelsius() {
		delete TempSensorCelsius;
	}

	virtual void GetInformation() override; //��������������� ������ �������� ���������� ��������� � �������������� ����������
	virtual int GiveInformation() override; //��������������� ������ �������� ���������� ��������� � �������������� ����������
	virtual string GiveName() override;		//��������������� ������ �������� ���������� �� ����� �������
};

