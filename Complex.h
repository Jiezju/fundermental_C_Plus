//
// Created by bright on 2021/6/8.
//

#ifndef C___COMPLEX_H
#define C___COMPLEX_H
#include <iostream>
using namespace std;

class Complex{
public:
    Complex() : m_real{0.0}, m_img{0.0} {}
    Complex(double r, double i);
    virtual ~Complex() {}

    // copy
    Complex(const Complex& x);

    // get attr
    double getReal() const {return m_real;}
    double getImage() const {return m_img;}

    // set attr
    void setReal(double r) {m_real = r;}
    void setImage(double i) {m_img = i;}

    // operator
    Complex operator+(const Complex& x);
    Complex& operator=(const Complex& x);

    Complex& operator++(); // pre
    Complex& operator++(int); // post

    // print
    friend ostream& operator<<(ostream& os, const Complex& x);
    friend istream& operator>>(istream& is, Complex& x);


private:
    double m_real;
    double m_img;
};


#endif //C___COMPLEX_H
