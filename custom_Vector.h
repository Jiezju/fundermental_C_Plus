//
// Created by bright on 2021/5/13.
//

#ifndef C___CUSTOM_VECTOR_H
#define C___CUSTOM_VECTOR_H
#include <initializer_list>
#include <iostream>

class custom_Vector {
public:
    // 默认构造函数
    custom_Vector():elem{new double(0)},sz{1}{}

    // 构造函数
    custom_Vector(int s): elem{new double [s]}, sz{s} {
        for (unsigned int i = 0; i< s;++i)
        {
            elem[i] = i;
        }
    }

    // 使用initializer_list初始化
    custom_Vector(std::initializer_list<double> lst);

    // 使用外部分配的内存指针
    custom_Vector(double* ptr, int s);

    // 析构函数
    ~custom_Vector();

    // 重载运算符
    double& operator[] (int index) const;

    // 访问私有属性
    int size() const;

private:
    int sz;
    double* elem;

};


#endif //C___CUSTOM_VECTOR_H
