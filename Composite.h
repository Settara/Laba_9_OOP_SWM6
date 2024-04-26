#pragma once
#include "INutrients.h"

//������� �����������
class Composite : public INutrients
{
private:
	vector<INutrients*> childs;				//���� �������� �� �������� ���������� ���������� �� Nutrients
public:
	Composite() { }							//��������������� ������������ 
	void Mix() override;					//����� ������� ��� ������ � ���������� � � ������� �������� ����� Mix
	void Add(INutrients* uk);				//����� ��������� ������ � ���������
	void Remove(INutrients* uk);				//����� ������� ������ �� ����������
	INutrients* GetChild(int node);			//����� ���������� �� ������� ������

};

