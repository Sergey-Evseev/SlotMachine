#include "Bandit.h"
#include <iostream>
using namespace std;

void Bandit::Show()
{
	cout << "\n-----------------------------------\n";
	//демонстраци€ очереди
	for (int i = 0; i < QueueLength; i++) {
		cout << Wait[i] << " ";
	}
	cout << "\n-----------------------------------\n";
}

Bandit::Bandit(int m)
{
	//получаем размер
	MaxQueueLength = m;
	//создаем очередь
	Wait = new int[MaxQueueLength];
	//»значально очередь пуста
	QueueLength = 0;	
}

Bandit::~Bandit()
{
	delete[] Wait;
}

int Bandit::Kick(Bandit & slot)
{
	int round=0;	
	while (round < rand() % 100)
	{
		slot.Extract();
	}
	return Wait[0];
}

void Bandit::Add(int c)
{
	//≈сли в очереди есть свободное место, то увеличиваем количество значений и вставл€ем новый элемент
	if (!IsFull())
		Wait[QueueLength++] = c;
}

int Bandit::Extract()
{
	//≈сли в очереди есть элементы, то возвращаем тот, который вошел первым и сдвигаем очередь
	if (!IsEmpty()) {
		//запомнить первый
		int temp = Wait[0];
		//сдвинуть все элементы
		for (int i = 1; i < QueueLength; i++)
			Wait[i - 1] = Wait[i];
		//забрасываем первый "вытолкнутый элемент в конец
		Wait[QueueLength - 1] = temp; 
		return Wait[0];
	}
	else return 0;
}

void Bandit::Clear()
{
	//Ёффективна€ "очистка" очереди
	QueueLength = 0;
}

bool Bandit::IsEmpty()
{
	//ѕуст?
	return QueueLength == 0;
}

bool Bandit::IsFull()
{
	// ѕолон?
	return QueueLength == MaxQueueLength;
}

int Bandit::GetCount()
{
	// оличество присутствующих в стеке элементов
	return QueueLength;
}