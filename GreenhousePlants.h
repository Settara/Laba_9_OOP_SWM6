#pragma once
#include <string>
using std::string;

//����� ������������ ��������� ��������
class GreenhousePlants
{
protected:
	string* PlantsName;
public:
	virtual void setPlantsName(string* name) = 0;
	virtual string getPlantsName() = 0;
	virtual GreenhousePlants* clone() const = 0;
};

