#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include "Header.h";
using namespace std;

// "Вывести" нужно испольозвать ostream
ostream& operator << (ostream& stream, Complex c)
{
    stream << c.Re << " + i( " << c.Im << " )" << endl;
    return stream;
}

double Re(Complex c)
{
    return c.Re;
}

double Im(Complex c)
{
    return c.Im;
}

double R(Complex c)
{
    return sqrt(pow(c.Re, 2) + pow(c.Im, 2));
}

double Phi(Complex c)
{
    if (c.Re > 0 && c.Im > 0)
        return atan(c.Im / c.Re);
    else if (c.Re > 0 && c.Im < 0)
        return atan(c.Im / c.Re);
    else if (c.Re < 0 && c.Im < 0)
        return -M_PI + atan(c.Im / c.Re);

    return M_PI + atan(c.Im / c.Re);
}

Complex operator+(Complex x, Complex y)
{
    Complex result;
    result.Re = x.Re + y.Re;
    result.Im = x.Im + y.Im;
    return result;
}

Complex operator-(Complex x, Complex y)
{
    Complex result;
    result.Re = x.Re - y.Re;
    result.Im = x.Im - y.Im;
    return result;
}

Complex operator*(Complex x, Complex y)
{
    Complex result;
    result.Re = x.Re * y.Re - x.Im * y.Im;
    result.Im = x.Re * y.Im + y.Re * x.Im;
    return result;
}

Complex operator/(Complex x, Complex y)
{
    Complex result;
    result.Re = (x.Re * y.Re + x.Im * y.Im) / (pow(y.Re, 2) + pow(y.Im, 2));
    result.Im = (x.Im * y.Re - x.Re * y.Im) / (pow(y.Re, 2) + pow(y.Im, 2));
    return result;
}

Complex y(Complex z)
{
    Complex s = z;
    s.Re = 2 + 3 * sin(z) * exp(z);
    s.Im = 3 * exp(z) * cos(z);
    return s;
}

double sin(Complex z)
{
    return sin(z.Im);
}

double cos(Complex z)
{
    return cos(z.Im);
}

double exp(Complex z)
{
    return 1 / exp(z.Re);
}