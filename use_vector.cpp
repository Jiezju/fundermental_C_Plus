//
// Created by bright on 2021/5/17.
//
#include "custom_Vector.h"

int main()
{
    custom_Vector v1 = {1,2,3,4,5};
    std::cout<<v1.size()<<std::endl;
    std::cout<<v1[2]<<std::endl;

    custom_Vector v2(4);
    std::cout<<v2[2]<<std::endl;

    custom_Vector v3;
    std::cout<<v3[0]<<std::endl;

    custom_Vector* vpt = &v1;
    std::cout<<vpt->size()<<std::endl;
    std::cout<<(*vpt)[2]<<std::endl;

    const int numLen = 7;
    double exptr[] = {1,2,3,4,5,6,7};
    custom_Vector exv(exptr, numLen);
    for (unsigned int i = 0; i < 7; ++i)
    {
        std::cout<<exv[i]<<std::endl;
    }

    custom_Vector vcopy(exv);
    for (unsigned int i = 0; i< vcopy.size(); ++i)
    {
        std::cout<<vcopy[i]<<std::endl;
    }

    custom_Vector veq = v1;
    for (unsigned int i = 0; i< veq.size(); ++i) {
        std::cout << veq[i] << std::endl;
    }

    return 0;
}