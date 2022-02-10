# ИТиП - Лабораторная работа №3

> Вариант 20

* [Цель практикума](*Цель-практикума)
* [Краткие сведения по циклам](*Краткие-сведения-по-циклам)
* [Задание 1](*Задание-1)
* [Задание 2](*Задание-2)
* [Задание 3](*Задание-3)

## Цель практикума

Овладеть навыками создания циклических алгоритмов на языке C++ с применением инструкций цикла на примере алгоритмов работы с последовательностями чисел

## Краткие сведения по циклам

`Регулярные циклы` – это циклы, число итераций которых заранее известно.
`Итерационные циклы` – это циклы, число итераций которых заранее неизвестно.

Для того чтобы прервать выполнение текущей итерации и перейти к следующей необходимо воспользоваться инструкцией `continue`.
Для досрочного завершения цикла необходимо воспользоваться инструкцией `break`.

## Задание 1

Написать функцию для вычисления выражения ∑𝑛−1 𝑎𝑖.
Функция в качестве параметра принимает значение 𝑛 и вычисляет сумму 𝑛 слагаемых. Прототип функции double summ(int n).
Функция не должна использовать функции консольного ввода-вывода.

*Header.h*:
```c++
#pragma once

double summNfor(int);

double summNwhile(int);

double summNdowhile(int);
```

*Source.cpp*:
```c++
#include <iostream>
#include "Header.h";
using namespace std;

int main() 
{
	setlocale(LC_ALL, "Russian");

	int n;

	cout << "Задание №1" << endl << endl;

	cout << "Введите количество итераций: ";
	cin >> n;

	cout << endl << "Вычисление значения суммы ряда (for): "
		<< summNfor(n) << endl;

	cout << endl << "Вычисление значения суммы ряда (while): "
		<< summNwhile(n) << endl;

	cout << endl << "Вычисление значения суммы ряда (do...while): "
		<< summNdowhile(n) << endl;
}
```

*OperFunc.cpp*:
```c++
#include <cmath>

// Вычисление регулярного цикла (цикл for)
// @ {int} n - количество итераций
// @ return {double}
double summNfor(int n)
{
	double S = 0;
	for (int i = 0; i < n; i++)
	{
		double a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		S += a;
	}
	return S;
}

// Вычисление регулярного цикла (цикл while)
// @ {int} n - количество итераций
// @ return {double}
double summNwhile(int n)
{
	double S = 0;
	int i = 0;
	while (i < n)
	{
		double a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		S += a;
		i++;
	}
	return S;
}

// Вычисление регулярного цикла (цикл do...while)
// @ {int} n - количество итераций
// @ return {double}
double summNdowhile(int n)
{
	double S = 0;
	int i = 0;
	do
	{
		double a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		S += a;
		i++;
	} while (i < n);
	return S;
}
```

## Задание 2

Написать функцию для вычисления выражения ∑∞ 𝑎𝑖 с точностью 𝜀.
Функция в качестве параметра принимает значение 𝜀 и вычисляет сумму до тех пор, пока не выполнится условие |𝑎𝑖| ≤ 𝜀.
Прототип функции double summ2(double eps).
Функция не должна использовать функции консольного ввода-вывода.

*Header.h*:
```c++
#pragma once

double summNfor(int);

double summNwhile(int);

double summNdowhile(int);

double summEpsfor(double);

double summEpswhile(double);

double summEpsdowhile(double);
```

