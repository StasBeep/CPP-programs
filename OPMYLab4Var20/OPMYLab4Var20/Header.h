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