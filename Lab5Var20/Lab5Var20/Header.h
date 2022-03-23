#pragma once
#include <iostream>
using namespace std;

class Complex {
public:

    // ������������
    Complex() : Re(0), Im(0) {}                        // ����������� ��-���������
    Complex(double re) : Re(re), Im(0) {}              // ����������� ��������������
    Complex(double re, double im) : Re(re), Im(im) {}  // ����������� �������������

    // ���������� �������� ������ (�������������)
    friend ostream& operator << (ostream&, Complex);

    // ��������� �������-����� (�������������) �� �������
    friend double Re(Complex); // �������������� �����
    friend double Im(Complex); // ������ �����
    friend double R(Complex);  // ������ ������������ �����
    friend double Phi(Complex); // �������� ������������ �����

    // ���������� �������������� �������� ��� ����������� �����
    friend Complex operator+(Complex, Complex); // �������� �����
    friend Complex operator-(Complex, Complex); // �������� ��������
    friend Complex operator*(Complex, Complex); // �������� ������������
    friend Complex operator/(Complex, Complex); // �������� ��������

    // ������� ���������� ��������������� �������
    friend Complex y(Complex);
    friend double sin(Complex);
    friend double cos(Complex);
    friend double exp(Complex);

private:
    double Re, Im;
};