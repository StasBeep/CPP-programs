#include <iostream>
#include <vector>
#include <fstream>
#define M_PI 3.14159265358979323846
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

void inputArrSignal(vector<float>&, float*, int);
bool write_adc(vector<float>, double);

int main()
{
	float data[64]; // ������ ����������
	vector<float> signalPlot; // ������ ���� ��������
	float signalConstant = 10.06;
	double freq_sampling = 48000.0;
	ofstream outFile;

	// CONST
	for (int i = 0; i < 64; i++)
	{
		data[i] = signalConstant;
	}

	// ������ � ����� ������
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

	// ������ � ����� ������
	inputArrSignal(signalPlot, data, 64);

	// PILA
	control = 0;
	for (int i = 0; i < 64; i++)
	{
		data[i] = (float)1 / 6 * i - control;

		if (i % 6 == 0 && i != 0)
			control++;
	}

	inputArrSignal(signalPlot, data, 128);

	// SIN
	for (int i = 0; i < 64; i++)
	{
		data[i] = sin(float(2 * M_PI * 1600 * i / 48000));
	}

	inputArrSignal(signalPlot, data, 192);

	// ������ � �������� �����
	bool l = write_adc(signalPlot, freq_sampling);
	cout << l << endl;

	// ������ � �������
	outFile.open("file.txt", ios::in);

	for (int i = 0; i < 256; i++)
		outFile << signalPlot[i] << endl;

	outFile.close();

	system("pause");
	return 0;
}

void inputArrSignal(vector<float>& arrSignal, float* arr, int start)
{
	arrSignal.resize(start + 64);

	for (int i = 0; i < 64; i++)
	{
		arrSignal[start] = arr[i];
		start++;
	}
}

bool write_adc(vector<float> data, double freq_sampling)
{
	ADCFILEHEADER head;
	head.Am = 1.0;
	head.h = 32;
	head.dt = 1.0 / freq_sampling;
	head.fN = data.size();
	head.flags = ADCF_DATA_FLOAT;

	const char* FName = "1.adc"; //���� � �����
	float im = 0.0;

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