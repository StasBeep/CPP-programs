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
	return (x <= 9 ? cos(2 * x) + 9 : cos(x) - x - 9);
}