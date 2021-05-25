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

class Derived: public Base
{
public:
    void doo()
    {
        cout<<"doo"<<endl;
    }
};

class Derived_p : private Base
{
public:
    void poo()
    {
        cout<<"poo"<<endl;
    }
};

class Derived_ex : private Base
{
public:
    void ex()
    {
       foo();
    }
};

int main()
{
    Derived d;
    d.foo();

    Derived_p dp;
    // dp.foo(); 公有函数变为子类私有，不可访问

    Derived_ex dpex;
    dpex.ex();

    return 0;
}