*Source.cpp*:
```c++
#include <iostream>
#include "Header.h";
using namespace std;

int main() 
{
	setlocale(LC_ALL, "Russian");

	int n;
	double eps;

	cout << "Задание №1" << endl << endl;

	cout << "Введите количество итераций: ";
	cin >> n;

	cout << endl << "Вычисление значения суммы ряда (for): "
		<< summNfor(n) << endl;

	cout << "Вычисление значения суммы ряда (while): "
		<< summNwhile(n) << endl;

	cout << "Вычисление значения суммы ряда (do...while): "
		<< summNdowhile(n) << endl << endl;

	cout << "Задание №2" << endl << endl;

	cout << "Введите точность: ";
	cin >> eps;

	cout << endl << "Вычисление значения суммы ряда с точностью: "
		<< eps << " (for) = " << summEpsfor(eps) << endl;

	cout << "Вычисление значения суммы ряда с точностью: "
		<< eps << " (while) = " << summEpswhile(eps) << endl;

	cout << "Вычисление значения суммы ряда с точностью: "
		<< eps << " (do...while) = " << summEpsdowhile(eps) << endl << endl;
}
```

*OperFunc.cpp*:
```c++
#include <cmath>

// Вычисление регулярного цикла (цикл for)
// @ {int} n - количество итераций
// @ return {double}
double summNfor(int n)
{
	double S = 0;
	for (int i = 0; i < n; i++)
	{
		double a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		S += a;
	}
	return S;
}

// Вычисление регулярного цикла (цикл while)
// @ {int} n - количество итераций
// @ return {double}
double summNwhile(int n)
{
	double S = 0;
	int i = 0;
	while (i < n)
	{
		double a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		S += a;
		i++;
	}
	return S;
}

// Вычисление регулярного цикла (цикл do...while)
// @ {int} n - количество итераций
// @ return {double}
double summNdowhile(int n)
{
	double S = 0;
	int i = 0;
	do
	{
		double a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		S += a;
		i++;
	} while (i < n);
	return S;
}

// Вычисление итерационного цикла с точчностью eps (цикл for)
// @ {double} eps - точность расчёта ряда
// @ return {double}
double summEpsfor(double eps)
{
	double a = -1;
	double S = a;
	for (int i = 2; abs(a) > eps; i++)
	{
		a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		S += a;
	}

	return S;
}

// Вычисление итерационного цикла с точчностью eps (цикл while)
// @ {double} eps - точность расчёта ряда
// @ return {double}
double summEpswhile(double eps)
{
	double a = -1;
	double S = a;
	int i = 2;
	while( abs(a) > eps )
	{
		a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		S += a;
		i++;
	}

	return S;
}

// Вычисление итерационного цикла с точчностью eps (цикл do...while)
// @ {double} eps - точность расчёта ряда
// @ return {double}
double summEpsdowhile(double eps)
{
	double a = -1;
	double S = a;
	int i = 2;
	do
	{
		a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		S += a;
		i++;
	} while (abs(a) > eps);

	return S;
}
```

## Задание 3

Написать функцию для вычисления выражения ∑∞ 𝑎𝑖 с точностью 𝜀.
Функция в качестве параметра принимает значение 𝜀 и вычисляет сумму до тех пор, пока не выполнится условие |𝑎𝑖| ≤ 𝜀.
Прототип функции double summ2(double eps).
Функция не должна использовать функции консольного ввода-вывода.

*Header.h*:
```c++
#pragma once

double summNfor(int);

double summNwhile(int);

double summNdowhile(int);

double summEpsfor(double);

double summEpswhile(double);

double summEpsdowhile(double);

void printFor(int, int);

void printWhile(int, int);

void printDowhile(int, int);
```

*Source.cpp*:
```c++
#include <iostream>
#include "Header.h";
using namespace std;

int main() 
{
	setlocale(LC_ALL, "Russian");

	int n, k;
	double eps;

	cout << "Задание №1" << endl << endl;

	cout << "Введите количество итераций: ";
	cin >> n;

	cout << endl << "Вычисление значения суммы ряда (for): "
		<< summNfor(n) << endl;

	cout << "Вычисление значения суммы ряда (while): "
		<< summNwhile(n) << endl;

	cout << "Вычисление значения суммы ряда (do...while): "
		<< summNdowhile(n) << endl << endl;

	cout << "Задание №2" << endl << endl;

	cout << "Введите точность: ";
	cin >> eps;

	cout << endl << "Вычисление значения суммы ряда с точностью: "
		<< eps << " (for) = " << summEpsfor(eps) << endl;

	cout << "Вычисление значения суммы ряда с точностью: "
		<< eps << " (while) = " << summEpswhile(eps) << endl;

	cout << "Вычисление значения суммы ряда с точностью: "
		<< eps << " (do...while) = " << summEpsdowhile(eps) << endl << endl;

	cout << "Задание №3" << endl << endl;

	cout << "Введите n: ";
	cin >> n;
	cout << "Введите k: ";
	cin >> k;

	printFor(n, k);
	cout << endl;
	printWhile(n, k);
	cout << endl;
	printDowhile(n, k);
	cout << endl << endl;
}
```

