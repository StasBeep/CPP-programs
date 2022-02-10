# ИТиП - Лабораторная работа №2

> Вариант 5

* [Цель практикума](*Цель-практикума)
* [Задание 1](*Задание-1)
* [Задание 2](*Задание-2)
* [Задание 3](*Задание-3)

## Цель практикума

Овладеть навыками создания разветвляющихся алгоритмов на языке C++ с применением инструкций выбора,
условных выражений, логических операций и операций отношения

## Задание 1

Написать функцию, которая получает в качестве параметров координаты точки (𝑥, 𝑦) и определяет, попадает ли она в заштрихованную
область на рисунке, который соответствует Вашему варианту (см. таблицу 1). Попадание на границу области считать попаданием в область.
Функция возвращает 1, если точка попадает в область, 0 в противном случае. Прототип функции _Bool isInArea(double x, double y).
Функция не должна использовать функции консольного ввода-вывода.

*OperFunc.h*:
```c++
#pragma once

bool isInArea(double, double);
```

*Source.cpp*:
```c++
#include <iostream>
#include "OperFunc.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	double x, y;
	bool goal;

	cout << "Введите х: ";
	cin >> x;

	cout << "Введите y: ";
	cin >> y;

	goal = isInArea(x, y);
	
	cout << endl;
	cout << "Выстрел попал в цель? " << goal << endl;
}
```

*OperFunc.cpp*:
```c++
#include <cmath>

bool isInArea(double x, double y)
{
	if (y <= -x + 1 && y >= 0 && x >= 0)
		return 1;
	if (x <= 0 && y <= 0 && x >= -1 && y >= -1)
		return 1;
	return 0;
}
```

## Задание 2

Используя условную операцию (условие ? оператор : оператор) написать функцию для вычисления выражения, указанного в таблице 2.
Функция получает 𝑥 в качестве входного параметра и возвращает значение выражения.
Прототип функции double f(double x).
Функция не должна использовать функции консольного ввода-вывода.

*OperFunc.h*:
```c++
#pragma once

bool isInArea(double, double);

double f(double);
```

*Source.cpp*:
```c++
#include <iostream>
#include "OperFunc.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	double x, y, result;
	bool goal;

	cout << "Задание 1" << endl << endl;

	cout << "Введите х: ";
	cin >> x;

	cout << "Введите y: ";
	cin >> y;

	goal = isInArea(x, y);
	
	cout << endl;
	cout << "Выстрел попал в цель? " << goal << endl << endl;
	
	cout << "Задание 2" << endl << endl;

	cout << "Введите x: ";
	cin >> x;

	result = f(x);
	cout << endl;
	cout << "f(x) = " << result << endl;
}
```

*OperFunc.cpp*:
```c++
#include <cmath>

bool isInArea(double x, double y)
{
	if (y <= -x + 1 && y >= 0 && x >= 0)
		return 1;
	if (x <= 0 && y <= 0 && x >= -1 && y >= -1)
		return 1;
	return 0;
}

double f(double x)
{
	double res;
	if (x <= 9 ? res = cos(2 * x) + 9 : res = cos(x) - x - 9);
	return res;
}
```

## Задание 3

Написать функцию main(), которая будет выводить меню и ожидать ответа пользователя:
	* Задание 1
	* Задание 2
Обработку ответа пользователя осуществить с помощью оператора switch.
	* При вводе пользователем цифры 1 перейти к демонстрации задания 1. 
	* При вводе пользователем цифры 2 перейти к демонстрации задания 2.
Для демонстрации задания 1 запросить у пользователя ввод двух чисел, вызвать разработанную в задании 1 функцию и вывести на экран результат – попадает ли точка в заданную область или нет.
Для демонстрации задания 2 запросить у пользователя ввод числа 𝑥, вызвать разработанную в задании 2 функцию и вывести результат расчёта на экран.
Скомпилировать все файлы, скомпоновать и выполнить полученный исполняемый файл

*OperFunc.h*:
```c++
#pragma once

bool isInArea(double, double);

double f(double);
```

*Source.cpp*:
```c++
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
```

*OperFunc.cpp*:
```c++
#include <cmath>

bool isInArea(double x, double y)
{
	if (y <= -x + 1 && y >= 0 && x >= 0)
		return 1;
	if (x <= 0 && y <= 0 && x >= -1 && y >= -1)
		return 1;
	return 0;
}

double f(double x)
{
	double res;
	if (x <= 9 ? res = cos(2 * x) + 9 : res = cos(x) - x - 9);
	return res;
}
```