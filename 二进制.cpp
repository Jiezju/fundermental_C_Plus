#include <iostream>
#include <bitset>

using namespace std;


int main()
{
    int num = 3;
    bitset<8> bnum(num);
    bitset<8> _bnum(-3);
    cout << bnum << endl;
    cout << _bnum << endl;
    cout << ~_bnum << endl;
    cout << (bnum & _bnum) << endl;
    cout << (bnum | _bnum) << endl;
    cout << (bnum | _bnum).to_ulong() <<endl;
    cout << (bnum | _bnum).to_string() <<endl;

    return 0;
}
