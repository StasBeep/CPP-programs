#include <cmath>

// ���� � ��������� ������������ ��������

// ������� ��������� � ����
// @{double} x
// @{double} y
// return {bool}
bool isInArea(double x, double y)
{
	if (y <= -x + 1 && y >= 0 && x >= 0)
		return 1;
	if (x <= 0 && y <= 0 && x >= -1 && y >= -1)
		return 1;
	return 0;
}

// ������� ������� �������
// @{double} x
// return {double}
double f(double x)
{
	double res;
	if (x <= 9 ? res = cos(2 * x) + 9 : res = cos(x) - x - 9);
	return res;
}