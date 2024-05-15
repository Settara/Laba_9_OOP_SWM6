#pragma once
//#define _CRT_SECURE_NO_WARNINGS
//#define __STDC_WANT_LIB_EXT1__ 1
#define __STDC_WANT_LIB_EXT1__ 1
#include <time.h>
#include <iostream>
#include <vector>
#include <string>
#include "AlarmSensor.h"
	

//Паттерн хранитель

class Origenator;	//Класс хозяин

class Memento		//Класс хранитель абстрактный базовый
{
public:
	friend class Origenator;				 //Хозяин друг хранителя
	virtual std::string GetName() const = 0; 
	virtual std::string date() const = 0;
	virtual ~Memento() {}
private:
	virtual std::string state() const = 0;
};

class AlarmMemento : public Memento
{
private:
	std::string state_;	//Состояние
	std::string date_;	//Дата снимка
public:
	//Через конструктор хозяин конфигурирует снимок
	AlarmMemento(std::string state) : state_(state)
	{
		this->state_ = state;
		std::time_t now = std::time(nullptr);
		char str[26];
		this->date_ = ctime_s(str , sizeof str ,&now);

	}
private:
	std::string state() const override //Метод позволяет восстановить состояние хозяину
	{
		return this->state_;
	}
public:
	std::string GetName() const override //Метод позволяет вернуть имя
	{
		return this->date_ + " / (" + this->state_.substr(0, 9) + "...)";
	}
	std::string date() const override //Метод позволяет дату
	{
		return this->date_;
	}
};

class Origenator	//Класс хозяин
{
private:
	std::string state_; //Состояние
	std::string GenetateState(bool uslovie) //Генерируем состояние
	{
		if (uslovie == true)
		{
			return "ТРЕВОГО";
		}
		else
		{
			return "НОРМА";
		}
	}
public:
	//В конструкторе передается состояние при инициализации
	Origenator(std::string state) : state_(state)
	{
		std::cout << "\nЯ Originator: Мое начальное состояние: " << this->state_ << "\n";
	}
	void DoSomething(bool сondition)
	{
		std::cout << "Originator: Я узнаю нарушил ли кто-то периметр \n";
		//Тут должно быть условие для проверки на пожар
		this->state_ = this->GenetateState(сondition);
		std::cout << "Originator: мое состояние изменилось на: " << this->state_ << "\n";
	}
	Memento* Save()	//Метод возвращает новый объект Memento и то состояние которое на момент вызова было у хозяина
	{
		return new AlarmMemento(this->state_);
	}
	void Restore(Memento* memento) //Метод восстановливает внутреннее состояние Originator на то которое передано в Memento
	{
		this->state_ = memento->state();
		std::cout << "Originator: Мое состояние изменилось на: " << this->state_ << "\n";
	}
};

class Caretaker		//Класс опекун
{
private:
	std::vector<Memento*> mementos_;	//В контейнере хранятся указатели на Memento
	Origenator* originator_;			//Указатель на хозяина
public:
	//В конструкторе принимает указатель на хозяина и инициализирует поле
	Caretaker(Origenator* origenator) : originator_(origenator)
	{
		this->originator_ = origenator;
	}
	void Backup()	//Кладем в вектор хранителя который создается методом Save
	{
		std::cout << "\nCaretaker: сохраняем состояние Origenator... \n ";
		this->mementos_.push_back(this->originator_->Save());
	}
	void Undo()		//Восстанавливает хранителя из контейнера
	{
		//Проверка на пустой контейнер
		if (!this->mementos_.size())
		{
			return;
		}
		//С краю берет хранителя и восстанавливает состояние
		Memento* memento = this->mementos_.back();
		this->mementos_.pop_back();
		std::cout << "Caretaker: восстановил состояние: " << memento->GetName() << "\n";
		try
		{
			this->originator_->Restore(memento);
		}
		catch (...)
		{
			this->Undo();
		}
	}
	//Метод обходит контейнер хранителей и выводит имена их состояний
	void ShowHistory()  const
	{
		std::cout << "Caretaker: Здесь список хранителей:\n";
		for (Memento* memento : this->mementos_)
		{
			std::cout << memento->GetName() << "\n";
		}
	}
	
};

