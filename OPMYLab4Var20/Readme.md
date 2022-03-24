# ОПМУ - Лабораторная работа №4

> Вариант 20

* [Цель практикума](#Цель-практикума)
* [Теоретические сведения](#Теоретические-сведения)
* [Задание](#Задание)
* [Подключение библиотеки .dll](#Подключение-библиотеки-.dll)

## Цель практикума

Классы в С++, использование dll библиотек.

## Теоретические сведения

*Классы*

Классы в программировании состоят из свойств и методов. Свойства — это любые данные, которыми можно характеризовать объект класса.

```c++
//Класс генерации синусоидального сигнала частоты 100 Гц
class SinGen_100Hz {
private:
	float freq = 100.0; // Частота 100 Гц
	float freq_sampling = 48000.0; // Частота дискретизации 48 кГц
	unsigned int size_array; // Размер массива
	std::vector<float> array_sin; // Объект std::vector для отсчетов синусоидального сигнала

public:
	// Конструктор класса SinGen_100Hz
	SinGen_100Hz(unsigned int _size_array)
	{
		size_array = _size_array;
		array_sin.resize(size_array);
	}

	// Функция, для генерации отсчетов sin - Метод класса
	void calculate_sin_array()
	{
		for (int i = 0; i < 5; ++i)
		{
			array_sin[i] = sin(float(2 * M_PI * i * freq / freq_sampling));
		}
	}
	
	// Метод класса, получения расчитанных значений
	std::vector<float> get_sin_array()
	{
		return array_sin;
	}

	// Геттер для получения значения свойства size_array
	unsigned int get_size_array()
	{
		return size_array;
	}

	// Сеттер для установки значения свойства size_array
	void set_size_array(unsigned int _n)
	{
		size_array = _n;
		array_sin.resize(size_array);
	}
};
```

В нашем случае, объектом класса является генератор синусоидального сигнала с частотой 100 Гц, а его свойствами — частота, частота дискретизации,
количество отсчетов для генерации. Методы — это функции, которые могут выполнять какие-либо действия над данными (свойствами) класса. Метод void
calculate_sin_array() рассчитывает отсчеты сигнала по параметрам заданным в свойствах класса. Методы класса – это его функции. Свойства класса – 
это его переменные. Все свойства и методы классов имеют права доступа. По умолчанию, все содержимое класса является доступным для чтения и записи
только для него самого. Для того, чтобы разрешить доступ к данным класса извне, используют модификатор доступа public. Все функции и переменные,
которые находятся после модификатора public, становятся доступными из всех частей программы. Закрытые данные класса размещаются после модификатора
доступа private. Если отсутствует модификатор public, то все функции и переменные, по умолчанию являются закрытыми (как в первом примере).
Конструктор класса — это специальная функция, которая автоматически вызывается сразу после создания объекта этого класса. Он не имеет типа возвращаемого
значения и должен называться также, как класс, в котором он находится. Деструктор класса вызывается при уничтожении объекта. Имя деструктора аналогично
имени конструктора, только в начале ставится знак тильды ~. Деструктор не имеет входных параметров.

Пример использования класса SinGen_100Hz:

```c++
int main()
{
	std::vector<float> data;
	std::vector<float> data1;
	
	// Создание объекта класса SinGen_100Hz
	SinGen_100Hz generator(256);
	
	// Вызываем метод генерации
	generator.calculate_sin_array();
	
	// Вызываем метод получения данных и получаем объект std::vector<float>
	data = generator.get_sin_array();

	// Меняем размер массива для генерации вызывая Сеттер параметра
	generator.set_size_array(512);
	
	// Вызываем метод генерации
	generator.calculate_sin_array();
	
	// Вызываем метод получения данных и получаем объект std::vector<float>
	data1 = generator.get_sin_array();
}
```

При создании объекта, лучше не копировать память для него, а выделять ее в в куче с помощью указателя. И освобождать ее после
того, как мы закончили работу с объектом. Реализуем это в нашей программе, немного изменив содержимое файла main.cpp.

```c++
int main()
{
	std::vector<float> data;
	std::vector<float> data1;
	
	// Выделение памяти для объекта SinGen_100Hz
	SinGen_100Hz *generator = new SinGen_100Hz(256);
	
	// Вызываем метод генерации
	generator->calculate_sin_array();
	
	// Вызываем метод получения данных и получаем объект std::vector<float>
	data = generator->get_sin_array();
	
	// Меняем размер массива для генерации вызывая Сеттер параметра
	generator->set_size_array(512);
	
	// Вызываем метод генерации
	generator->calculate_sin_array();
	
	// Вызываем метод получения данных и получаем объект std::vector<float>
	data1 = generator->get_sin_array();
	
	// Удаление объекта SinGen_100Hz из памяти
	delete generator;
}
```

## Задание

Написать класс, который будет внутри генерировать сигнал, рассчитывать спектр (ДПФ) с использованием библиотеки fftw,
записывать в комплексный файл .adc.
У класса должно быть:
	* конструктор с параметрами по умолчанию (размер БПФ, частота дискретизации);
	* сеттеры и геттеры для параметров из пункта 1;
	* приватный метод генерации сигнала;
	* свойства (члены) класса std::vector для сигнала и результата fftw;
	* публичный метод расчета спектра с использованием fftw;
	* публичный метод для записи результата fftw в файл.
Проверить работоспособность класса, записать файл и построить в Спектр-2.

*Header.h*

```c++
#pragma once
#include <vector>
#include <complex>
using namespace std;

//! Структура заголовка файла АЦП (ADC)
struct ADCFILEHEADER {
	double dt; //!< Период дискретизации в секундах
	unsigned long h; //!< Разрядность АЦП
	unsigned long fN; //!< Общее количество отсчетов в файле
	float Am; //!< Амплитуда, соответствующая максимальному значению целочисленного отсчета
	unsigned long flags; //!< Флаги
	char reserv[8]; //!< Резерв
};
typedef struct ADCFILEHEADER* LPADCFILEHEADER; //!< Указатель на ADCFILEHEADER

#define ADCF_DATA_INTEGER 0x00000000 //!< Тип данных - целочисленные
#define ADCF_DATA_FLOAT 0x00000001 //!< Тип данных - float
#define ADCF_TYPE_REAL 0x00000000 //!< Тип отсчетов - действительные
#define ADCF_TYPE_COMPLEX 0x00000002 //!< Тип отсчетов – комплексные

bool write_adc(vector<complex<float>>, double);
```

*Source.cpp*

```c++
#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <complex>
#include <math.h>
#include <fstream>
#include "Header.h"

#include <fftw3.h> // Подключение библиотеки БПФ
					// (подключается отдельно)

using namespace std;

class SinGen
{
private:
	// параметры варианта для создания сигнала
	int k = 20;
	int N = 46;
	int X = 6;

	// Параметры сигнала
	float f1 = 100 * N;
	float f2 = 512 * k;
	float f3 = 50 * (N + k);
	float A1 = 0.01 * N;
	float A2 = k / 10;
	float A3 = 0.05 * (N + k);
	float Fs = 48000;

	// Размер массива + размер на один сигнал
	int SizeFFT = pow(2, X + 7);

	// Массив для 3 сигналов
	vector<complex<float>> array_sin;

	void generatorSignal()
	{
		for (int i = 0; i < SizeFFT; i++)
			array_sin[i] = pointSignal(A1, f1, i) + pointSignal(A2, f2, i) + pointSignal(A3, f3, i);
	}

	float pointSignal(float _A, float _f, int n)
	{
		return _A * sin(2 * M_PI * n * _f / Fs);
	}

public:
	// Конструктор (без параметров)
	SinGen()
	{
		array_sin.resize(SizeFFT);
	}

	// Геттеры для получения номера варианта (номера списка)
	// размера массива и последнего числа варианта
	int getNumberList()
	{
		return k;
	}

	int getNumberTicket()
	{
		return N;
	}

	int getNumberTicketLast()
	{
		return X;
	}

	int getSizeFFT()
	{
		return SizeFFT;
	}

	// Сеттер для установки нового значения размера массива
	void setNewObject(int _X)
	{
		SizeFFT = pow(2, _X + 7);
		array_sin.resize(SizeFFT);
	}

	// Функция (метод) для работы с БПФ
	vector<complex<float>> outArrayFFT()
	{
		generatorSignal();

		// создаем план для библиотеки fftw
		fftwf_plan plan = fftwf_plan_dft_1d(array_sin.size(), (fftwf_complex*)&array_sin[0], (fftwf_complex*)&array_sin[0], FFTW_FORWARD, FFTW_ESTIMATE);
		fftwf_execute(plan);
		fftwf_destroy_plan(plan);

		return array_sin;
	}
};


int main()
{
	SinGen* generator = new SinGen();
	vector<complex<float>> data;

	data = generator->outArrayFFT();

	bool l = write_adc(data, 48000);
	cout << "l =" << l << endl;
}

bool write_adc(vector<complex<float>> data, double freq_sampling)
{
	ADCFILEHEADER head;
	head.Am = 1.0;
	head.h = 32;
	head.dt = 1.0 / freq_sampling;
	head.fN = data.size();
	head.flags = ADCF_TYPE_COMPLEX | ADCF_DATA_FLOAT;

	const char* FName = "1.adc"; //Путь к файлу

	/*РАБОТА С БИНАРНЫМ ФАЙЛОМ*/
	ofstream out(FName, ios::binary); //Ставим режим "бинарный файл"
	out.write((char*)&head, sizeof(head)); //Записываем в файл структуру заголовка
	for (int i = 0; i < data.size(); ++i)
	{
		out.write((char*)&data[i], sizeof(data[i])); // Записываем действительные отсчеты из вектора
	}
	out.close();
	return true;
}
```

## Подключение библиотеки .dll

Подключение библиотеки на примере FFTW

Для того чтобы подключить библиотеку FFTW к Visual Studio, необходимо:
	1. разархивировать файлы из fftw.zip в любую папку, например D:\fftw

Для того, чтобы использовать библиотеку FFTW, необходимо проделать следующие настройки (пункт меню Project->[имя проекта]Properties):
	1. Выбрать конфигурацию например "Debug"
	2. В разделе “C/C++” -> “Общие” -> “Дополнительные каталоги включаемых файлов” указать путь к папке D:\fftw.
	3. В разделе “Компоновщик” -> “Общие” -> “Дополнительные каталоги библиотек” указать путь к папке D:\fftw.
	4. В разделе “Компоновщик” -> “Ввод” -> “Дополнительные зависимости” указать libfftw3f-3.lib;

!ВАЖНО! Положить библиотеку (файл .dll) около .exe файла программы (Нахождение в Debug). Для того, чтобы программа запускалась из студии
вместе со сторонней библитекой, нужно проделать шаги описанные выше (на примере FFTW), а также положить файлы библиотеки и заголовочные
файлы в корень проекта (может вся библиотке находится в папке), около .sln

Процедура подключения библиотеки описана в .pdf лаборатоной работы, без "важно", но работать программа без "важно" не будет

Библиотека statistic.dll находится в данной директории - нужна для работы с программой spectr2 (для корректной работы программы)
Программа spectr2 находится в корне репозитория CPP-programs