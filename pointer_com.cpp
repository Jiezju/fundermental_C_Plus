//
// Created by bright on 2021/5/10.
//

#include <iostream>

using namespace std;

int main() {
    int a = 1, b = 2, c, d;

    c = a++ + b;
    d = a + ++b;

    char ch = 'a';
    char* cp = &ch;

    char* cp2 = ++cp;
    char* cp3 = cp++;
    char* cp4 = --cp;
    char* cp5 = cp--;

    *++cp2 = 98;

    char ch4 = *cp2++;
    char ch5 = ++*++cp;

    return 0;
}