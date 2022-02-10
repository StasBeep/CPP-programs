#include <cmath>
#include <stdio.h>

// ���������� ����������� ����� (���� for)
// @ {int} n - ���������� ��������
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

// ���������� ����������� ����� (���� while)
// @ {int} n - ���������� ��������
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

// ���������� ����������� ����� (���� do...while)
// @ {int} n - ���������� ��������
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

// ���������� ������������� ����� � ���������� eps (���� for)
// @ {double} eps - �������� ������� ����
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

// ���������� ������������� ����� � ���������� eps (���� while)
// @ {double} eps - �������� ������� ����
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

// ���������� ������������� ����� � ���������� eps (���� do...while)
// @ {double} eps - �������� ������� ����
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

// ������� ������ ������ ������������������ �������� k ���� (for)
// @ { int } n - ���������� ��������� ����
// @ { int } k - ������� ����������
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

// ������� ������ ������ ������������������ �������� k ���� (while)
// @ { int } n - ���������� ��������� ����
// @ { int } k - ������� ����������
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

// ������� ������ ������ ������������������ �������� k ���� (do...while)
// @ { int } n - ���������� ��������� ����
// @ { int } k - ������� ����������
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

// ������� ���������� ������ ������� ����� ����
// {double} eps - ��������
// return {int} - ����� ����� ����
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

// ������� ���������� ������ ������� ����� ����
// {double} eps - ��������
// return {int} - ����� ����� ����
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

// ������� ���������� ������ ������� ����� ����
// {double} eps - ��������
// return {int} - ����� ����� ����
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

// �������, ����������� ����� ������� �������������� 
// ����� ������������������, ��� �������� ����������� 
// ������� |ai| <= eps (for)
// @{double} eps - ��������
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

// �������, ����������� ����� ������� �������������� 
// ����� ������������������, ��� �������� ����������� 
// ������� |ai| <= eps (while)
// @{double} eps - ��������
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

// �������, ����������� ����� ������� �������������� 
// ����� ������������������, ��� �������� ����������� 
// ������� |ai| <= eps (do...while)
// @{double} eps - ��������
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