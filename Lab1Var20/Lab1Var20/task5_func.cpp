#include <cmath>

// функция с параметрами (вычисление)
double operation(double x, double y)
{
	return ((x - 1) * sqrt(x) - (y - 1) * sqrt(y)) / (sqrt(pow(x, 3)) * y + x * y + pow(x, 2) - x);;
}