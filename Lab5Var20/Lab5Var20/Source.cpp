#include <iostream>
#include "Header.h";
#include <complex> // Для проверки созданых функций
using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    double re, im;

    // Проверка работоспособности конструкторов
    Complex l;
    cout << l << endl;

    Complex s(7.0);
    cout << s << endl;

    Complex z(1, 2);
    cout << z << endl;

    cout << "Введите комплексные числа\n";
    cout << "Введите действитульную часть 1 числа: ";
    cin >> re;
    cout << "Введите мнимую часть 1 числа: ";
    cin >> im;

    cout << endl;

    Complex Z1(re, im);

    cout << Z1 << endl;
    complex<double> z1(re, im);

    cout << "Введите действитульную часть 2 числа: ";
    cin >> re;
    cout << "Введите мнимую часть 2 числа: ";
    cin >> im;

    cout << endl;

    Complex Z2(re, im);

    cout << Z2 << endl;
    complex<double> z2(re, im);

    // Вывод действительной части комплексного числа
    cout << "Действительная часть: " << Re(Z1) << endl;
    cout << "Проверка: " << z1.real() << endl;

    cout << endl;

    // Вывод мнимой части комплексного числа
    cout << "Мнимая часть: " << Im(Z1) << endl;
    cout << "Проверка: " << z1.imag() << endl;

    cout << endl;

    // Вывод модуля комплексного числа
    cout << "Модуль комплексного числа: " << R(Z1) << endl;
    cout << "Проверка: " << abs(z1) << endl;

    cout << endl;

    // Вывод аргумента комплексного числа
    cout << "Аргумент комплексного числа: " << Phi(Z1) << endl;
    cout << "Проверка: " << arg(z1) << endl;

    cout << endl;

    // Перегрузка операции сложения
    cout << "Сумма комплексных чисел: " << Z1 + Z2;
    cout << "Проверка: " << z1 + z2 << endl;

    cout << endl;

    // Перегрузка операции разности
    cout << "Разность комплексных чисел: " << Z1 - Z2;
    cout << "Проверка: " << z1 - z2 << endl;

    cout << endl;

    // Перегрузка операции произведения
    cout << "Произведение комплексных чисел: " << Z1 * Z2;
    cout << "Проверка: " << z1 * z2 << endl;

    cout << endl;

    // Перегрузка операции частного
    cout << "Частное комплексных чисел: " << Z1 / Z2;
    cout << "Проверка: " << z1 / z2 << endl;

    cout << endl;

    // Расчёт индивидуального задания
    cout << "Результат индивидуального задания: " << y(Z1);

}