*OperFunc.cpp*:
```c++
#include <cmath>
#include <stdio.h>

// Вычисление регулярного цикла (цикл for)
// @ {int} n - количество итераций
// @ return {double}
double summNfor(int n)
{
	double S = 0;
	for (int i = 0; i < n; i++)
	{
		double a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		S += a;
	}
	return S;
}

// Вычисление регулярного цикла (цикл while)
// @ {int} n - количество итераций
// @ return {double}
double summNwhile(int n)
{
	double S = 0;
	int i = 0;
	while (i < n)
	{
		double a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		S += a;
		i++;
	}
	return S;
}

// Вычисление регулярного цикла (цикл do...while)
// @ {int} n - количество итераций
// @ return {double}
double summNdowhile(int n)
{
	double S = 0;
	int i = 0;
	do
	{
		double a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		S += a;
		i++;
	} while (i < n);
	return S;
}

// Вычисление итерационного цикла с точчностью eps (цикл for)
// @ {double} eps - точность расчёта ряда
// @ return {double}
double summEpsfor(double eps)
{
	double a = -1;
	double S = a;
	for (int i = 2; abs(a) > eps; i++)
	{
		a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		S += a;
	}

	return S;
}

// Вычисление итерационного цикла с точчностью eps (цикл while)
// @ {double} eps - точность расчёта ряда
// @ return {double}
double summEpswhile(double eps)
{
	double a = -1;
	double S = a;
	int i = 2;
	while( abs(a) > eps )
	{
		a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		S += a;
		i++;
	}

	return S;
}

// Вычисление итерационного цикла с точчностью eps (цикл do...while)
// @ {double} eps - точность расчёта ряда
// @ return {double}
double summEpsdowhile(double eps)
{
	double a = -1;
	double S = a;
	int i = 2;
	do
	{
		a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		S += a;
		i++;
	} while (abs(a) > eps);

	return S;
}

// Функция вывода членов последовательности исключая k член (for)
void printFor(int n, int k)
{
	for (int i = 0; i < n; i++)
	{
		if (i == k)
			continue;
		double a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		printf("%lf\t", a);
	}
}

// Функция вывода членов последовательности исключая k член (while)
void printWhile(int n, int k)
{
	int i = 0;
	while ( i < n )
	{
		if (i == k)
		{
			i++;
			continue;
		}
		double a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		printf("%lf\t", a);
		i++;
	}
}

// Функция вывода членов последовательности исключая k член (do...while)
void printDowhile(int n, int k)
{
	int i = 0;
	do
	{
		if (i == k)
		{
			i++;
			continue;
		}
		double a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		printf("%lf\t", a);
		i++;
	} while (i < n);
}
```

## Задание 4

Написать функцию, которая возвращает номер первого члена последовательности {𝑎𝑖}, для которого выполняется условие |𝑎𝑖| ≤ 𝜀.
Функция в качестве параметра принимает значение 𝜀.
Выход из цикла организовать с помощью оператора break. Прототип функции int findFirstElement(double eps).
Функция не должна использовать функции консольного ввода-вывода.

*Header.h*:
```c++
#pragma once

double summNfor(int);

double summNwhile(int);

double summNdowhile(int);

double summEpsfor(double);

double summEpswhile(double);

double summEpsdowhile(double);

void printFor(int, int);

void printWhile(int, int);

void printDowhile(int, int);

int findFirstElementFor(double);

int findFirstElementWhile(double);

int findFirstElementDowhile(double);
```

