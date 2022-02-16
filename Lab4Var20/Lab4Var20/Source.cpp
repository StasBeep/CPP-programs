#include <iostream>
#include "Header.h";
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	
	bool key = true;
	int k = 0;
	int a = 5; // �������� ���������� a
	int* pa = &a; // ����� ���������� a
	int array[] = { 1, 2, 3, 4, 5, 6 };
	int n; // ���������� ��������� �������
	// ������ ��� ���������� (6-7 �������)
	int arrayRand[] = { -1, -9, 7, 2, 9, 1, -19, 10, 0, 2 };

	do
	{
		cout << "����\n" << endl;
		cout << "1. ������� �1" << endl;
		cout << "2. ������� �2" << endl;
		cout << "3. ������� �3" << endl;
		cout << "4. ������� �4" << endl;
		cout << "5. ������� �5" << endl;
		cout << "6. ������� �6" << endl;
		cout << "7. ������� �7" << endl;
		cout << "8. ������� �8" << endl;
		cout << "0. �����\n" << endl;

		cout << "������� ����� �������: ";
		cin >> k;

		cout << endl;

		switch (k)
		{
		case 1:
			cout << "a = " << a << " ����� a: " << pa << endl;

			increment(&a); // ����� �������

			cout << "a = " << a << " ����� a: " << pa << endl << endl;

			system("cls");
			break;

		case 2:
			incrementStackVariable();

			system("cls");
			break;

		case 3:
			incrementHeapVariable();

			system("cls");
			break;

		case 4:
			writeArray(array, 6);

			system("cls");
			break;

		case 5:
			cout << endl << "������� ���������� ��������� �������: ";
			cin >> n;

			int* arrAdd = new int[n]; // ��������� �� ������ ����������

			readArray(arrAdd, n);

			// ����� ������� �� 4 �������
			writeArray(arrAdd, n);

			// ������������ ������
			delete arrAdd;

			system("cls");
			break;

		case 6:
			// ����� ��������� �������
			writeArray(array, 6);

			// ���������� �������
			sort(array, 6);

			cout << endl;

			// ����� �������������� �������
			writeArray(array, 6);

			system("cls");
			break;

		case 7:
			sortStackArray(arrayRand, 10);

			system("cls");
			break;

		case 8:
			sortArrayPerson();

			system("cls");
			break;

		case 0:
			key = false;
			system("cls");
			break;
		}
	} while (key);
}