#include <iostream>
#include <string>

using namespace std;


int main()
{
    string s0 = "helloworld";
    string s1("helloworldhelloworld");

    // 长度
    cout << s0.length() << endl;
    cout << s0.size() << endl;

    // 比较
    cout << (s1 < s0) << endl;

    string s2 = s0 + s1;
    cout << s2 << endl;

    // string to char
    const char* strs = s2.c_str();
    cout << strs <<endl;


    return 0;
}
