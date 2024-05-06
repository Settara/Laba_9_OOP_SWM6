#include "IGMS.h"

void IGMS::Management(IDynamicDatabase* DinBase, ProxyDatabase* Database, ISensor* Sensors[NSensors], IAO* Objects[NObjects], IIS* Systems[NSystem], Decorator* Decorators[NDecorators])
{
	//���������� �������� Prototype
	//�������� ������ ������ 
	Greens* greensDonor = new Greens();
	string name = "�����";
	greensDonor->setPlantsName(&name);

	//�������� ������ �����
	Greens* greensClone = greensDonor->clone();

	//��������� � ������� ����� ������ �� �������
	cout << "�������: " << endl;
	cout <<  greensDonor->getPlantsName() << endl;
	cout <<  greensClone->getPlantsName() << endl;

	//�������� ��������� �� ��������� ������ ������� ����� ����������� ���������
	INutrientsStorage *humuscreator = new HumusStorage();
	INutrientsStorage *peatcreator  = new PeatStorage();

	//������� ��������� �� ������� ������� ����� � ���� ������� ����� ����������� � �����
	INutrients* humus = NULL;
	INutrients* peat = NULL;

	//������� ����������� ������� ����� ������� ���������
	Composite root;
	//������� ������ ��� ���������� ������ �������� �� ������������
	bool flagkomp1 = true;
	bool flagkomp2 = true;

	//�������� ������� ��� ������������ ����� � ��������, ��������� ������� Abstract Factory
	IFactory* tomatofactory = new TomatoFactory();
	IFactory* cucumberfactory = new CucumberFactory();

	//�������� ������� �������� � �������� �������
	ISeed* tomatoseed = tomatofactory->CreateSeed();
	IPlant* tomatoplant = tomatofactory->CreatePlant();
	//������� �������� �������
	tomatoplant->TakePlant(tomatoseed);
	
	//�������� ������� ������ � �������� ������
	ISeed* cucumberseed = cucumberfactory->CreateSeed();
	IPlant* cucumberplant = cucumberfactory->CreatePlant();
	//������� �������� ������
	cucumberplant->TakePlant(cucumberseed);


	/*

	//������� ����������� ������� ������ 
	Node* node1, * node2, * node3;
	node1 = new Node();
	node2 = new Node();
	node3 = new Node();
	//��������� ������
	node1->item = 1;
	node2->item = 2;
	node3->item = 3;
	node1->p_next = node2;
	node2->p_next = node3;
	//������� ��������
	Iterator* iterator = new Iterator(node1);
	//������ ��� �� �� ����� ��� �����
	cout << endl << "��� ����� � Node: " << iterator->operator*() << " ";
	//���������� ��������
	iterator->operator++();
	//������ ��� �� �� ����� ��� �����
	cout << endl << "��� ����� � Node: " << iterator->operator*() << " "; 
	*/
	
	//��� ������ ����� �������� ��� ������� ����� ������ ������� ��������� 
	do
	{
		for (int i = 0; i < NSensors; i++) {
			if (Sensors[i]->GiveName() == "TemperatureSensor")
			{
				DinBase->SetTemperatureCurrent(Sensors[i]);			//���������� ������
				CurrentValue = DinBase->GetTemperatureCurrent();	//�������� �������� � ������� � ���������� � ���� ������� ��������
				cout << endl << "������� �������� �����������: " << CurrentValue;
				//���� ����������� ������ ��� ������ ����
				if (CurrentValue > Database->GetInformation(temperatureMax))
				{
					//cout << endl << "����������� ���������� �������� �����������: " << Database->GetInformation(temperatureMax);
					Decorators[0]->DoWrite();
					cout << Database->GetInformation(temperatureMax);
					cout << endl << "����������� ������ ��� ������ ���� ";
					//���������� ���������� ������� ����� ����� ������
					for (int i = 0; i < NObjects; i++) {
						if (Objects[i]->GiveName() == "Ventilator") {
							Objects[i]->Start();
							cout << endl << "�������� ����������";
						}
						if (Objects[i]->GiveName() == "Window") {
							Objects[i]->Finish();
							cout << endl << "��������� ����";
						}
					}
				}
				//���� ����������� ������ ��� ������ ����
				if (CurrentValue < Database->GetInformation(temperatureMin))
				{
					//cout << endl << "���������� ���������� �������� �����������: " << Database->GetInformation(temperatureMin);
					Decorators[1]->DoWrite();
					cout << Database->GetInformation(temperatureMin);
					cout << endl << "����������� ������ ��� ������ ���� ";
					//���������� ���������� ������� ����� ����� ������
					for (int i = 0; i < NObjects; i++) {
						if (Objects[i]->GiveName() == "Window") {
							Objects[i]->Start();
							cout << endl << "��������� ����";
						}
						if (Objects[i]->GiveName() == "Ventilator") {
							Objects[i]->Finish();
							cout << endl << "��������� ����������";
						}
					}
				}
			}
			else
			{
				if (Sensors[i]->GiveName() == "HumiditySensor")
				{
					DinBase->SetHumidityCurrent(Sensors[i]);		//���������� ������
					CurrentValue = DinBase->GetHumidityCurrent();	//�������� �������� � ������� � ���������� � ���� ������� ��������
					cout << endl << "������� �������� ���������: " << CurrentValue;
					//���� ��������� ������ ��� ������ ���� 
					if (CurrentValue > Database->GetInformation(humidityMax))
					{
						//cout << endl << "����������� ���������� �������� ���������: " << Database->GetInformation(humidityMax);
						Decorators[2]->DoWrite();
						cout << Database->GetInformation(humidityMax);
						cout << endl << "��������� ������ ��� ������ ���� ";
						//���������� ���������� ������� ����� ����� ������
						for (int i = 0; i < NObjects; i++) {
							if (Objects[i]->GiveName() == "Window") {
								Objects[i]->Start();
								cout << endl << "��������� ����";
							}
						}
					}
					//���� ��������� ������ ��� ������ ����
					if (CurrentValue < Database->GetInformation(humidityMin))
					{
						//cout << endl << "���������� ���������� �������� ���������: " << Database->GetInformation(humidityMin);
						Decorators[3]->DoWrite();
						cout << Database->GetInformation(humidityMin);
						cout << endl << "��������� ������ ��� ������ ���� ";
						//���������� ���������� ������� ����� ����� ������
						for (int i = 0; i < NObjects; i++) {
							if (Objects[i]->GiveName() == "Window") {
								Objects[i]->Finish();
								cout << endl << "��������� ����";
							}
						}
						//���������� ������� ������ ����� ����� ������
						for (int i = 0; i < NSystem; i++) {
							if (Systems[i]->GiveSystemType() == "WaterReservoir") {
								if (Systems[i]->StartWatering(5) == true)
								{
									cout << endl << "����� ����� ��������";
								}
								else
								{
									cout << endl << "�� ������� ����";
								};
							}
						}
					}
				}
				else
				{
					if (Sensors[i]->GiveName() == "LightingSensor")
					{
						DinBase->SetLightingCurrent(Sensors[i]);	 //���������� ������
						CurrentValue = DinBase->GetLightingCurrent();//�������� �������� � ������� � ���������� � ���� ������� ��������
						cout << endl << "������� �������� ������������: " << CurrentValue;
						//���� ������������ ������ ��� ������ ���� 
						if (CurrentValue > Database->GetInformation(lightingMax))
						{
							//cout << endl << "����������� ���������� �������� ������������: " << Database->GetInformation(lightingMax);
							Decorators[4]->DoWrite();
							cout << Database->GetInformation(lightingMax);
							cout << endl << "������������ ������ ��� ������ ���� ";
							//���������� ���������� ������� ����� ����� ������
							for (int i = 0; i < NObjects; i++) {
								if (Objects[i]->GiveName() == "Lamp") {
									Objects[i]->Finish();
									cout << endl << "��������� �����";
								}
							}
						}
						//���� ������������ ������ ��� ������ ����
						if (CurrentValue < Database->GetInformation(lightingMin))
						{
							//cout << endl << "���������� ���������� �������� ������������: " << Database->GetInformation(lightingMin);
							Decorators[5]->DoWrite();
							cout << Database->GetInformation(lightingMin);
							cout << endl << "������������ ������ ��� ������ ���� ";
							//���������� ���������� ������� ����� ����� ������
							for (int i = 0; i < NObjects; i++) {
								if (Objects[i]->GiveName() == "Lamp") {
									Objects[i]->Start();
									cout << endl << "�������� �����";
								}
							}
						}
					}
					
					//��� ����������� ������� Factory method
					//����� ������� �������� ������ � ������������ ���� 
					if (DinBase->GetHumusQuantity() > 0)
					{
						humus = humuscreator->create();
						root.Add(humus);
						//��������� ���������� ������ � ���� �� 1
						DinBase->SetHumusQuantity(DinBase->GetHumusQuantity() - 1);
							
					}
					
					//����� ������� �������� ����� � ������������ ���� 
					if (DinBase->GetPeatQuantityt() > 0)
					{
						peat = peatcreator->create();
						root.Add(peat);
						//��������� ���������� ����� � ���� �� 1
						DinBase->SetPeatQuantity(DinBase->GetPeatQuantityt() - 1);

					}
				}
			}
		}

		//�������� �������� ��� �������� ��������� ������� ����� � ������������ � �����������
		root.Mix();
		//������� ��������� �� ������������
		if ((DinBase->GetHumusQuantity() >= 0) && (flagkomp1 == true))
		{
			root.Remove(humus);
			if (DinBase->GetHumusQuantity() == 0)
			{
				flagkomp1 = false;
				//����������� ������
				delete humus;
			}
			
		}
		if ((DinBase->GetPeatQuantityt() >= 0) && (flagkomp2 == true))
		{
			root.Remove(peat);
			if (DinBase->GetPeatQuantityt() == 0)
			{
				flagkomp2 = false;
				//����������� ������
				delete peat;
			}
		}
		
		

		//����� ����� �������� �����-�� ����� � ��������� ������
		cout << endl;
		//sleep_until(system_clock::now() + seconds(1));
		Counter--;
		if (Counter <= 0)
		{
			Working = false;
		}
	} while (Working == true);
}