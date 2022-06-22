#include "Bandit.h"
#include <iostream>
using namespace std;

void Bandit::Show()
{
	cout << "\n-----------------------------------\n";
	//������������ �������
	for (int i = 0; i < QueueLength; i++) {
		cout << Wait[i] << " ";
	}
	cout << "\n-----------------------------------\n";
}

Bandit::Bandit(int m)
{
	//�������� ������
	MaxQueueLength = m;
	//������� �������
	Wait = new int[MaxQueueLength];
	//���������� ������� �����
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
	//���� � ������� ���� ��������� �����, �� ����������� ���������� �������� � ��������� ����� �������
	if (!IsFull())
		Wait[QueueLength++] = c;
}

int Bandit::Extract()
{
	//���� � ������� ���� ��������, �� ���������� ���, ������� ����� ������ � �������� �������
	if (!IsEmpty()) {
		//��������� ������
		int temp = Wait[0];
		//�������� ��� ��������
		for (int i = 1; i < QueueLength; i++)
			Wait[i - 1] = Wait[i];
		//����������� ������ "����������� ������� � �����
		Wait[QueueLength - 1] = temp; 
		return Wait[0];
	}
	else return 0;
}

void Bandit::Clear()
{
	//����������� "�������" �������
	QueueLength = 0;
}

bool Bandit::IsEmpty()
{
	//����?
	return QueueLength == 0;
}

bool Bandit::IsFull()
{
	// �����?
	return QueueLength == MaxQueueLength;
}

int Bandit::GetCount()
{
	//���������� �������������� � ����� ���������
	return QueueLength;
}