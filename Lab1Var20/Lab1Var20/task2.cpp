#include <iostream> // ���������� cin cout
#include <cmath> // ���������� �������������� ��������
using namespace std; // ������������ ��� std

// ������� � ����������� (����������)
double operation(double x, double y) 
{
	return ((x - 1) * sqrt(x) - (y - 1) * sqrt(y)) / (sqrt(pow(x, 3)) * y + x * y + pow(x, 2) - x);;
}


int main()
{
	// ����������� �������� �����
	setlocale(LC_ALL, "Russian");

	int Rx, Ry;
	// ������ ���������� ���� int (��������)
	Rx = 2;
	Ry = 5;

	// �������� ������ (����� ������� ���� double)
	double F, WrX, WrY, Fxy;

	F = operation(Rx, Ry);

	cout << "task2" << endl << endl;

	// ����� ���������� � ���� ��������
	cout << "��� � = " << Rx << " ��� y = " << Ry << " F(x, y) = "
		<< F << endl << endl;

	// ������ ������ � �������
	cout << "������� �: ";
	cin >> WrX;

	cout << "������� y: ";
	cin >> WrY;

	Fxy = operation(WrX, WrY);

	// ����� ����������
	cout << "��� � = " << WrX << " ��� y = " << WrY << " F(x, y) = "
		<< Fxy << endl << endl;
}