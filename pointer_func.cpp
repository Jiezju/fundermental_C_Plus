#include <iostream>

using namespace std;

int MaxValue(int x, int y)
{
    return (x>y)? x:y;
}

int MinValue(int x, int y)
{
    return (x>y)? y:x;
}

int Add(int x, int y)
{
    return x+y;
}

bool ProcessNum(int x, int y, int (*p)(int a, int b))
{
    cout << (*p)(x, y) << endl;

    return true;
}

int main(int argc, char* argv[])
{
    int x = 10;
    int y = 20;
//    int x = atoi(argv[1]); //  字符转数字
//    int y = atoi(argv[2]);

    ProcessNum(x, y, MaxValue);
    ProcessNum(x, y, MinValue);
    ProcessNum(x, y, Add);

    // func pointer array
    const int len = 3;
    int (*fpt_array[len]) (int, int) = {MaxValue, MinValue, Add};

    for (unsigned int i = 0; i < len; i++)
    {
        int res = fpt_array[i](10,20);
        cout << res << endl;
    }

    return 0;
}
