#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

int printVector(vector<int> v)
{
    for (int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<' ';
    }
    cout << endl;

    return 0;
}

int main()
{
    vector<int> v = {0,1,2,3};
    // end add
    v.push_back(2);
    printVector(v);

    // insert
    v.insert(--v.end(),3);
    printVector(v);

    // mid delete
    vector<int>::iterator iter = v.begin();
    int pos = 0;
    for(; iter != v.end(); iter++)
    {
        pos += 1;
        if (pos == 2)
        {
            v.erase(iter);
        }
    }

    printVector(v);

    // end delete
    v.erase(--v.end());
    printVector(v);

    // end delete
    v.pop_back();
    printVector(v);

    // head delete
    v.erase(v.begin());
    printVector(v);


    return 0;
}

