#include <iostream>
#include "Header.h";
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	
	bool key = true;
	int k = 0;
	int a = 5; // значение переменной a
	int* pa = &a; // адрес переменной a
	int array[] = { 1, 2, 3, 4, 5, 6 };
	int n; // количество элементов массива
	// массив для сортировки (6-7 задание)
	int arrayRand[] = { -1, -9, 7, 2, 9, 1, -19, 10, 0, 2 };

	do
	{
		cout << "Меню\n" << endl;
		cout << "1. Задание №1" << endl;
		cout << "2. Задание №2" << endl;
		cout << "3. Задание №3" << endl;
		cout << "4. Задание №4" << endl;
		cout << "5. Задание №5" << endl;
		cout << "6. Задание №6" << endl;
		cout << "7. Задание №7" << endl;
		cout << "8. Задание №8" << endl;
		cout << "0. Выход\n" << endl;

		cout << "Введите номер задания: ";
		cin >> k;

		cout << endl;

		switch (k)
		{
		case 1:
			cout << "a = " << a << " адрес a: " << pa << endl;

			increment(&a); // вызов функции

			cout << "a = " << a << " адрес a: " << pa << endl << endl;

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
			cout << endl << "Введите количество элементов массива: ";
			cin >> n;

			int* arrAdd = new int[n]; // указатель на массив заполнения

			readArray(arrAdd, n);

			// вывод массива из 4 задания
			writeArray(arrAdd, n);

			// освобождение памяти
			delete arrAdd;

			system("cls");
			break;

		case 6:
			// вывод исходного массива
			writeArray(array, 6);

			// сортировка массива
			sort(array, 6);

			cout << endl;

			// вывод сортированного массива
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