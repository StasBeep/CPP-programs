#include <iostream> // библиотека cin cout
#include <cmath> // библиотека математических операций
using namespace std; // пространство имён std

// Объявление функции (прототип функции)
void operation();

int main()
{
	// Подключение русского языка
	setlocale(LC_ALL, "Russian");

	cout << "task6" << endl << endl;

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