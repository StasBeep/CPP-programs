#include <iostream> // ���������� cin cout
#include <cmath> // ���������� �������������� ��������
using namespace std; // ������������ ��� std

// ���������� ������� (�������� �������)
// P.S. � ��������� �� ����������� ����������,
// � ����������� ������ ��� ����������
double operation(double, double);

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

	cout << "task5" << endl << endl;

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