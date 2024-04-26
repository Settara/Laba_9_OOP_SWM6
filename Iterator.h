#pragma once
//����� �������� ������
struct Node
{
	double item;
	Node* p_next;	//��������� �� ��������� ����� � ������� ������
};

//����� �������� �� ��������
class Iterator
{
private:
	Node* Pt;	//���� ��������
public:
	Iterator() : Pt(nullptr) {}
	//����������� ��������� ��������� �� ������ �������� ������
	Iterator(Node* pn) : Pt(pn) {}
	//������������� �������� ��������� �������� ������ �� ������
	double operator*()
	{
		return Pt->item;
	}
	//������������� �������� �������������� ��������
	Iterator& operator++()
	{
		Pt = Pt->p_next;
		return *this;
	}

};

