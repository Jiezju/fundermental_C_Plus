//
// Created by bright on 2021/5/10.
//

#include <iostream>

using namespace std;

void sub(int* pt, unsigned int size)
{
    for (unsigned int i=0; i< size; i++)
    {
        cout << pt[i] - 1<< endl;
    }
}

int main() {

    int* pt = new int;
    if (pt == nullptr)
    {
        return -1;
    }

    *pt = 1;

    int* ptarray = new int[10];

    if (ptarray == nullptr)
    {
        return -1;
    }

    sub(ptarray,10);

    delete pt;

    delete [] ptarray;




    return 0;
}