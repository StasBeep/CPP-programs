#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <complex>
#include <math.h>
#include <fstream>
#include "Header.h"

#include <fftw3.h> // ����������� ���������� ���
					// (������������ ��������)

using namespace std;

class SinGen
{
private:
	// ��������� �������� ��� �������� �������
	int k = 20;
	int N = 46;
	int X = 6;

	// ��������� �������
	float f1 = 100 * N;
	float f2 = 512 * k;
	float f3 = 50 * (N + k);
	float A1 = 0.01 * N;
	float A2 = k / 10;
	float A3 = 0.05 * (N + k);
	float Fs = 48000;

	// ������ ������� + ������ �� ���� ������
	int SizeFFT = pow(2, X + 7);

	// ������ ��� 3 ��������
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
	// ����������� (��� ����������)
	SinGen()
	{
		array_sin.resize(SizeFFT);
	}

	// ������� ��� ��������� ������ �������� (������ ������)
	// ������� ������� � ���������� ����� ��������
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

	// ������ ��� ��������� ������ �������� ������� �������
	void setNewObject(int _X)
	{
		SizeFFT = pow(2, _X + 7);
		array_sin.resize(SizeFFT);
	}

	// ������� (�����) ��� ������ � ���
	vector<complex<float>> outArrayFFT()
	{
		generatorSignal();

		// ������� ���� ��� ���������� fftw
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

	const char* FName = "1.adc"; //���� � �����

	/*������ � �������� ������*/
	ofstream out(FName, ios::binary); //������ ����� "�������� ����"
	out.write((char*)&head, sizeof(head)); //���������� � ���� ��������� ���������
	for (int i = 0; i < data.size(); ++i)
	{
		out.write((char*)&data[i], sizeof(data[i])); // ���������� �������������� ������� �� �������
	}
	out.close();
	return true;
}