#include "AlarmSensor.h"
#include <ctime>

void AlarmSensor::GetInformation()
{
	//��������� ���������� ����� �� 0 �� 1 
	srand((int)time(0));
	int start = 0;
	int end = 1;
	Alarm = rand() % (end - start + 1) + start;; 
}

int AlarmSensor::GiveInformation()
{
	return Alarm;
}

string AlarmSensor::GiveName()
{
	return SensorName;
}