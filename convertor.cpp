//
// Created by bright on 2021/6/17.
//
#include <iostream>
using namespace std;

class Base
{
public:
    Base(): m_i{0} {;}
    virtual void T()
    {
        cout<< "Base:"<<m_i<<endl;
    }

private:
    int m_i;
};

class Derived : public Base
{
public:
    Derived() : m_j{0} {}
    virtual void T()
    {
        cout<<"Derived:"<<endl;
    }

private:
    int m_j;
};


int Test()
{
    return 0;
}

typedef void(*FuncPtr) ();

int main()
{
    // const cast
    const int a = 10;
    int* pa = const_cast<int*>(&a);
    // *pa = 100;
    cout<<a<<endl;
    cout<<*pa<<endl;

    // reinterpret_cast
    FuncPtr funcPtr;
    funcPtr = reinterpret_cast<FuncPtr>(&Test);

    int i = 6;
    double d = static_cast<double>(i);
    cout<<d<<endl;

    // dynamic_cast
    Base cb;
    Derived cd;
    Base* pcb;
    Derived* pcd;

    // derived -> base
    pcb = static_cast<Base*>(&cd);
    if (pcb == nullptr)
    {
        cout << "unsafe dynamic_cast from Derived to Base" << endl;
    }

    pcb = dynamic_cast<Base*>(&cd);
    if (pcb == nullptr)
    {
        cout << "unsafe dynamic_cast from Derived to Base" << endl;
    }

    // 父类-->子类
    pcd = static_cast<Derived*>(&cb);
    if (pcd == NULL)
    {
        cout << "unsafe dynamic_cast from Derived to Base" << endl;
    }
    pcd = dynamic_cast<Derived*>(&cb);
    if (pcd== NULL)
    {
        cout << "unsafe dynamic_cast from Derived to Base" << endl;
    }


    return 0;
}