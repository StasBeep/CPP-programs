#include <cmath>
#include "task7_func.h"

double x, y, result;

// ������� ��� ���������� (����������)
void operation()
{
	result = ((x - 1) * sqrt(x) - (y - 1) * sqrt(y)) / (sqrt(pow(x, 3)) * y + x * y + pow(x, 2) - x);;
}