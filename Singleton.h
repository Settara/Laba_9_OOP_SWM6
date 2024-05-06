#pragma once
#include <iostream>
#include "IDynamicDatabase.h"
using namespace std;

//����� ��������� ������� Singleton
class Singleton
{
private:
    static Singleton* instance;	//���� ������ ��������� �� ��������� �������
    IDynamicDatabase* data; //���� ������ ������(��������� �� ������������ ���� ������)
    Singleton() //����������� ������ ���� ��������� ����� ������ ������ ���� ������� ������� ��������
    {
        cout << "����������� � ������������ ���� ������" << endl;
        data = new IDynamicDatabase("������������ ���� ������");
    }
public:
    //������� ����������� ����������� � �������� ������������
    Singleton(const Singleton&) = delete;
    void operator = (const Singleton&) = delete;
    //������� ����������� ����� ����� ������� ����� �������� ������ �� ���������
    static Singleton* getConnection() {
        //���� ���� ����� nullptr �� �������������� ���
        if (instance == nullptr)
        {
            instance = new Singleton();
        }
        return instance;
    }
    //����� ���������� �������� ���� data
    IDynamicDatabase* selectData() const {
        return data;
    }
};

