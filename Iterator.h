#pragma once
//«вено св€зного списка
struct Node
{
	double item;
	Node* p_next;	//”казатель на следующее звено в св€зном списке
};

// ласс отвечает за итератор
class Iterator
{
private:
	Node* Pt;	//ѕоле содержит
public:
	Iterator() : Pt(nullptr) {}
	// онструктор принимает указатель на начало св€зного списка
	Iterator(Node* pn) : Pt(pn) {}
	//ѕерегруженный оператор позвол€ет получать данные из списка
	double operator*()
	{
		return Pt->item;
	}
	//ѕерегруженный оператор инкрементирует итератор
	Iterator& operator++()
	{
		Pt = Pt->p_next;
		return *this;
	}

};

