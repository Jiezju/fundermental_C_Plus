//
// Created by bright on 2021/6/8.
//

#include "Complex.h"

Complex::Complex(double r, double i)
{
    m_real = r;
    m_img = i;
}

Complex::Complex(const Complex &x)
{
    m_real = x.m_real;
    m_img = x.m_img;
}

Complex Complex::operator+(const Complex &x)
{
    Complex tmp;
    tmp.m_real = m_real + x.m_real;
    tmp.m_img = m_img + x.m_img;
    return tmp; // copy
}

Complex& Complex::operator=(const Complex &x) {
    m_real = x.m_real;
    m_img = x.m_img;
    return *this;
}

Complex& Complex::operator++()
{
    Complex tmp;
    tmp.m_img = m_img + 1;
    tmp.m_real = m_real + 1;
    m_real++;
    m_img++;
    return tmp;
}

Complex& Complex::operator++(int)
{
    Complex tmp(*this);
    m_img++;
    m_real++;
    return tmp;
}

ostream& operator<<(ostream& os, const Complex& x)
{
    os<<x.m_real<<x.m_img<<endl;
    return os;
}

istream& operator>>(istream& is, Complex& x)
{
    double r;
    double i;
    is>>r>>i;
    x.m_real = r;
    x.m_img = i;
    return is;
}

int main()
{
    Complex a(1.0,2.0);
    cout<<a<<endl;
    a.setReal(3.0);
    a.setImage(3.0);
    cout<<a<<endl;

    Complex b(0.5, 2.4);

    Complex c;
    c = a + b;
    cout<<c<<endl;

    Complex d(c);

    cout<<c<<endl;

    Complex e = d;
    cout<<e<<endl;

    e.setImage(1.0);
    cout<<d<<endl;

    return 0;
}

