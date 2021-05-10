#include <iostream>
#include <string.h>

using namespace std;

struct Student1
{
    char tex[2];
    int age;
    double score;
};

struct Student2
{
    double score;
    char tex[2];
    int age;
};

struct Student3
{
    char tex[2];
    double score;
    int age;
};

int main()
{
    Student1 stu1;
    Student2 stu2;
    Student3 stu3;
    Student3* stu4ptr = &stu3;
    strcpy(stu1.tex, "1");
    stu1.age = 10;
    stu1.score = 10.0;
    cout << stu1.tex << endl;
    cout << stu1.age << endl;
    cout << stu1.score << endl;
    cout << sizeof(stu1) << endl;
    cout << sizeof(stu2) << endl;
    cout << sizeof(stu3) << endl;

    strcpy(stu4ptr->tex, "0");
    stu4ptr->age = 11;
    stu4ptr->score = 11.0;
    cout << stu4ptr->tex << endl;
    cout << stu4ptr->age << endl;
    cout << stu4ptr->score << endl;
    
    return 0;
}
