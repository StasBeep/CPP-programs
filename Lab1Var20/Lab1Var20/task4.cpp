#include <iostream> // библиотека cin cout
#include <cmath> // библиотека математических операций
using namespace std; // пространство имён std

// Объявление функции (прототип функции)
void operation();

// объявление глобальных переменных
double x, y, result;

int main()
{
	// Подключение русского языка
	setlocale(LC_ALL, "Russian");

	cout << "task4" << endl << endl;

	// запрос данных у клиента
	cout << "Введите х: ";
	cin >> x;

	cout << "Введите y: ";
	cin >> y;

	// вызов функции вычисления (без параметров)
	operation();

	// Вывод результата
	cout << "При х = " << x << " при y = " << y << " F(x, y) = "
		<< result << endl << endl;
}

// функция без параметров (вычисление)
void operation()
{
	result = ((x - 1) * sqrt(x) - (y - 1) * sqrt(y)) / (sqrt(pow(x, 3)) * y + x * y + pow(x, 2) - x);;
}