*Source.cpp*:
```c++
#include <iostream>
#include "Header.h";
using namespace std;

int main() 
{
	setlocale(LC_ALL, "Russian");

	int n, k;
	double eps;

	cout << "Задание №1" << endl << endl;

	cout << "Введите количество итераций: ";
	cin >> n;

	cout << endl << "Вычисление значения суммы ряда (for): "
		<< summNfor(n) << endl;

	cout << "Вычисление значения суммы ряда (while): "
		<< summNwhile(n) << endl;

	cout << "Вычисление значения суммы ряда (do...while): "
		<< summNdowhile(n) << endl << endl;

	cout << "Задание №2" << endl << endl;

	cout << "Введите точность: ";
	cin >> eps;

	cout << endl << "Вычисление значения суммы ряда с точностью: "
		<< eps << " (for) = " << summEpsfor(eps) << endl;

	cout << "Вычисление значения суммы ряда с точностью: "
		<< eps << " (while) = " << summEpswhile(eps) << endl;

	cout << "Вычисление значения суммы ряда с точностью: "
		<< eps << " (do...while) = " << summEpsdowhile(eps) << endl << endl;

	cout << "Задание №3" << endl << endl;

	cout << "Введите n: ";
	cin >> n;
	cout << "Введите k: ";
	cin >> k;

	printFor(n, k);
	cout << endl;
	printWhile(n, k);
	cout << endl;
	printDowhile(n, k);
	cout << endl << endl;

	cout << "Задание №4" << endl << endl;

	cout << "Введите точность: ";
	cin >> eps;

	cout << "Номер первого члена последовательности, для которого "
		<< "выполняется условие |ai| <= eps (for) " << findFirstElementFor(eps)
		<< endl;

	cout << "Номер первого члена последовательности, для которого "
		<< "выполняется условие |ai| <= eps (while) " << findFirstElementWhile(eps)
		<< endl;

	cout << "Номер первого члена последовательности, для которого "
		<< "выполняется условие |ai| <= eps (do...while) " << findFirstElementDowhile(eps)
		<< endl;
}
```

