#include <iostream>
#include "OperFunc.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	double x, y, result;
	bool goal;
	int k;

	cout << "�������� �������: " << endl;
	cout << "������� 1" << endl;
	cout << "������� 2" << endl << endl;
	cout << "������� ����� �������: ";
	cin >> k;

	switch (k)
	{
	case 1:
		cout << "������� �: ";
		cin >> x;

		cout << "������� y: ";
		cin >> y;

		goal = isInArea(x, y);

		cout << endl;
		cout << "������� ����� � ����? " << goal << endl << endl;
		break;
	case 2:
		cout << "������� x: ";
		cin >> x;

		result = f(x);
		cout << endl;
		cout << "f(x) = " << result << endl;
		break;
	}
}