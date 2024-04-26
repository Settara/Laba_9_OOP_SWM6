#pragma once
#include <string>
#include "Characteristic.h"
using std::string;

//����� ����������� ���� ������
class IDatabase
{
private:
	string DatabaseName;	 //���� ������ ��� ���� ������
	int TemperatureMax;		 //���� ������ ������������ �������� �����������
	int TemperatureMin;		 //���� ������ �����������  �������� ����������� 
	int HumidityMax;		 //���� ������ ������������ �������� ��������� 
	int HumidityMin;		 //���� ������ �����������  �������� ��������� 
	int LightingMax;		 //���� ������ ������������ �������� ��������� 
	int LightingMin;		 //���� ������ �����������  �������� ��������� 

public:
	IDatabase();										    //���������� �� ��������� ������������� ��� ���� ������
	IDatabase(string DatabaseName);						    //���������� ������������� ��� ���� ������
	void SetTemperatureMax(int value);						//����� ������������� �������� ���� TemperatureMax
	void SetTemperatureMin(int value);						//����� ������������� �������� ���� TemperatureMin
	void SetHumidityMax(int value);							//����� ������������� �������� ���� HumidityMax
	void SetHumidityMin(int value);							//����� ������������� �������� ���� HumidityMin
	void SetLightingMax(int value);							//����� ������������� �������� ���� LightingMax
	void SetLightingMin(int value);							//����� ������������� �������� ���� LightingMin
	virtual int GetInformation(Characteristic name);		//����� �������� ������ ���������� � �������� �������� ��������.

};

