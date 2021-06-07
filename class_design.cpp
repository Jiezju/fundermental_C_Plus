//
// Created by bright on 2021/6/7.
//
#include <iostream>
#include <vector>
#include <initializer_list>
#include <list>

using namespace std;

// pure virtual class
class Container
{
public:
    virtual double operator[] (int) const = 0;
    virtual int size() const = 0;
    virtual ~Container() {}
};

class Vector_container : public Container
{
public:
    Vector_container(initializer_list<double> lst) : vc{lst} {}

    virtual double operator[](int i) const {return vc[i];}
    virtual int size() const {return vc.size();}
    virtual ~Vector_container() {}
private:
    vector<double> vc;
};

class List_Container : public Container
{
public:
    List_Container() {}
    List_Container(initializer_list<double> li) : lst{li} {}

    virtual double operator[] (int i) const;
    virtual int size() const { return lst.size();}
    virtual ~List_Container() {}

private:
    list<double> lst;
};

double List_Container::operator[] (int i) const
{
    for (auto x : lst)
    {
        if (i==0)
        {
            return x;
        }
        else
        {
            i--;
        }
    }
}

void use(Container& con)
{
    const int sz = con.size();
    for (unsigned int i = 0; i<sz; i++)
    {
        cout<<con[i]<<endl;
    }
}

int main()
{
    Vector_container Vcon{1,2,3,4,4};
    List_Container Lcon{1,1,1,1,1,1};
    use(Vcon);
    use(Lcon);

    return 0;
}

