# ИТиП - Лабораторная работа №1

> Вариант 20

* [Цель практикума](#Цель-практикума)
* [Задание 1](#Задание-1)
* [Задание 2](#Задание-2)
* [Задание 3](#Задание-3)
* [Задание 4](#Задание-4)
* [Задание 5](#Задание-5)
* [Задание 6](#Задание-6)
* [Задание 7](#Задание-7)
* [Задание 8](#Задание-8)
* [Задание 9](#Задание-9)

## Цель практикума

Овладеть навыками работы с производными типами данных в языке C++, научиться динамически выделять память

## Задание 1

Написать функцию, которая в качестве параметра получает указатель на целое число и увеличивает его значение на единицу. 
Функция должна осуществлять проверку переданного указателя на нуль.
Перед началом выполнения и перед выходом функция выводит адрес и значение параметра.
Прототип функции void increment(int *n).
Формат вывода: адрес значение адрес значение. 

*Header.h*

```c++
#pragma once

// Значение (через указатель) +1
void increment(int*);
```

*Source.cpp*

```c++
#include <iostream>
#include "Header.h";
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int a = 5; // значение переменной a
	int* pa = &a; // адрес переменной a

	cout << "a = " << a << " адрес a: " << pa << endl;

	increment(&a); // вызов функции

	cout << "a = " << a << " адрес a: " << pa << endl;
}
```

*OperFunc.cpp*

```c++
// Функция получает в качестве параметра указатель на целое число
// и увеличивает его значение на еденицу
void increment(int *n)
{
	*n = ++ * n;
}
```

## Задание 2

Написать функцию, которая создаёт на стеке целое число, осуществляет ввод, выводит на
экран адрес переменной и её значение. Далее вызывает функцию из задания 1, а затем повторно выводит адрес и значение переменной.
Прототип функции void incrementStackVariable().
Формат вывода: адрес значение адрес значение адрес значение адрес значение.

*Header.h*

```c++
// Функция работы со стеком
void incrementStackVariable();
```

*Source.cpp*

```c++
#include <iostream>
#include "Header.h";
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	incrementStackVariable();
}
```

*OperFunc.cpp*

```c++
#include <iostream>
#include <stack>
using namespace std;

// Функция работы со стеком
void incrementStackVariable()
{
	// создание на стеке целого числа
	stack <int> steck;
	int s;
	int* ps;

	cout << "Введите переменную стека: ";
	cin >> s;
	ps = &s;

	cout << "\ns = " << s << " aдрес s: " << ps << endl;

	// добавление значения в стек
	steck.push(s);
	int* psteck = &steck.top();

	cout << "s = " << steck.top() << " aдрес s: " << psteck << endl;

	increment(psteck); // функция из первого задания

	cout << "s = " << steck.top() << " aдрес s: " << psteck << endl;
}
```

## Задание 3

Написать функцию, которая создаёт в динамической памяти целое число, осуществляет ввод, выводит на экран адрес переменной и её значение. Далее вызывает функцию из задания 1, а затем повторно выводит адрес и значение переменной.
Перед выходом из функции необходимо освободить ранее выделенную память.
Прототип функции void incrementHeapVariable().
Формат вывода: адрес значение адрес значение адрес значение адрес значение.

*Header.h*

```c++
// Функция работы с динамической памятью
void incrementHeapVariable();
```

*Source.cpp*

```c++
#include <iostream>
#include "Header.h";
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	incrementHeapVariable();
}
```

*OperFunc.cpp*

```c++
// Функция работы с динамической памятью
void incrementHeapVariable()
{
	// выделение динамической памяти (целое число)
	int* p = (int*)malloc(sizeof(int));

	cout << "p = " << *p << " адрес: " << p << endl;

	cout << "Введите значение: ";
	cin >> *p;

	cout << "p = " << *p << " адрес: " << p << endl;

	increment(p); // функция из первого задания

	cout << "p = " << *p << " адрес: " << p << endl;

	// освобождение выделенной памяти
	free(p);

	cout << "p = " << *p << " адрес: " << p << endl;
}
```

## Задание 4

Написать функцию вывода массива целых чисел на экран.
Функция получает указатель на первый элемент массива и его длину.
Прототип функции void writeArray(int *arr, int n).
Формат вывода: 1 2 3 4 5 6

*Header.h*

```c++
// Функция вывода массива целых чисел на экран
void writeArray(int*, int);
```

*Source.cpp*

```c++
#include <iostream>
#include "Header.h";
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int array[] = { 1, 2, 3, 4, 5, 6 };

	writeArray(array, 6);
}
```

*OperFunc.cpp*

```c++
// Функция вывода массива целых чисел на экран
void writeArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}
```

## Задание 5

Написать функцию ввода массива целых чисел с клавиатуры.
Функция получает указатель на первый элемент массива и его длину.
Прототип функции void readArray(int *arr, int n).

*Header.h*

```c++
// Функция ввода массива целых чисел с клавиатуры
void readArray(int*, int);
```

*Source.cpp*

```c++
#include <iostream>
#include "Header.h";
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int n; // количество элементов массива

	cout << endl << "Введите количество элементов массива: ";
	cin >> n;

	int* arrAdd = new int[n]; // указатель на массив заполнения

	readArray(arrAdd, n);

	// вывод массива из 4 задания
	writeArray(arrAdd, n);
}
```

*OperFunc.cpp*

```c++
// Функция ввода массива целых чисел с клавиатуры
void readArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Введите элемент массива: ";
		cin >> arr[i];
	}

	cout << endl;
}
```

## Задание 6

Написать функцию сортировки массива с использованием алгоритма сортировки, указанном в индивидуальном задании.
Функция должна получать указатель на первый элемент массива и количество элементов в массиве.
Прототип функции void sort(int *arr, int n).
Функция не должна использовать функции консольного ввода-вывода.

*Header.h*

```c++
// Функция сортировки массивов методом "Сортировка вставки"
void sort(int*, int);
```

*Source.cpp*

```c++
#include <iostream>
#include "Header.h";
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	// массив для сортировки (6 задание)
	int arrayRand[] = {-1, -9, 7, 2, 9, 1, -19, 10, 0, 2};

	// вывод исходного массива для проверки работы сортировки
	writeArray(arrayRand, 10);

	// сортировка массива
	sort(arrayRand, 10);

	cout << endl;

	// вывод сортированного массива
	writeArray(arrayRand, 10);
}
```

*OperFunc.cpp*

```c++
// Функция сортировки массивов методом "Сортировка вставки"
void sort(int* arr, int length)
{
	int temp, // временная переменная для хранения значения элемента сортируемого массива
		item; // индекс предыдущего элемента

	// "Сортировка вставками" (начало со второго элемента массива)
	for (int counter = 1; counter < length; counter++)
	{
		temp = arr[counter]; // инициализируем временную переменную текущим значением элемента массива
		item = counter - 1; // запоминаем индекс предыдущего элемента массива

		// пока индекс не равен 0 и предыдущий элемент массива больше текущего
		while (item >= 0 && arr[item] > temp)
		{
			arr[item + 1] = arr[item];  // перестановка элементов массива
			arr[item] = temp;
			item--;
		}
	}
}
```

## Задание 7

Написать функцию, которая создаёт на стеке массив из N элементов (число N определяется константой в коде),
выводит на экран N и с помощью разработанных ранее функций (задания 4-6) осуществляет ввод данных, вывод массива на экран, 
сортировку и повторный вывод отсортированного массива на экран
Прототип функции void sortStackArray(int *arr, int n).
Формат вывода (первая строка – количество элементов массива): 5
5 1 9 7 8
1 5 7 8 9

*Header.h*

```c++
// Функция работы с массивом константой
void sortStackArray(int*, int);
```

*Source.cpp*

```c++
#include <iostream>
#include "Header.h";
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	// массив для сортировки (6-7 задание)
	int arrayRand[] = {-1, -9, 7, 2, 9, 1, -19, 10, 0, 2};

	sortStackArray(arrayRand, 10);
}
```

*OperFunc.cpp*

```c++
// Функция работы с массивом константой
void sortStackArray(int* arr, int n)
{
	// вывод исходного массива (4 задание)
	writeArray(arr, n);

	// сортировка массива (6 задание)
	sort(arr, n);

	cout << endl;

	// вывод сортированного массива (4 задание)
	writeArray(arr, n);
}
```

## Задание 8

Написать функцию, которая создаёт в динамической памяти из N элементов (число N вводится пользователем с клавиатуры),
выводиn n на экран и с помощью разработанных ранее функций (задания 4-6) осуществляет ввод данных, вывод массива на экран, сортировку и повторный

*Header.h*

```c++
// Функция работы с массивом заполняемым пользователем
void sortArrayPerson();
```

*Source.cpp*

```c++
#include <iostream>
#include "Header.h";
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	sortArrayPerson();
}
```

*OperFunc.cpp*

```c++
// Функция работы с массивом заполняемым пользователем
void sortArrayPerson()
{
	int size;
	cout << "Введите размер массива: ";
	cin >> size;

	// создание массива, состоящего из size элементов
	int* arrayPer = new int[size];

	// ввод массива
	readArray(arrayPer, size);

	// очистка консоли
	system("cls");

	// вывод исходного массива
	cout << "Исходный массив:" << endl;

	writeArray(arrayPer, size);

	cout << endl;

	// сортировка введённого массива
	sort(arrayPer, size);

	// вывод сортированного массива
	cout << "Сортированный массив: " << endl;
	
	writeArray(arrayPer, size);

	// освобождение памяти
	delete arrayPer;
}
```

## Задание 9

Разработать функцию main, демонстрирующую работу функций из заданий 2,3,7,8.
Организовать меню и возможность многократной демонстрации заданий.

*Header.h*

```c++
#pragma once

// Значение (через указатель) +1
void increment(int*);

// Функция работы со стеком
void incrementStackVariable();

// Функция работы с динамической памятью
void incrementHeapVariable();

// Функция вывода массива целых чисел на экран
void writeArray(int*, int);

// Функция ввода массива целых чисел с клавиатуры
void readArray(int*, int);

// Функция сортировки массивов методом "Сортировка вставки"
void sort(int*, int);

// Функция работы с массивом константой
void sortStackArray(int*, int);

// Функция работы с массивом заполняемым пользователем
void sortArrayPerson();
```

*Source.cpp*

```c++
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
```

*OperFunc.cpp*

```c++
#include <iostream>
#include <stack>
using namespace std;

// Функция получает в качестве параметра указатель на целое число
// и увеличивает его значение на еденицу
void increment(int *n)
{
	*n = ++ * n;
}

// Функция работы со стеком
void incrementStackVariable()
{
	// создание на стеке целого числа
	stack <int> steck;
	int s;
	int* ps;

	cout << "Введите переменную стека: ";
	cin >> s;
	ps = &s;

	cout << "\ns = " << s << " aдрес s: " << ps << endl;

	// добавление значения в стек
	steck.push(s);
	int* psteck = &steck.top();

	cout << "s = " << steck.top() << " aдрес s: " << psteck << endl;

	increment(psteck); // функция из первого задания

	cout << "s = " << steck.top() << " aдрес s: " << psteck << endl;
}

// Функция работы с динамической памятью
void incrementHeapVariable()
{
	// выделение динамической памяти (целое число)
	int* p = (int*)malloc(sizeof(int));

	cout << "p = " << *p << " адрес: " << p << endl;

	cout << "Введите значение: ";
	cin >> *p;

	cout << "p = " << *p << " адрес: " << p << endl;

	increment(p); // функция из первого задания

	cout << "p = " << *p << " адрес: " << p << endl;

	// освобождение выделенной памяти
	free(p);

	cout << "p = " << *p << " адрес: " << p << endl;
}

// Функция вывода массива целых чисел на экран
void writeArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}

// Функция ввода массива целых чисел с клавиатуры
void readArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Введите элемент массива: ";
		cin >> arr[i];
	}

	cout << endl;
}

// Функция сортировки массивов методом "Сортировка вставки"
void sort(int* arr, int length)
{
	int temp, // временная переменная для хранения значения элемента сортируемого массива
		item; // индекс предыдущего элемента

	// "Сортировка вставками" (начало со второго элемента массива)
	for (int counter = 1; counter < length; counter++)
	{
		temp = arr[counter]; // инициализируем временную переменную текущим значением элемента массива
		item = counter - 1; // запоминаем индекс предыдущего элемента массива

		// пока индекс не равен 0 и предыдущий элемент массива больше текущего
		while (item >= 0 && arr[item] > temp)
		{
			arr[item + 1] = arr[item];  // перестановка элементов массива
			arr[item] = temp;
			item--;
		}
	}
}

// Функция работы с массивом константой
void sortStackArray(int* arr, int n)
{
	// вывод исходного массива
	writeArray(arr, n);

	// сортировка массива
	sort(arr, n);

	cout << endl;

	// вывод сортированного массива
	writeArray(arr, n);
}

// Функция работы с массивом заполняемым пользователем
void sortArrayPerson()
{
	int size;
	cout << "Введите размер массива: ";
	cin >> size;

	// создание массива, состоящего из size элементов
	int* arrayPer = new int[size];

	// ввод массива
	readArray(arrayPer, size);

	// очистка консоли
	system("cls");

	// вывод исходного массива
	cout << "Исходный массив:" << endl;

	writeArray(arrayPer, size);

	cout << endl;

	// сортировка введённого массива
	sort(arrayPer, size);

	// вывод сортированного массива
	cout << "Сортированный массив: " << endl;
	
	writeArray(arrayPer, size);

	// освобождение памяти
	delete arrayPer;
}
```