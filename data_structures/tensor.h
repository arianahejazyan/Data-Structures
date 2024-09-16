#pragma once
#include "utility.h"

namespace Ariana
{

template<typename T>
struct Tensor
{
    private:

        T* elements;
        S* shape;
        S dimension;
};

}; // namespace