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