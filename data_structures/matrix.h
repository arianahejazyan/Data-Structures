#pragma once
#include <cstddef>

namespace Ariana
{

template<typename T>
struct Matrix
{
    private:

        T* m_elements;
        size_t m_rows;
        size_t m_cols;

    public:

        Matrix(size_t rows, size_t cols);

        ~Matrix();
};

template<typename T>
Matrix<T>::Matrix(size_t rows, size_t cols): m_rows(rows), m_cols(cols) {
    m_elements = new T[m_rows * m_cols];
}

template<typename T>
Matrix<T>::~Matrix() {
    delete[] m_elements;
}

}; // namespace