//
// Created by bright on 2021/5/20.
//

#include "Tensor.h"
#include <vector>

Tensor::Tensor(unsigned int size)
{
    psize = size;
    pshape.push_back(int(size));
    pelem = new double [size];
}

Tensor::Tensor(std::vector<int>& shape)
{
    psize = 1;
    for (int i: shape)
    {
        psize *= i;
    }

    pelem = new double [psize];
}

Tensor::Tensor(double* ptr, std::vector<int>& shape)
{
    pelem = ptr;
    pshape = shape;
    psize = 1;
    for (int i: shape)
    {
        psize *= i;
    }
}

Tensor::Tensor(double* ptr, unsigned int size)
{
    psize = size;
    pelem = ptr;
    pshape.push_back(int(size));
}

void Tensor::reshape(std::vector<int>& shape)
{
    int tmpsize = 1;
    for (auto i : shape)
    {
        tmpsize *= 1;
    }

    if (tmpsize != psize)
    {
        std::cout<<"Error!"<<std::endl;
    }

    pshape = shape;
}

double& Tensor::operator[](int i)
{
    if (i < psize || i > 0)
        return pelem[i];
}

double Tensor::data(int i, int j) const
{
    if (pshape.size() == 2)
    {
        return pelem[i*pshape[0] + j];
    }
}




