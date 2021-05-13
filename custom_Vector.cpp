//
// Created by bright on 2021/5/13.
//

#include "custom_Vector.h"

custom_Vector::custom_Vector(std::initializer_list<double> lst) :
        elem{new double[lst.size()]},
        sz{static_cast<int>(lst.size())} {
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

int custom_Vector::size() const {
    return sz;
}

double &custom_Vector::operator[](int index) const {
    if (index < sz) {
        return elem[index];
    }
}

