#include <iostream>
#include "OperFunc.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	double x, y, result;
	bool goal;
	int k;

	cout << "Выберите задание: " << endl;
	cout << "Задание 1" << endl;
	cout << "Задание 2" << endl << endl;
	cout << "Введите номер задания: ";
	cin >> k;

	switch (k)
	{
	case 1:
		cout << "Введите х: ";
		cin >> x;

		cout << "Введите y: ";
		cin >> y;

		goal = isInArea(x, y);

		cout << endl;
		cout << "Выстрел попал в цель? " << goal << endl << endl;
		break;
	case 2:
		cout << "Введите x: ";
		cin >> x;

		result = f(x);
		cout << endl;
		cout << "f(x) = " << result << endl;
		break;
	}
}