#pragma once
#include "IDatabase.h"

//������-����� ����������� ���� ������
class ProxyDatabase : public IDatabase
{
private:
	IDatabase* realDatabase;

public:
	//����������� �� ��������� ����������� ���� realDatabase NULL
	ProxyDatabase()
	{
		this->realDatabase = NULL;
	};
	//����������� ��������� ��������� �� ��������� ������� Database � ����������� ��� �������� ���� realDatabase
	ProxyDatabase(IDatabase* realDatabase)
	{
		this->realDatabase = realDatabase;
	};
	virtual void SetTemperatureMax(int value);					//����� ������������� �������� ���� TemperatureMax
	virtual void SetTemperatureMin(int value);					//����� ������������� �������� ���� TemperatureMin
	virtual void SetHumidityMax(int value);						//����� ������������� �������� ���� HumidityMax
	virtual void SetHumidityMin(int value);						//����� ������������� �������� ���� HumidityMin
	virtual void SetLightingMax(int value);						//����� ������������� �������� ���� LightingMax
	virtual void SetLightingMin(int value);						//����� ������������� �������� ���� LightingMin
	virtual int GetInformation(Characteristic name) override;	//����� �������� ������ ���������� � �������� �������� ��������.
};

