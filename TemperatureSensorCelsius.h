#pragma once
#include <string>
using std::string;

//����� ������� ����������� ������� �������� ����������� � ��������
class TemperatureSensorCelsius
{
private:
	int Temperature; //����������� � ��������  
public:
	//���� ���������������� � ������������
	TemperatureSensorCelsius()
	{
		Temperature = 0;
	}
	//��������� ���� 
	int GetTemperature();
};

