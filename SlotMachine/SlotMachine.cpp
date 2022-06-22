//Lesson 7: Task 1. ������� �������� ���� ���������� ������. ��������, ��� ������� ������ �Enter� ���������� ���������
//���� ���������(�����������, ���������� �������� ������� �� ��� ���������� ��������), �� ������� ���������� ������ ������; 
//� ���� �������� ������������ ����������, �� ����� �������� �����-�� �������.

#include <iostream>
#include <time.h>
#include "Bandit.h";

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	//�������� �������
	Bandit slot(3); 
	//������������� �������
	for (int i = 1; i < 4; i++) { slot.Add(i);}	
	cout << "VARIANTS: "; slot.Show();
	char quit;
	do {

		int A = slot.Kick(slot);
		int B = slot.Kick(slot);
		int C = slot.Kick(slot);
		cout << "\nYOUR NUMBERS: \n" << A << " : " << B << " : " << C << "\n\n";
		if (A == B && A == C && B == C)
		{
			cout << "You are the winner!" << "\n\n";
		}
		else cout << "Try once again!" << "\n\n";
		cout << "����������� ��� ���, y/n?" << endl;
	} while (cin >> quit && quit == 'y');

	return 0;
}
