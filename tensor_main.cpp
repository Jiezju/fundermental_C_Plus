//
// Created by bright on 2021/5/24.
//
#include <iostream>
#include <vector>
#include "Tensor.h"
using namespace std;

typedef unsigned int uint;

int main()
{
    Tensor t;
    cout<<t.size()<<endl;
    vector<int> v{3,4};
    Tensor t1(v);

    for (uint i = 0; i< t1.size(); ++i)
    {
        cout<< t1[i] <<endl;
    }

    cout<<t1.data(1,1)<<endl;


    return 0;
}