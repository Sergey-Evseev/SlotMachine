//Lesson 7: Task 1. Создать имитацию игры «однорукий бандит». Например, при нажатии кнопки «Enter» происходит «вращение»
//трех барабанов(естественно, количество вращений каждого из них выбирается случайно), на которых изображены разные значки; 
//и если выпадает определенная комбинация, то игрок получает какой - то выигрыш.

#include <iostream>
#include <time.h>
#include "Bandit.h";

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	//создание очереди
	Bandit slot(6); 
	//инициализация очереди
	for (int i = 1; i < 8; i++)
	{
		slot.Add(i);
	}
	slot.Show();
	cout << slot.Extract();

	cout << slot.Kick(slot) << endl;

	return 0;
}
