#include <iostream> // библиотека cin cout
#include <cmath> // библиотека математических операций
using namespace std; // пространство имён std

// Объявление функции (прототип функции)
// P.S. в прототипе не указывается переменные,
// а указывается только тип переменной
double operation(double, double);

int main()
{
	// Подключение русского языка
	setlocale(LC_ALL, "Russian");

	int Rx, Ry;
	// задача переменных типа int (констант)
	Rx = 2;
	Ry = 5;

	// выходные данные (ответ функции типа double)
	double F, WrX, WrY, Fxy;

	F = operation(Rx, Ry);

	cout << "task5" << endl << endl;

	// Вывод результата в виде констант
	cout << "При х = " << Rx << " при y = " << Ry << " F(x, y) = "
		<< F << endl << endl;

	// запрос данных у клиента
	cout << "Введите х: ";
	cin >> WrX;

	cout << "Введите y: ";
	cin >> WrY;

	Fxy = operation(WrX, WrY);

	// Вывод результата
	cout << "При х = " << WrX << " при y = " << WrY << " F(x, y) = "
		<< Fxy << endl << endl;
}