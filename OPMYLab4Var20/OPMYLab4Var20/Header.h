#pragma once
#include <vector>
#include <complex>
using namespace std;

//! ��������� ��������� ����� ��� (ADC)
struct ADCFILEHEADER {
	double dt; //!< ������ ������������� � ��������
	unsigned long h; //!< ����������� ���
	unsigned long fN; //!< ����� ���������� �������� � �����
	float Am; //!< ���������, ��������������� ������������� �������� �������������� �������
	unsigned long flags; //!< �����
	char reserv[8]; //!< ������
};
typedef struct ADCFILEHEADER* LPADCFILEHEADER; //!< ��������� �� ADCFILEHEADER

#define ADCF_DATA_INTEGER 0x00000000 //!< ��� ������ - �������������
#define ADCF_DATA_FLOAT 0x00000001 //!< ��� ������ - float
#define ADCF_TYPE_REAL 0x00000000 //!< ��� �������� - ��������������
#define ADCF_TYPE_COMPLEX 0x00000002 //!< ��� �������� � �����������

bool write_adc(vector<complex<float>>, double);