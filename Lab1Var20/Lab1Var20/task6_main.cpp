#include <iostream> // ���������� cin cout
#include <cmath> // ���������� �������������� ��������
using namespace std; // ������������ ��� std

// ���������� ������� (�������� �������)
void operation();

int main()
{
	// ����������� �������� �����
	setlocale(LC_ALL, "Russian");

	cout << "task6" << endl << endl;

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