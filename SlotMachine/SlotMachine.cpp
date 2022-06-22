//Lesson 7: Task 1. ������� �������� ���� ���������� ������. ��������, ��� ������� ������ �Enter� ���������� ���������
//���� ���������(�����������, ���������� �������� ������� �� ��� ���������� ��������), �� ������� ���������� ������ ������; 
//� ���� �������� ������������ ����������, �� ����� �������� ����� - �� �������.

#include <iostream>
#include <time.h>
#include "Bandit.h";

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	//�������� �������
	Bandit slot(6); 
	//������������� �������
	for (int i = 1; i < 8; i++)
	{
		slot.Add(i);
	}
	slot.Show();
	cout << slot.Extract();

	cout << slot.Kick(slot) << endl;

	return 0;
}
