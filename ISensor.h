#pragma once
#include <string>
using std::string;

//��������� ��������
class ISensor
{
protected:
	string SensorName; //��� �������

public:
	ISensor() { this->SensorName = "SensorName"; };				   //����������� ��� ��������� ������������� ��� �������
	ISensor(string SensorName) { this->SensorName = SensorName; }; //����������� ������������� ��� �������
	virtual void GetInformation() = 0;						       //����� �������� ���������� � �������������� ����������
	virtual int GiveInformation() = 0;							   //����� �������� ���������� ���� ������
	virtual string GiveName() = 0;								   //����� �������� ���������� �� ����� ���� ������

};

