#pragma once
#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class Bandit
{
	//�������
	int* Wait;
	//������������ ������ �������
	int MaxQueueLength;
	//������� ������ �������
	int QueueLength;
public:
	
	//����� ������ ���������� �������� �������� �������//
	int Kick(Bandit &slot);

	//�����������
	Bandit(int m);

	

	//����������
	~Bandit();

	//���������� ��������
	void Add(int c);

	//���������� ��������
	int Extract();

	//������� �������
	void Clear();

	//�������� ������������� ��������� � �������
	bool IsEmpty();

	//�������� �� ������������ �������
	bool IsFull();

	//���������� ��������� � �������
	int GetCount();

	//������������ �������
	void Show();
};

