//
// Created by bright on 2021/5/7.
//
#include <iostream>
#include <string.h>

using namespace std;

unsigned int MaxLen = 11;

char* strfunc(const char* str, const unsigned int& len)
{
    char* newptr = new char[len];

    for (unsigned int i = 0; i< len; ++i)
    {
        newptr[i] = str[i] + 1;
    }
    return newptr;
}

int main()
{
    char strHello[] = "helloworld";

    char* strHelloptr = "afdsfdsfa";

    // const char
    const char* constchar = "adfsfa";

    // const ptr to char
    char* const const_ptr = strHello;

    unsigned int len = strnlen(const_ptr, MaxLen);
    cout << len << endl;

    for (unsigned int i = 0; i < len; i++)
    {
        const_ptr[i] += 1;
        cout << const_ptr[i] << endl;
    }

     // const_ptr = strHelloptr;

     // pointer param in func
     char* printptr = strfunc(const_ptr, len);

    for (unsigned int i = 0; i < len; ++i)
    {
        cout<<printptr[i]<<endl;
    }


    return 0;
}