#include <iostream> // библиотека cin cout
#include <cmath> // библиотека математических операций
using namespace std; // пространство имён std

int main() 
{
	// Подключение русского языка
	setlocale(LC_ALL, "Russian");

	int Rx, Ry;
	// задача переменных типа int (констант)
	Rx = 2;
	Ry = 5;

	// выходные данные (ответ функции типа double)
	double F;

	F = ((Rx - 1) * sqrt(Rx) - (Ry - 1) * sqrt(Ry)) / (sqrt(pow(Rx, 3)) * Ry + Rx * Ry + pow(Rx, 2) - Rx);

	cout << "task1" << endl << endl;

	// Вывод результата в виде констант
	cout << "При х = " << Rx << " при y = " << Ry << " F(x, y) = "
		<< F << endl << endl;

	// для записи новых значений переменных (вручную)
	double WrX, WrY, Fxy;

	// запрос данных у клиента
	cout << "Введите х: ";
	cin >> WrX;

	cout << "Введите y: ";
	cin >> WrY;

	Fxy = ((WrX - 1) * sqrt(WrX) - (WrY - 1) * sqrt(WrY)) / (sqrt(pow(WrX, 3)) * WrY + WrX * WrY + pow(WrX, 2) - WrX);

	// Вывод результата
	cout << "При х = " << WrX << " при y = " << WrY << " F(x, y) = "
		<< Fxy << endl << endl;
}