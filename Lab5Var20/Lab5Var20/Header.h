#pragma once
#include <iostream>
using namespace std;

class Complex {
public:

    // Конструкторы
    Complex() : Re(0), Im(0) {}                        // конструктор по-умолчанию
    Complex(double re) : Re(re), Im(0) {}              // конструктор преобразования
    Complex(double re, double im) : Re(re), Im(im) {}  // конструктор инициализации

    // Перегрузка операции вывода (дружественная)
    friend ostream& operator << (ostream&, Complex);

    // Публичные функции-члены (дружественные) по заданию
    friend double Re(Complex); // Действительная часть
    friend double Im(Complex); // Мнимая часть
    friend double R(Complex);  // Молуль комплексного числа
    friend double Phi(Complex); // Аргумент комплексного числа

    // Перегрузка математических операций для комплексных чисел
    friend Complex operator+(Complex, Complex); // Операция суммы
    friend Complex operator-(Complex, Complex); // Операция разности
    friend Complex operator*(Complex, Complex); // Операция произведения
    friend Complex operator/(Complex, Complex); // Операция частного

    // Функция выполнения индивидуального задания
    friend Complex y(Complex);
    friend double sin(Complex);
    friend double cos(Complex);
    friend double exp(Complex);

private:
    double Re, Im;
};