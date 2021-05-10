#include <iostream>

using namespace std;

enum Operator
{
    Add = 0,
    Sub,
    Mul,
    Div
};

int main()
{
    int num1 = 1;
    int num2 = 2;
    Operator op = Sub;

    switch(op)
    {
    case Add:
        cout << num1 + num2 << endl;
        break;
    case Sub:
        cout << num1 - num2 << endl;
        break;
    case Mul:
        cout << num1 * num2 << endl;
        break;
    case Div:
        cout << num1 / num2 << endl;
        break;
    }



    return 0;
}
