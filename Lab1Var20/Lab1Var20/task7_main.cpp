#include <iostream> // ���������� cin cout
#include <cmath> // ���������� �������������� ��������
#include "task7_func.h";
using namespace std; // ������������ ��� std

int main()
{
	// ����������� �������� �����
	setlocale(LC_ALL, "Russian");

	cout << "task7" << endl << endl;

	// ������ ������ � �������
	cout << "������� �: ";
	cin >> x;

	cout << "������� y: ";
	cin >> y;

	// ����� ������� ���������� (��� ����������)
	operation();

	// ����� ����������
	cout << "��� � = " << x << " ��� y = " << y << " F(x, y) = "
		<< result << endl << endl;
}