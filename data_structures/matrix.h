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

        T& operator()(size_t i, size_t j) const;
};

template<typename T>
Matrix<T>::Matrix(size_t rows, size_t cols): m_rows(rows), m_cols(cols) {
    m_elements = new T[m_rows * m_cols];
}

template<typename T>
Matrix<T>::~Matrix() {
    delete[] m_elements;
}

template<typename T>
T& Matrix<T>::operator()(size_t i, size_t j) const {
    return m_elements[i * m_cols + j];
}

}; // namespace