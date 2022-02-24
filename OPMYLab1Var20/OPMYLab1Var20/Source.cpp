#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	double x, a, z1, z2, y1, y2;

	cout << "¬ведите значение x: ";
	cin >> x;
	cout << "¬ведите значение a: ";
	cin >> a;
	cout << endl;

	z1 = (sqrt(1 - pow(x, 2)) + 1) / (1 / sqrt(1 + x) + sqrt(1 - x));
	z2 = sqrt(1 + x);
	y1 = 3 - 4 * pow((sin(3 * M_PI / 2 - a)), 2);
	y2 = 4 * cos(M_PI / 6 + a) * cos(M_PI / 6 - a);

	cout << "z1 = " << z1 << endl;
	cout << "z2 = " << z2 << endl;
	cout << "y1 = " << y1 << endl;
	cout << "y2 = " << y2 << endl;

	system("pause");
}