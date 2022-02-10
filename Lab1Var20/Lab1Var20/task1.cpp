#include <iostream> // ���������� cin cout
#include <cmath> // ���������� �������������� ��������
using namespace std; // ������������ ��� std

int main() 
{
	// ����������� �������� �����
	setlocale(LC_ALL, "Russian");

	int Rx, Ry;
	// ������ ���������� ���� int (��������)
	Rx = 2;
	Ry = 5;

	// �������� ������ (����� ������� ���� double)
	double F;

	F = ((Rx - 1) * sqrt(Rx) - (Ry - 1) * sqrt(Ry)) / (sqrt(pow(Rx, 3)) * Ry + Rx * Ry + pow(Rx, 2) - Rx);

	cout << "task1" << endl << endl;

	// ����� ���������� � ���� ��������
	cout << "��� � = " << Rx << " ��� y = " << Ry << " F(x, y) = "
		<< F << endl << endl;

	// ��� ������ ����� �������� ���������� (�������)
	double WrX, WrY, Fxy;

	// ������ ������ � �������
	cout << "������� �: ";
	cin >> WrX;

	cout << "������� y: ";
	cin >> WrY;

	Fxy = ((WrX - 1) * sqrt(WrX) - (WrY - 1) * sqrt(WrY)) / (sqrt(pow(WrX, 3)) * WrY + WrX * WrY + pow(WrX, 2) - WrX);

	// ����� ����������
	cout << "��� � = " << WrX << " ��� y = " << WrY << " F(x, y) = "
		<< Fxy << endl << endl;
}