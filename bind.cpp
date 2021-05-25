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
        cout<<"foo"<<endl;
    }
};

class Derived:public Base
{
public:
    void foo()
    {
        cout<<"Derived"<<endl;
    }
};

// runtime
class Base1
{
public:
    virtual void foo()
    {
        cout<<"base"<<endl;
    }
};

class Derived1 : public Base1
{
public:
    virtual void foo()
    {
        cout<<"derived"<<endl;
    }
};


int main()
{
    Derived d1;
    Base* b1 = &d1;
    b1->foo(); // Base 静态绑定：子类的函数表中既有父类的foo也有子类的foo，会根据数据类型调用

    Derived1 d2;
    Base1* b2 = &d2;
    b2->foo();

    return 0;
}