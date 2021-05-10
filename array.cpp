#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

const int LenNum = 12;

int getNum(const int *a, const int i, const int j, const vector<int>& shape);

int main()
{
    int array[LenNum]={0}; // a[3][4]
    vector<int> shape = {3,4};

    // init
    for(int i=1; i<LenNum; ++i)
    {
        array[i] += array[i-1] + 1;
    }

    cout << getNum(array, 2, 3, shape) << endl;

    return 0;
}

int getNum(const int *a, const int i, const int j, const vector<int>& shape)
{
    assert(i>=0 && i<shape[0]);
    assert(j>=0 && j<shape[1]);

    return a[i*shape[0] + j];

}
