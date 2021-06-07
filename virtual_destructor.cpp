#include <iostream>

using namespace std;

class Base
{
public:
    Base() {}

    virtual void foo()
    {
        cout<< "Base" << endl;
    }

    virtual ~Base(){}
};

class Derived : public Base
{
public:
    Derived() {}
    virtual void foo()
    {
        cout<< "Derived" << endl;
    }

    virtual ~Derived(){}
};

int main()
{
    Base* b = new Derived; // Derived() -> Base()
    b->foo();
    delete b; // ~Derived() -> ~Base()
}