#pragma once
#include "IAO.h"

//����� ��� ��������
class Window : public IAO
{
public:
	Window() { ObjectName = "Window"; }		//��������������� ������������ ������ ��������� ��� Window
	virtual void Start() override;			//��������������� ������ ������� ������ �������
	virtual void Finish() override;			//��������������� ������ ���������� ������ �������
	virtual bool GetCondition() override;	//��������������� ������ ��������� ���������� � ��������� �������
	virtual string GiveName() override;		//��������������� ������ �������� ���������� �� ����� �������
};
