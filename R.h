#pragma once
#include <string>
using std::string;

//��������� �����������
class R
{
protected:
	string ReservoirName; //��� ����������
	int Fullness; //������������� ����������

public:
	//����������� �� ��������� ������������� ��� ����������
	R()
	{
		this->ReservoirName = "ReservoirName";
		this->Fullness = 0;
	};
	R(string SensorName) { this->ReservoirName = SensorName; };	   //����������� ������������� ��� ����������
	virtual bool GiveWatering(int quantity) = 0;				   //����� �������� ������ ���������� ��������
	virtual string GiveName() = 0;								   //����� �������� ���������� �� ����� ����������
};

