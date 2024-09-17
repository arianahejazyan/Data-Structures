#pragma once
#include "utility.h"

namespace Ariana
{

template<typename T>
struct Matrix
{
    private:

        T* elements;
        S rows;
        S cols;

    public:

        Matrix(S m, S n);

        ~Matrix();

        T& operator()(S i, S j);

        S getRows() const;

        S getCols() const;
};

template<typename T>
Matrix<T>::Matrix(S m, S n): rows(m), cols(n) {
    elements = new T[rows * cols];
}

template<typename T>
Matrix<T>::~Matrix() {
    delete[] elements;
}

template<typename T>
T& Matrix<T>::operator()(S i, S j) {
    return elements[i * cols + j];
}

template<typename T>
S Matrix<T>::getRows() const {
    return rows;
}

template<typename T>
S Matrix<T>::getCols() const {
    return cols;
}

}; // namespace