#include <iostream> // ���������� cin cout
#include <cmath> // ���������� �������������� ��������
using namespace std; // ������������ ��� std

// ���������� ������� (�������� �������)
void operation();

// ���������� ���������� ����������
double x, y, result;

int main()
{
	// ����������� �������� �����
	setlocale(LC_ALL, "Russian");

	cout << "task4" << endl << endl;

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

// ������� ��� ���������� (����������)
void operation()
{
	result = ((x - 1) * sqrt(x) - (y - 1) * sqrt(y)) / (sqrt(pow(x, 3)) * y + x * y + pow(x, 2) - x);;
}