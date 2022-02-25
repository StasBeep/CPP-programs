#include <iostream>
#include <fstream> // работа с текстовыми файлами с++
#define M_PI 3.14159265358979323846
using namespace std;

void inputArrSignal(double*, double*, int);

int main()
{
	double data[64]; // массив вычислений
	double signalPlot[256]; // массив всех сигналов
	double signalConstant = 10.06;
	ofstream outFile;

	// CONST
	for (int i = 0; i < 64; i++)
	{
		data[i] = signalConstant;
	}

	// запись в общий массив
	inputArrSignal(signalPlot, data, 0);

	// GIT
	int control = 0;
	for (int i = 0; i < 64; i++)
	{
		if (i == 0)
		{
			data[i] = 0;
			data[++i] = 1;
			control++;
		}
		else
		{
			data[i] = 1;
			control++;

			if (control % 6 == 0)
			{
				control = 0;
				data[++i] = 0;
				data[++i] = 0;
			}
		}
	}

	// запись в общий массив
	inputArrSignal(signalPlot, data, 64);

	// PILA
	control = 0;
	for (int i = 0; i < 64; i++)
	{
		data[i] = (double)1 / 6 * i - control;

		if (i % 6 == 0 && i != 0)
			control++;
	}

	inputArrSignal(signalPlot, data, 128);

	// SIN
	for (int i = 0; i < 64; i++)
	{
		data[i] = sin(double (2 * M_PI * 1600 * i / 48000));
	}

	inputArrSignal(signalPlot, data, 192);


	// –абота с файлами
	outFile.open("file.txt", ios::in);

	for (int i = 0; i < 256; i++)
		outFile << signalPlot[i] << endl;

	outFile.close();

	system("pause");
	return 0;
}

void inputArrSignal(double* arrSignal, double* arr, int start)
{
	for (int i = 0; i < 64; i++)
	{
		arrSignal[start] = arr[i];
		start++;
	}
}