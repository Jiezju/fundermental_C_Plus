#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

void printString();
void printNum();

int main()
{
    ifstream fileIn("file.txt");
    string userInput;
    getline(fileIn, userInput);

    char copyInput[20] = {'\0'};

    if (userInput.length() < 20)
    {
        strcpy(copyInput, userInput.c_str());
    }

    cout << copyInput << endl;

    fileIn.close();

    printString();
    printNum();

    return 0;
}

void printString()
{
    char str[] = {'a','b','v'};
    for (char ch : str) // C++ 11
    {
        cout << ch << " ";
    }
}

void printNum()
{
    for (auto num : {1,2,3,4,5})
        cout << num << endl;
}
