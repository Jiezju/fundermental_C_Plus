//
// Created by bright on 2021/5/20.
//

#ifndef C___TENSOR_H
#define C___TENSOR_H

#include <iostream>
#include <vector>

class Tensor {
public:
    Tensor():pshape{1}, psize{1}, pelem{new double(0)} {};
    explicit Tensor(unsigned int size);
    explicit Tensor(std::vector<int>& shape);
    Tensor(double* ptr, std::vector<int>& shape);
    Tensor(double* ptr, unsigned int size);

    std::vector<int> shape() const {return pshape;}
    unsigned int size() const {return psize;}

    void reshape(std::vector<int>& shape);

    double& operator[] (int i);

    double data(int i, int j) const;

    //    Tensor& operator=(const Tensor& t);
    Tensor& operator=(Tensor&& t);

    friend double* print_ptr(Tensor t);


    ~Tensor()
    {
        psize = 0;
        pelem = nullptr;
    }



private:
    std::vector<int> pshape;
    unsigned int psize;
    double* pelem;

};


#endif //C___TENSOR_H
