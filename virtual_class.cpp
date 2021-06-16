//
// Created by bright on 2021/6/16.
//

#include <iostream>
using namespace std;

enum Color
{
    red,
    blue,
    green,
};

class Shape{
public:
    virtual double Area() const = 0;
    virtual void Show() = 0;
    void SetColor(Color color) {m_color = color;}
    void Display()
    {
        cout<<Area()<<endl;
    }

private:
    Color m_color;
};

class Square : public Shape
{
public:
    Square(double len) : m_len{len} {}
    void Show() {cout<<"Square"<<endl;}
    double Area() const
    {
        return m_len*m_len;
    }
private:
    double m_len;
};

class Circle : public Shape
{
public:
    Circle(double radius): m_radius{radius} {}
    void Show() {cout<<"Circle"<<endl;}
    double Area() const
    {
        return m_radius*m_radius*3;
    }
private:
    double m_radius;
};

class Trangle : public Shape
{
public:
    Trangle(double len, double height) : m_len{len} , m_height {height} {}
    void Show() {cout<<"Trangle"<<endl;}
    double Area() const
    {
        return 0.5 * m_len * m_height;
    }
private:
    double m_len;
    double m_height;
};

int main()
{
    const int shapeNum =3;
    Square s1(2.0);
    Color c1 = red;
    s1.SetColor(c1);

    Circle s2(2.0);
    Trangle s3(2.0,3.0);

    Shape* shapes[shapeNum];
    shapes[0] = &s1;
    shapes[1] = &s2;
    shapes[2] = &s3;

    for (unsigned int i=0; i<shapeNum; ++i)
    {
        shapes[i]->Display();
    }

    cout<<sizeof(s1)<<endl;

    return 0;
}