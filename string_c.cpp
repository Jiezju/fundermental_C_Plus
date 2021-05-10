#include <iostream>
#include <string>
#include <string.h>

using namespace std;


int main()
{
    char c = '0';
    char strName[] = "Hello World";

    char* strPtr = "Hello World!";

    // 字符串长度
    int l1 = strlen(strPtr);
    int l2 = strlen(strName);
    cout << l1 << endl;
    cout << l2 << endl;

    // 字符串比较
    int s1 = strcmp(strName, strPtr); // -33
    cout << s1 << endl;

    int s2 = strcmp(strPtr, strName); // 33
    cout << s2 << endl;

    // 字符串复制指定长度
    char* strPtr2 = "hhh";
    strncpy(strName, strPtr2, strlen(strPtr2));

    for (int i=0; i< strlen(strName); ++i)
    {
        cout << strName[i];
    }
    cout << endl;

    // 字符串拼接 危险！ strName太小！！
    char* newcharptr = strcat(strName, strPtr2);

    for (int i=0; i< strlen(strName); ++i)
    {
        cout << newcharptr[i];
    }
    cout << endl;

    // 查找字符
    char* pos = strchr(strPtr2, 'h');
    cout << *pos << endl;


    return 0;
}