*OperFunc.cpp*:
```c++
#include <cmath>
#include <stdio.h>

// Вычисление регулярного цикла (цикл for)
// @ {int} n - количество итераций
// @ return {double}
double summNfor(int n)
{
	double S = 0;
	for (int i = 0; i < n; i++)
	{
		double a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		S += a;
	}
	return S;
}

// Вычисление регулярного цикла (цикл while)
// @ {int} n - количество итераций
// @ return {double}
double summNwhile(int n)
{
	double S = 0;
	int i = 0;
	while (i < n)
	{
		double a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		S += a;
		i++;
	}
	return S;
}

// Вычисление регулярного цикла (цикл do...while)
// @ {int} n - количество итераций
// @ return {double}
double summNdowhile(int n)
{
	double S = 0;
	int i = 0;
	do
	{
		double a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		S += a;
		i++;
	} while (i < n);
	return S;
}

// Вычисление итерационного цикла с точчностью eps (цикл for)
// @ {double} eps - точность расчёта ряда
// @ return {double}
double summEpsfor(double eps)
{
	double a = -1;
	double S = a;
	for (int i = 2; abs(a) > eps; i++)
	{
		a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		S += a;
	}

	return S;
}

// Вычисление итерационного цикла с точчностью eps (цикл while)
// @ {double} eps - точность расчёта ряда
// @ return {double}
double summEpswhile(double eps)
{
	double a = -1;
	double S = a;
	int i = 2;
	while( abs(a) > eps )
	{
		a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		S += a;
		i++;
	}

	return S;
}

// Вычисление итерационного цикла с точчностью eps (цикл do...while)
// @ {double} eps - точность расчёта ряда
// @ return {double}
double summEpsdowhile(double eps)
{
	double a = -1;
	double S = a;
	int i = 2;
	do
	{
		a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		S += a;
		i++;
	} while (abs(a) > eps);

	return S;
}

// Функция вывода членов последовательности исключая k член (for)
// @ { int } n - количество элементов ряда
// @ { int } k - элемент исключения
void printFor(int n, int k)
{
	for (int i = 0; i < n; i++)
	{
		if (i == k)
			continue;
		double a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		printf("%lf\t", a);
	}
}

// Функция вывода членов последовательности исключая k член (while)
// @ { int } n - количество элементов ряда
// @ { int } k - элемент исключения
void printWhile(int n, int k)
{
	int i = 0;
	while ( i < n )
	{
		if (i == k)
		{
			i++;
			continue;
		}
		double a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		printf("%lf\t", a);
		i++;
	}
}

// Функция вывода членов последовательности исключая k член (do...while)
// @ { int } n - количество элементов ряда
// @ { int } k - элемент исключения
void printDowhile(int n, int k)
{
	int i = 0;
	do
	{
		if (i == k)
		{
			i++;
			continue;
		}
		double a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		printf("%lf\t", a);
		i++;
	} while (i < n);
}

// функция нахождения номера первого члена ряда
// {double} eps - точность
// return {int} - номер члена ряда
int findFirstElementFor(double eps)
{
	double a = -1;
	int s;
	for (int i = 2; abs(a) > eps; i++)
	{
		a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		if (abs(a) > eps)
		{
			s = i;
			break;
		}
	}

	return s;
}

// функция нахождения номера первого члена ряда
// {double} eps - точность
// return {int} - номер члена ряда
int findFirstElementWhile(double eps)
{
	double a = -1;
	int s;
	int i = 2;
	while (abs(a) > eps)
	{
		a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		if (abs(a) > eps)
		{
			s = i;
			break;
		}
		i++;
	}

	return s;
}

// функция нахождения номера первого члена ряда
// {double} eps - точность
// return {int} - номер члена ряда
int findFirstElementDowhile(double eps)
{
	double a = -1;
	int s;
	int i = 2;
	do
	{
		a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		if (abs(a) > eps)
		{
			s = i;
			break;
		}
		i++;
	} while (abs(a) > eps);

	return s;
}
```

## Задание 5

Написать	функцию,	которая	возвращает	номер	первого	отрицательного	члена последовательности {𝑎𝑖}, для которого выполняется условие |𝑎𝑖| ≤ 𝜀.
Функция в качестве параметра принимает значение 𝜀. Выход из цикла организовать с помощью оператора return.
Прототип функции int findFirstNegativeElement(double eps). Функция не должна использовать функции консольного ввода-вывода.

*Header.h*:
```c++
#pragma once

double summNfor(int);

double summNwhile(int);

double summNdowhile(int);

double summEpsfor(double);

double summEpswhile(double);

double summEpsdowhile(double);

void printFor(int, int);

void printWhile(int, int);

void printDowhile(int, int);

int findFirstElementFor(double);

int findFirstElementWhile(double);

int findFirstElementDowhile(double);

int findFirstNegativeElementFor(double);

int findFirstNegativeElementWhile(double);

int findFirstNegativeElementDowhile(double);
```

