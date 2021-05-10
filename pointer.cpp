//
// Created by bright on 2021/5/6.
//
#include <iostream>

using namespace std;

typedef long int lint;

template<typename T>
void print_val(T vpt) {
    cout << vpt << std::endl;
    cout << *vpt << std::endl;
}

int main() {
    // 指针定义
    int i = 4;
    int *ipt = &i;
    print_val<int *>(ipt);

    double d = 3.14;
    double *dpt = &d;
    print_val<double *>(dpt);

    char c = 'a';
    char *cpt = &c;
    print_val<char *>(cpt);

    // 数组定义
    lint array[4] = {1, 2, 3, 4};
    int *arraypt[4];
    lint (*ptarray)[4];
    ptarray = &array;

    for (unsigned int i = 0; i < 4; ++i) {
        arraypt[i] = (int *) &(array[i]); // lint -> int
    }

    cout << *(arraypt[0]) << endl;
    cout << (*ptarray)[0] << endl;


    return 0;

}