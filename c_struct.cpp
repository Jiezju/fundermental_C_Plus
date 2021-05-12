//
// Created by bright on 2021/5/12.
//

#include <iostream>

using namespace std;

struct Vector
{
    int sz;
    double* elem;
};

void vector_init(Vector& v, const int s)
{
    v.sz = s;
    v.elem = new double[s];

    for (unsigned int i=0; i<s; ++i)
    {
        v.elem[i] = i;
    }
}

void vector_init(Vector* v, const int s)
{
    v->sz = s;
    v->elem = new double [s];
    for (unsigned int i=0; i<s; ++i)
    {
        v->elem[i] = i;
    }
}

double read_and_sum(const Vector& v)
{
    double sum = 0.0;
    for (unsigned int i = 0;i<v.sz;++i)
    {
        sum += v.elem[i];
    }
    return sum;
}

void read_and_sum(const Vector* vpt, double* sumpt)
{
    for (unsigned int i=0; i<vpt->sz; i++)
    {
        *sumpt += vpt->elem[i];
    }
}

int main()
{
    Vector v1;
    vector_init(v1,10);
    Vector v2;
    Vector* v2pt = &v2;
    vector_init(v2pt,10);
    double sum1 = read_and_sum(v1);
    cout<<sum1<<endl;
    double sum2 = 0.0;
    double* sum2pt = &sum2;
    read_and_sum(v2pt, sum2pt);
    cout<<*sum2pt<<endl;

    return 0;
}