*Source.cpp*:
```c++
#include <iostream>
#include "Header.h";
using namespace std;

int main() 
{
	setlocale(LC_ALL, "Russian");

	int n, k;
	double eps;

	cout << "Задание №1" << endl << endl;

	cout << "Введите количество итераций: ";
	cin >> n;

	cout << endl << "Вычисление значения суммы ряда (for): "
		<< summNfor(n) << endl;

	cout << "Вычисление значения суммы ряда (while): "
		<< summNwhile(n) << endl;

	cout << "Вычисление значения суммы ряда (do...while): "
		<< summNdowhile(n) << endl << endl;

	cout << "Задание №2" << endl << endl;

	cout << "Введите точность: ";
	cin >> eps;

	cout << endl << "Вычисление значения суммы ряда с точностью: "
		<< eps << " (for) = " << summEpsfor(eps) << endl;

	cout << "Вычисление значения суммы ряда с точностью: "
		<< eps << " (while) = " << summEpswhile(eps) << endl;

	cout << "Вычисление значения суммы ряда с точностью: "
		<< eps << " (do...while) = " << summEpsdowhile(eps) << endl << endl;

	cout << "Задание №3" << endl << endl;

	cout << "Введите n: ";
	cin >> n;
	cout << "Введите k: ";
	cin >> k;

	printFor(n, k);
	cout << endl;
	printWhile(n, k);
	cout << endl;
	printDowhile(n, k);
	cout << endl << endl;

	cout << "Задание №4" << endl << endl;

	cout << "Введите точность: ";
	cin >> eps;

	cout << "Номер первого члена последовательности, для которого "
		<< "выполняется условие |ai| <= eps (for) " << findFirstElementFor(eps)
		<< endl;

	cout << "Номер первого члена последовательности, для которого "
		<< "выполняется условие |ai| <= eps (while) " << findFirstElementWhile(eps)
		<< endl;

	cout << "Номер первого члена последовательности, для которого "
		<< "выполняется условие |ai| <= eps (do...while) " << findFirstElementDowhile(eps)
		<< endl;

	cout << "Задание №5" << endl << endl;

	cout << "Введите точность: ";
	cin >> eps;

	cout << "Номер первого отрицательного члена последовательности, для которого "
		<< "выполняется условие |ai| <= eps (for) " << findFirstNegativeElementFor(eps)
		<< endl;

	cout << "Номер первого отрицательного члена последовательности, для которого "
		<< "выполняется условие |ai| <= eps (while) " << findFirstNegativeElementWhile(eps)
		<< endl;

	cout << "Номер первого отрицательного члена последовательности, для которого "
		<< "выполняется условие |ai| <= eps (do...while) " << findFirstNegativeElementDowhile(eps)
		<< endl;
}
```

