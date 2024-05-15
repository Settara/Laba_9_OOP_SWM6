#pragma once
//#define _CRT_SECURE_NO_WARNINGS
//#define __STDC_WANT_LIB_EXT1__ 1
#define __STDC_WANT_LIB_EXT1__ 1
#include <time.h>
#include <iostream>
#include <vector>
#include <string>
#include "AlarmSensor.h"
	

//������� ���������

class Origenator;	//����� ������

class Memento		//����� ��������� ����������� �������
{
public:
	friend class Origenator;				 //������ ���� ���������
	virtual std::string GetName() const = 0; 
	virtual std::string date() const = 0;
	virtual ~Memento() {}
private:
	virtual std::string state() const = 0;
};

class AlarmMemento : public Memento
{
private:
	std::string state_;	//���������
	std::string date_;	//���� ������
public:
	//����� ����������� ������ ������������� ������
	AlarmMemento(std::string state) : state_(state)
	{
		this->state_ = state;
		std::time_t now = std::time(nullptr);
		char str[26];
		this->date_ = ctime_s(str , sizeof str ,&now);

	}
private:
	std::string state() const override //����� ��������� ������������ ��������� �������
	{
		return this->state_;
	}
public:
	std::string GetName() const override //����� ��������� ������� ���
	{
		return this->date_ + " / (" + this->state_.substr(0, 9) + "...)";
	}
	std::string date() const override //����� ��������� ����
	{
		return this->date_;
	}
};

class Origenator	//����� ������
{
private:
	std::string state_; //���������
	std::string GenetateState(bool uslovie) //���������� ���������
	{
		if (uslovie == true)
		{
			return "�������";
		}
		else
		{
			return "�����";
		}
	}
public:
	//� ������������ ���������� ��������� ��� �������������
	Origenator(std::string state) : state_(state)
	{
		std::cout << "\n� Originator: ��� ��������� ���������: " << this->state_ << "\n";
	}
	void DoSomething(bool �ondition)
	{
		std::cout << "Originator: � ����� ������� �� ���-�� �������� \n";
		//��� ������ ���� ������� ��� �������� �� �����
		this->state_ = this->GenetateState(�ondition);
		std::cout << "Originator: ��� ��������� ���������� ��: " << this->state_ << "\n";
	}
	Memento* Save()	//����� ���������� ����� ������ Memento � �� ��������� ������� �� ������ ������ ���� � �������
	{
		return new AlarmMemento(this->state_);
	}
	void Restore(Memento* memento) //����� ��������������� ���������� ��������� Originator �� �� ������� �������� � Memento
	{
		this->state_ = memento->state();
		std::cout << "Originator: ��� ��������� ���������� ��: " << this->state_ << "\n";
	}
};

class Caretaker		//����� ������
{
private:
	std::vector<Memento*> mementos_;	//� ���������� �������� ��������� �� Memento
	Origenator* originator_;			//��������� �� �������
public:
	//� ������������ ��������� ��������� �� ������� � �������������� ����
	Caretaker(Origenator* origenator) : originator_(origenator)
	{
		this->originator_ = origenator;
	}
	void Backup()	//������ � ������ ��������� ������� ��������� ������� Save
	{
		std::cout << "\nCaretaker: ��������� ��������� Origenator... \n ";
		this->mementos_.push_back(this->originator_->Save());
	}
	void Undo()		//��������������� ��������� �� ����������
	{
		//�������� �� ������ ���������
		if (!this->mementos_.size())
		{
			return;
		}
		//� ���� ����� ��������� � ��������������� ���������
		Memento* memento = this->mementos_.back();
		this->mementos_.pop_back();
		std::cout << "Caretaker: ����������� ���������: " << memento->GetName() << "\n";
		try
		{
			this->originator_->Restore(memento);
		}
		catch (...)
		{
			this->Undo();
		}
	}
	//����� ������� ��������� ���������� � ������� ����� �� ���������
	void ShowHistory()  const
	{
		std::cout << "Caretaker: ����� ������ ����������:\n";
		for (Memento* memento : this->mementos_)
		{
			std::cout << memento->GetName() << "\n";
		}
	}
	
};

