//
// Created by bright on 2021/5/25.
//
#include <iostream>

using namespace std;

class Base
{
public:
    void foo()
    {
        cout<<"base foo"<<endl;
    }
};

class Derived : public Base
{
public:
    void foo()
    {
        cout<<"derived foo"<<endl;
    }
};

int main()
{
    Base b1;
    b1.foo();

    Derived d1;
    d1.foo();

    return 0 ;
}