*OperFunc.cpp*:
```c++
#include <cmath>
#include <stdio.h>

// Вычисление регулярного цикла (цикл for)
// @ {int} n - количество итераций
// @ return {double}
double summNfor(int n)
{
	double S = 0;
	for (int i = 0; i < n; i++)
	{
		double a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		S += a;
	}
	return S;
}

// Вычисление регулярного цикла (цикл while)
// @ {int} n - количество итераций
// @ return {double}
double summNwhile(int n)
{
	double S = 0;
	int i = 0;
	while (i < n)
	{
		double a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		S += a;
		i++;
	}
	return S;
}

// Вычисление регулярного цикла (цикл do...while)
// @ {int} n - количество итераций
// @ return {double}
double summNdowhile(int n)
{
	double S = 0;
	int i = 0;
	do
	{
		double a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		S += a;
		i++;
	} while (i < n);
	return S;
}

// Вычисление итерационного цикла с точчностью eps (цикл for)
// @ {double} eps - точность расчёта ряда
// @ return {double}
double summEpsfor(double eps)
{
	double a = -1;
	double S = a;
	for (int i = 2; abs(a) > eps; i++)
	{
		a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		S += a;
	}

	return S;
}

// Вычисление итерационного цикла с точчностью eps (цикл while)
// @ {double} eps - точность расчёта ряда
// @ return {double}
double summEpswhile(double eps)
{
	double a = -1;
	double S = a;
	int i = 2;
	while( abs(a) > eps )
	{
		a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		S += a;
		i++;
	}

	return S;
}

// Вычисление итерационного цикла с точчностью eps (цикл do...while)
// @ {double} eps - точность расчёта ряда
// @ return {double}
double summEpsdowhile(double eps)
{
	double a = -1;
	double S = a;
	int i = 2;
	do
	{
		a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		S += a;
		i++;
	} while (abs(a) > eps);

	return S;
}

// Функция вывода членов последовательности исключая k член (for)
// @ { int } n - количество элементов ряда
// @ { int } k - элемент исключения
void printFor(int n, int k)
{
	for (int i = 0; i < n; i++)
	{
		if (i == k)
			continue;
		double a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		printf("%lf\t", a);
	}
}

// Функция вывода членов последовательности исключая k член (while)
// @ { int } n - количество элементов ряда
// @ { int } k - элемент исключения
void printWhile(int n, int k)
{
	int i = 0;
	while ( i < n )
	{
		if (i == k)
		{
			i++;
			continue;
		}
		double a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		printf("%lf\t", a);
		i++;
	}
}

// Функция вывода членов последовательности исключая k член (do...while)
// @ { int } n - количество элементов ряда
// @ { int } k - элемент исключения
void printDowhile(int n, int k)
{
	int i = 0;
	do
	{
		if (i == k)
		{
			i++;
			continue;
		}
		double a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		printf("%lf\t", a);
		i++;
	} while (i < n);
}

// функция нахождения номера первого члена ряда
// {double} eps - точность
// return {int} - номер члена ряда
int findFirstElementFor(double eps)
{
	double a = -1;
	int s;
	for (int i = 2; abs(a) > eps; i++)
	{
		a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		if (abs(a) > eps)
		{
			s = i;
			break;
		}
	}

	return s;
}

// функция нахождения номера первого члена ряда
// {double} eps - точность
// return {int} - номер члена ряда
int findFirstElementWhile(double eps)
{
	double a = -1;
	int s;
	int i = 2;
	while (abs(a) > eps)
	{
		a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		if (abs(a) > eps)
		{
			s = i;
			break;
		}
		i++;
	}

	return s;
}

// функция нахождения номера первого члена ряда
// {double} eps - точность
// return {int} - номер члена ряда
int findFirstElementDowhile(double eps)
{
	double a = -1;
	int s;
	int i = 2;
	do
	{
		a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		if (abs(a) > eps)
		{
			s = i;
			break;
		}
		i++;
	} while (abs(a) > eps);

	return s;
}

// функция, возращающая номер первого отрицательного 
// члена последовательности, для которого выполняется 
// условие |ai| <= eps (for)
// @{double} eps - точность
// return {int}
int findFirstNegativeElementFor(double eps)
{
	double a = -1;
	int s;
	for (int i = 2; abs(a) > eps; i++)
	{
		a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		if (a < 0)
		{
			s = i;
			break;
		}
	}

	return s;
}

// функция, возращающая номер первого отрицательного 
// члена последовательности, для которого выполняется 
// условие |ai| <= eps (while)
// @{double} eps - точность
// return {int}
int findFirstNegativeElementWhile(double eps)
{
	double a = -1;
	int s;
	int i = 2;
	while (abs(a) > eps)
	{
		a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		if (a < 0)
		{
			s = i;
			break;
		}
		i++;
	}

	return s;
}

// функция, возращающая номер первого отрицательного 
// члена последовательности, для которого выполняется 
// условие |ai| <= eps (do...while)
// @{double} eps - точность
// return {int}
int findFirstNegativeElementDowhile(double eps)
{
	double a = -1;
	int s;
	int i = 2;
	do
	{
		a = (pow((-1), i) * (i - 1)) / (2 * pow(i, 2) + 1);
		if (abs(a) > eps)
		{
			s = i;
			break;
		}
		i++;
	} while (a < 0);

	return s;
}
```

## Задание 6

Разработать функцию main(), которая в цикле выводит на экран меню из 6 пунктов и ожидает
ответа пользователя:
	1. Задание 1
	2. Задание 2
	3. Задание 3
	4. Задание 4
	5. Задание 5
	6. Выход
