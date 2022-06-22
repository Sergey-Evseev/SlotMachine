#pragma once
#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class Bandit
{
	//Очередь
	int* Wait;
	//Максимальный размер очереди
	int MaxQueueLength;
	//Текущий размер очереди
	int QueueLength;
public:
	
	//метод вызова случайного значения перебора очереди//
	int Kick(Bandit &slot);

	//Конструктор
	Bandit(int m);

	

	//Деструктор
	~Bandit();

	//Добавление элемента
	void Add(int c);

	//Извлечение элемента
	int Extract();

	//Очистка очереди
	void Clear();

	//Проверка существования элементов в очереди
	bool IsEmpty();

	//Проверка на переполнение очереди
	bool IsFull();

	//Количество элементов в очереди
	int GetCount();

	//демонстрация очереди
	void Show();
};

