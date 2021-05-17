//
// Created by bright on 2021/5/13.
//

#include "custom_Vector.h"

custom_Vector::custom_Vector(std::initializer_list<double> lst) :
        elem{new double[lst.size()]},
        sz{static_cast<unsigned int>(lst.size())} {
    std::copy(lst.begin(), lst.end(), elem);
}

custom_Vector::custom_Vector(double *ptr, int s) {
    if (ptr == nullptr) {
        std::cout << "Empty pointer!" << std::endl;
        custom_Vector();
    } else {
        elem = new double[s];
        sz = s;
        for (unsigned int i = 0; i < s; ++i) {
            elem[i] = ptr[i];
        }
        ptr = nullptr;
    }
}

custom_Vector::~custom_Vector() {
    delete[] elem;
    sz = 0;
}

unsigned int custom_Vector::size() const {
    return sz;
}

double &custom_Vector::operator[](int index) const {
    if (index < sz) {
        return elem[index];
    }
}

custom_Vector::custom_Vector(const custom_Vector& vec): elem{new double [vec.size()]}, sz{vec.size()}
{
    for (unsigned int i = 0; i< sz; ++i)
    {
        elem[i] = vec[i];
    }
}

custom_Vector & custom_Vector::operator=(const custom_Vector &vec)
{
    double* p = new double [vec.sz];
    sz = vec.sz;

    for (unsigned int i = 0; i<vec.sz; ++i)
    {
        p[i] = vec[i];
    }
    delete [] elem;
    elem = p;

    return *this;
}

