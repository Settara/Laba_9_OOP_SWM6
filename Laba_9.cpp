// Laba_9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include "IAO.h"
#include "ProxyDatabase.h"
#include "IGMS.h"
#include "ProxyDatabase.h"
#include "TemperatureSensor.h"
#include "HumiditySensor.h"
#include "LightingSensor.h"
#include "Window.h"
#include "Ventilator.h"
#include "Lamp.h"
#include "FireR.h"
#include "WaterR.h"
#include "AdapterForCelsius.h"
#include "UnitType.h"
#include "Singleton.h"

int main()
{
    setlocale(LC_ALL, "RUS");
    //Создаем систему управления теплицей
    IGMS* managmentSystem = new IGMS(3);
    //Cоздаем динамиическую базу данных ч/з паттерн Singleton
    IDynamicDatabase* dinB = Singleton::getConnection()->selectData();
    //IDynamicDatabase* dinB = new IDynamicDatabase("Динамическая база данных");
    //Устанавливаем какое количество гумуса и торфа будет изначально в нашей динамической базе
    dinB->SetHumusQuantity(2);
    dinB->SetPeatQuantity(2);
    //Cоздаем статическую базу данных
    IDatabase* dB = new IDatabase();
    //Cоздаем прокси для базы данных
    ProxyDatabase* pD = new ProxyDatabase(dB);
    //Создаем массив указателей на датчики
    ISensor* sensors[NSensors];
    //Создаем датчики
    sensors[0] = new TemperatureSensor();
    sensors[1] = new HumiditySensor();
    sensors[2] = new LightingSensor();
    //Создаем массив указателей на прикладные объекты
    IAO* objects[NObjects];
    //Создаем прикладные объекты
    objects[0] = new Window();
    objects[1] = new Ventilator();
    objects[2] = new Lamp();
    //Создаем резервуары
    R* waterReservoir = new WaterR();
    R* fireReservoir = new FireR();
    //Создаем массив указателей на системы полива
    IIS* systems[NSystem];
    //Создаем системы полива которые конфигурируются непосредственно резервуарами
    systems[0] = new IIS(waterReservoir);
    systems[1] = new IIS(fireReservoir);
    //Устанавливаем граничные значения для базы данных
    pD->SetHumidityMax(80);
    pD->SetHumidityMin(70);
    pD->SetLightingMax(1900);
    pD->SetLightingMin(500);
    pD->SetTemperatureMax(307);
    pD->SetTemperatureMin(293);
    //Датчик для температуры в цельсиях и адаптер для него
    sensors[3] = new AdapterForCelsius(new TemperatureSensorCelsius());
    //Создаем массив укзателей на объекты UnitType
    UnitType* types[NTypes];
    //Создаем объекты UnitType для хранения в них сообщений о типах данных
    types[0] = new UnitType("Температура");
    types[1] = new UnitType("Влажность");
    types[2] = new UnitType("Значение освещенности");
    //Создаем массив укзателей на декораторы 
    Decorator* decorators[NDecorators];
    //Создаем декораторы для вывода сообщений о максимальном и минимальном значении характеристики
    decorators[0] = new DecoratorMax(types[0]);
    decorators[1] = new DecoratorMin(types[0]);
    decorators[2] = new DecoratorMax(types[1]);
    decorators[3] = new DecoratorMin(types[1]);
    decorators[4] = new DecoratorMax(types[2]);
    decorators[5] = new DecoratorMin(types[2]);

    //Вызываем главный метод управления теплицей
    managmentSystem->Management(dinB, pD, sensors, objects, systems, decorators);
    cout << endl << "Сделал работу Иван Чепрасов" << endl;
}
