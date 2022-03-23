#include <iostream>
#include "Header.h";
#include <complex> // ��� �������� �������� �������
using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    double re, im;

    // �������� ����������������� �������������
    Complex l;
    cout << l << endl;

    Complex s(7.0);
    cout << s << endl;

    Complex z(1, 2);
    cout << z << endl;

    cout << "������� ����������� �����\n";
    cout << "������� �������������� ����� 1 �����: ";
    cin >> re;
    cout << "������� ������ ����� 1 �����: ";
    cin >> im;

    cout << endl;

    Complex Z1(re, im);

    cout << Z1 << endl;
    complex<double> z1(re, im);

    cout << "������� �������������� ����� 2 �����: ";
    cin >> re;
    cout << "������� ������ ����� 2 �����: ";
    cin >> im;

    cout << endl;

    Complex Z2(re, im);

    cout << Z2 << endl;
    complex<double> z2(re, im);

    // ����� �������������� ����� ������������ �����
    cout << "�������������� �����: " << Re(Z1) << endl;
    cout << "��������: " << z1.real() << endl;

    cout << endl;

    // ����� ������ ����� ������������ �����
    cout << "������ �����: " << Im(Z1) << endl;
    cout << "��������: " << z1.imag() << endl;

    cout << endl;

    // ����� ������ ������������ �����
    cout << "������ ������������ �����: " << R(Z1) << endl;
    cout << "��������: " << abs(z1) << endl;

    cout << endl;

    // ����� ��������� ������������ �����
    cout << "�������� ������������ �����: " << Phi(Z1) << endl;
    cout << "��������: " << arg(z1) << endl;

    cout << endl;

    // ���������� �������� ��������
    cout << "����� ����������� �����: " << Z1 + Z2;
    cout << "��������: " << z1 + z2 << endl;

    cout << endl;

    // ���������� �������� ��������
    cout << "�������� ����������� �����: " << Z1 - Z2;
    cout << "��������: " << z1 - z2 << endl;

    cout << endl;

    // ���������� �������� ������������
    cout << "������������ ����������� �����: " << Z1 * Z2;
    cout << "��������: " << z1 * z2 << endl;

    cout << endl;

    // ���������� �������� ��������
    cout << "������� ����������� �����: " << Z1 / Z2;
    cout << "��������: " << z1 / z2 << endl;

    cout << endl;

    // ������ ��������������� �������
    cout << "��������� ��������������� �������: " << y(Z1);

}