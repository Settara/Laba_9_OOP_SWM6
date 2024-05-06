#pragma once
#include <iostream>
#include "IDynamicDatabase.h"
using namespace std;

//Класс реализует паттерн Singleton
class Singleton
{
private:
    static Singleton* instance;	//Поле хранит указатель на экземпляр объекта
    IDynamicDatabase* data; //Поле хранит данные(указатель на динамическую базу данных)
    Singleton() //Конструктор должен быть приватным чтобы объект нельзя было создать обычным способом
    {
        cout << "Подключение к динамической базе данных" << endl;
        data = new IDynamicDatabase("Динамическая база данных");
    }
public:
    //Удаляем конструктор копирования и оператор присваивания
    Singleton(const Singleton&) = delete;
    void operator = (const Singleton&) = delete;
    //Создаем статический метод через который будем получать ссылку на экземпляр
    static Singleton* getConnection() {
        //Если поле равно nullptr то инициализируем его
        if (instance == nullptr)
        {
            instance = new Singleton();
        }
        return instance;
    }
    //Метод возвращает значение поля data
    IDynamicDatabase* selectData() const {
        return data;
    }
};

