#pragma once
#include "IUnit.h"

//����� �������� �� ����� � ������� ���� ������
class UnitType : public IUnit
{
private:
	string Message;
public:
	//������������ ���������� ��� ������ ��� ����������� ������
	UnitType(string mes)
	{
		Message = mes;
	};
	//��������������� ������ ������ �� �����
	void DoWrite() override;
};