Обработку пользовательского ввода выполнить с помощью оператора switch. При нажатии на соответствующую цифру меню стирается с экрана и приложение переходит в режим демонстрации работы выбранного задания. По завершении демонстрации программа ожидает пользовательского ввода для перехода в меню. Выход из программы должно осуществляться при нажатии цифры 6 в режиме меню. Скомпилировать 3 версии программы:
	* Все функции реализованы с помощью цикла for
	* Все функции реализованы с помощью цикла while
	* Все функции реализованы с помощью цикла do … while 
	Убедиться, что все три версии программы работают одинаково

*Source.cpp*:
```c++
#include <iostream>
#include "Header.h";
using namespace std;

int main() 
{
	setlocale(LC_ALL, "Russian");

	int n, k, r;
	double eps;
	bool sl = true;

	while (sl)
	{
		cout << "Выберите номер задания:" << endl;
		cout << "1. Задание 1" << endl;
		cout << "2. Задание 2" << endl;
		cout << "3. Задание 3" << endl;
		cout << "4. Задание 4" << endl;
		cout << "5. Задание 5" << endl;
		cout << "6. Выход" << endl << endl;

		cout << "Задание: ";
		cin >> r;
		system("cls");

		switch (r)
		{
		case 1:
			cout << "Задание №1" << endl << endl;

			cout << "Введите количество итераций: ";
			cin >> n;

			cout << endl << "Вычисление значения суммы ряда (for): "
				<< summNfor(n) << endl;

			cout << "Вычисление значения суммы ряда (while): "
				<< summNwhile(n) << endl;

			cout << "Вычисление значения суммы ряда (do...while): "
				<< summNdowhile(n) << endl << endl;
			system("pause");
			system("cls");
			break;

		case 2:
			cout << "Задание №2" << endl << endl;

			cout << "Введите точность: ";
			cin >> eps;

			cout << endl << "Вычисление значения суммы ряда с точностью: "
				<< eps << " (for) = " << summEpsfor(eps) << endl;

			cout << "Вычисление значения суммы ряда с точностью: "
				<< eps << " (while) = " << summEpswhile(eps) << endl;

			cout << "Вычисление значения суммы ряда с точностью: "
				<< eps << " (do...while) = " << summEpsdowhile(eps) << endl << endl;
			system("pause");
			system("cls");
			break;

		case 3:
			cout << "Задание №3" << endl << endl;

			cout << "Введите n: ";
			cin >> n;
			cout << "Введите k: ";
			cin >> k;

			printFor(n, k);
			cout << endl;
			printWhile(n, k);
			cout << endl;
			printDowhile(n, k);
			cout << endl << endl;
			system("pause");
			system("cls");
			break;

		case 4:
			cout << "Задание №4" << endl << endl;

			cout << "Введите точность: ";
			cin >> eps;

			cout << "Номер первого члена последовательности, для которого "
				<< "выполняется условие |ai| <= eps (for) " << findFirstElementFor(eps)
				<< endl;

			cout << "Номер первого члена последовательности, для которого "
				<< "выполняется условие |ai| <= eps (while) " << findFirstElementWhile(eps)
				<< endl;

			cout << "Номер первого члена последовательности, для которого "
				<< "выполняется условие |ai| <= eps (do...while) " << findFirstElementDowhile(eps)
				<< endl;
			system("pause");
			system("cls");
			break;

		case 5:
			cout << "Задание №5" << endl << endl;

			cout << "Введите точность: ";
			cin >> eps;

			cout << "Номер первого отрицательного члена последовательности, для которого "
				<< "выполняется условие |ai| <= eps (for) " << findFirstNegativeElementFor(eps)
				<< endl;

			cout << "Номер первого отрицательного члена последовательности, для которого "
				<< "выполняется условие |ai| <= eps (while) " << findFirstNegativeElementWhile(eps)
				<< endl;

			cout << "Номер первого отрицательного члена последовательности, для которого "
				<< "выполняется условие |ai| <= eps (do...while) " << findFirstNegativeElementDowhile(eps)
				<< endl;
			system("pause");
			system("cls");
			break;
		case 6:
			sl = false;
			break;
		}
	}
}
```