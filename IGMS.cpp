#include "IGMS.h"

void IGMS::Management(IDynamicDatabase* DinBase, ProxyDatabase* Database, ISensor* Sensors[NSensors], IAO* Objects[NObjects], IIS* Systems[NSystem], Decorator* Decorators[NDecorators])
{
	//Реализация паттерна Prototype
	//Создадим зелень донора 
	Greens* greensDonor = new Greens();
	string name = "Укроп";
	greensDonor->setPlantsName(&name);

	//Создадим зелень клона
	Greens* greensClone = greensDonor->clone();

	//Отобразим в консоли какую зелень мы создали
	cout << "Создали: " << endl;
	cout <<  greensDonor->getPlantsName() << endl;
	cout <<  greensClone->getPlantsName() << endl;

	//Создадим указатели на фабричные методы которые будут производить удобрения
	INutrientsStorage *humuscreator = new HumusStorage();
	INutrientsStorage *peatcreator  = new PeatStorage();

	//Создаем указатели на будущие объекты гумус и торф которые будут создаваться в цикле
	INutrients* humus = NULL;
	INutrients* peat = NULL;

	//Создаем компоновщик который будет хранить удобрения
	Composite root;
	//Создаем флажки для корректной работы удаления из компоновщика
	bool flagkomp1 = true;
	bool flagkomp2 = true;

	//Создадим фабрики для производства семян и растений, использую паттерн Abstract Factory
	IFactory* tomatofactory = new TomatoFactory();
	IFactory* cucumberfactory = new CucumberFactory();

	//Создадим семечко помидора и растение помидор
	ISeed* tomatoseed = tomatofactory->CreateSeed();
	IPlant* tomatoplant = tomatofactory->CreatePlant();
	//Посадим растение помидор
	tomatoplant->TakePlant(tomatoseed);
	
	//Создадим семечко огурца и растение огурец
	ISeed* cucumberseed = cucumberfactory->CreateSeed();
	IPlant* cucumberplant = cucumberfactory->CreatePlant();
	//Посадим растение огурец
	cucumberplant->TakePlant(cucumberseed);


	/*

	//Создаем односвязный связный список 
	Node* node1, * node2, * node3;
	node1 = new Node();
	node2 = new Node();
	node3 = new Node();
	//Заполняем список
	node1->item = 1;
	node2->item = 2;
	node3->item = 3;
	node1->p_next = node2;
	node2->p_next = node3;
	//Создаем итератор
	Iterator* iterator = new Iterator(node1);
	//Узнаем что же за число там лежит
	cout << endl << "Что лежит в Node: " << iterator->operator*() << " ";
	//Передвинем итератор
	iterator->operator++();
	//Узнаем что же за число там лежит
	cout << endl << "Что лежит в Node: " << iterator->operator*() << " "; 
	*/
	
	//Для начала нужно опросить все датчики чтобы узнать текущие параметры 
	do
	{
		for (int i = 0; i < NSensors; i++) {
			if (Sensors[i]->GiveName() == "TemperatureSensor")
			{
				DinBase->SetTemperatureCurrent(Sensors[i]);			//Опрашиваем датчик
				CurrentValue = DinBase->GetTemperatureCurrent();	//Получаем значение с датчика и записываем в поле текущее значение
				cout << endl << "Текущее значение температуры: " << CurrentValue;
				//Если температура больше чем должна быть
				if (CurrentValue > Database->GetInformation(temperatureMax))
				{
					//cout << endl << "Максимально допустимое значение температуры: " << Database->GetInformation(temperatureMax);
					Decorators[0]->DoWrite();
					cout << Database->GetInformation(temperatureMax);
					cout << endl << "Температура больше чем должна быть ";
					//Перебираем прикладные объекты чтобы найти нужный
					for (int i = 0; i < NObjects; i++) {
						if (Objects[i]->GiveName() == "Ventilator") {
							Objects[i]->Start();
							cout << endl << "Включаем вентилятор";
						}
						if (Objects[i]->GiveName() == "Window") {
							Objects[i]->Finish();
							cout << endl << "Закрываем окно";
						}
					}
				}
				//Если температура меньше чем должна быть
				if (CurrentValue < Database->GetInformation(temperatureMin))
				{
					//cout << endl << "Минимально допустимое значение температуры: " << Database->GetInformation(temperatureMin);
					Decorators[1]->DoWrite();
					cout << Database->GetInformation(temperatureMin);
					cout << endl << "Температура меньше чем должна быть ";
					//Перебираем прикладные объекты чтобы найти нужный
					for (int i = 0; i < NObjects; i++) {
						if (Objects[i]->GiveName() == "Window") {
							Objects[i]->Start();
							cout << endl << "Открываем окно";
						}
						if (Objects[i]->GiveName() == "Ventilator") {
							Objects[i]->Finish();
							cout << endl << "Выключаем вентилятор";
						}
					}
				}
			}
			else
			{
				if (Sensors[i]->GiveName() == "HumiditySensor")
				{
					DinBase->SetHumidityCurrent(Sensors[i]);		//Опрашиваем датчик
					CurrentValue = DinBase->GetHumidityCurrent();	//Получаем значение с датчика и записываем в поле текущее значение
					cout << endl << "Текущее значение влажности: " << CurrentValue;
					//Если влажность больше чем должна быть 
					if (CurrentValue > Database->GetInformation(humidityMax))
					{
						//cout << endl << "Максимально допустимое значение влажности: " << Database->GetInformation(humidityMax);
						Decorators[2]->DoWrite();
						cout << Database->GetInformation(humidityMax);
						cout << endl << "Влажность больше чем должна быть ";
						//Перебираем прикладные объекты чтобы найти нужный
						for (int i = 0; i < NObjects; i++) {
							if (Objects[i]->GiveName() == "Window") {
								Objects[i]->Start();
								cout << endl << "Открываем окно";
							}
						}
					}
					//Если влажность меньше чем должна быть
					if (CurrentValue < Database->GetInformation(humidityMin))
					{
						//cout << endl << "Минимально допустимое значение влажности: " << Database->GetInformation(humidityMin);
						Decorators[3]->DoWrite();
						cout << Database->GetInformation(humidityMin);
						cout << endl << "Влажность меньше чем должна быть ";
						//Перебираем прикладные объекты чтобы найти нужный
						for (int i = 0; i < NObjects; i++) {
							if (Objects[i]->GiveName() == "Window") {
								Objects[i]->Finish();
								cout << endl << "Закрываем окно";
							}
						}
						//Перебираем системы полива чтобы найти нужную
						for (int i = 0; i < NSystem; i++) {
							if (Systems[i]->GiveSystemType() == "WaterReservoir") {
								if (Systems[i]->StartWatering(5) == true)
								{
									cout << endl << "Пошел полив растений";
								}
								else
								{
									cout << endl << "Не хватило воды";
								};
							}
						}
					}
				}
				else
				{
					if (Sensors[i]->GiveName() == "LightingSensor")
					{
						DinBase->SetLightingCurrent(Sensors[i]);	 //Опрашиваем датчик
						CurrentValue = DinBase->GetLightingCurrent();//Получаем значение с датчика и записываем в поле текущее значение
						cout << endl << "Текущее значение освещенности: " << CurrentValue;
						//Если освещенность больше чем должна быть 
						if (CurrentValue > Database->GetInformation(lightingMax))
						{
							//cout << endl << "Максимально допустимое значение освещенности: " << Database->GetInformation(lightingMax);
							Decorators[4]->DoWrite();
							cout << Database->GetInformation(lightingMax);
							cout << endl << "Освещенность больше чем должна быть ";
							//Перебираем прикладные объекты чтобы найти нужный
							for (int i = 0; i < NObjects; i++) {
								if (Objects[i]->GiveName() == "Lamp") {
									Objects[i]->Finish();
									cout << endl << "Выключаем лампу";
								}
							}
						}
						//Если освещенность меньше чем должна быть
						if (CurrentValue < Database->GetInformation(lightingMin))
						{
							//cout << endl << "Минимально допустимое значение освещенности: " << Database->GetInformation(lightingMin);
							Decorators[5]->DoWrite();
							cout << Database->GetInformation(lightingMin);
							cout << endl << "Освещенность меньше чем должна быть ";
							//Перебираем прикладные объекты чтобы найти нужный
							for (int i = 0; i < NObjects; i++) {
								if (Objects[i]->GiveName() == "Lamp") {
									Objects[i]->Start();
									cout << endl << "Включаем лампу";
								}
							}
						}
					}
					
					//Тут реализуется паттерн Factory method
					//Опрос сколько осталось гумуса в динамической базе 
					if (DinBase->GetHumusQuantity() > 0)
					{
						humus = humuscreator->create();
						root.Add(humus);
						//Уменьшаем количество гумуса в базе на 1
						DinBase->SetHumusQuantity(DinBase->GetHumusQuantity() - 1);
							
					}
					
					//Опрос сколько осталось торфа в динамической базе 
					if (DinBase->GetPeatQuantityt() > 0)
					{
						peat = peatcreator->create();
						root.Add(peat);
						//Уменьшаем количество торфа в базе на 1
						DinBase->SetPeatQuantity(DinBase->GetPeatQuantityt() - 1);

					}
				}
			}
		}

		//Вызываем собщение что добавили удобрения которые лежат в компоновщике с удобрениями
		root.Mix();
		//Удаляем удобрения из компоновщика
		if ((DinBase->GetHumusQuantity() >= 0) && (flagkomp1 == true))
		{
			root.Remove(humus);
			if (DinBase->GetHumusQuantity() == 0)
			{
				flagkomp1 = false;
				//Освобождаем память
				delete humus;
			}
			
		}
		if ((DinBase->GetPeatQuantityt() >= 0) && (flagkomp2 == true))
		{
			root.Remove(peat);
			if (DinBase->GetPeatQuantityt() == 0)
			{
				flagkomp2 = false;
				//Освобождаем память
				delete peat;
			}
		}
		
		

		//После этого выжидаем какое-то время и повторяем заново
		cout << endl;
		//sleep_until(system_clock::now() + seconds(1));
		Counter--;
		if (Counter <= 0)
		{
			Working = false;
		}
	} while (Working == true);
}