#pragma once
#include <cstddef>
#include <initializer_list>

namespace Ariana
{

template<typename T>
struct Array
{
    using reference = T&;
    using const_reference = const T&;

    private:

        T* m_elements;
        size_t m_capacity;
        size_t m_size;

        class Iterator;
        class CIterator;

        void allocate();

        void deallocate();

    public:

        Array();

        Array(std::initializer_list<T>&& list);

        Array(const Array<T>& other);

        Array(Array<T>&& other) noexcept;

        ~Array();

        reference operator[](std::size_t n);

        const_reference operator[](std::size_t n) const;

        Array<T>& operator=(const Array<T>& other);

        template<typename... Args>
        void emplace_back(Args&&... args);

        void push_back(const T& element);

        void push_back(T&& element);

        void pop_back();

        size_t capacity() const;

        size_t size() const;

        Iterator begin();

        Iterator end();
};

template<typename T>
Array<T>::Array(): m_size(0), m_capacity(1) {
    m_elements = new T[m_capacity];
}

template<typename T>
Array<T>::Array(std::initializer_list<T>&& list): m_size(list.size()), m_capacity(list.size()) {
    m_elements = new T[m_capacity];
    for (int i = 0; i < list.size(); i++) {
        m_elements[i] = list[i];
    }
}

template<typename T>
Array<T>::Array(const Array<T>& other): m_size(other.size()), m_capacity(other.size()) {
    m_elements = new T[m_capacity];
    for (int i = 0; i < other.size(); i++) {
        m_elements[i] = other[i];
    }
}

template<typename T>
Matrix<T>::Matrix(Matrix<T>&& other) noexcept: rows(other.rows), cols(other.cols), data(other.data) {
    other.data = nullptr;
}


template<typename T>
Array<T>::~Array() {
    delete[] m_elements;
}

template<typename T>
T& Array<T>::operator[](size_t index) {
    return *(m_elements + index);
}

template<typename T>
const T& Array<T>::operator[](size_t index) const {
    return m_elements[index];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {

    }
    return *this;
}

template<typename T>
size_t Array<T>::capacity() const {
    return m_capacity;
}

template<typename T>
size_t Array<T>::size() const {
    return m_size;
}

template<typename T>
typename Array<T>::Iterator Array<T>::begin() {
    return Iterator(m_elements);
}

template<typename T>
typename Array<T>::Iterator Array<T>::end() {
    return Iterator(m_elements + m_size);
}

template<typename T>
class Array<T>::Iterator
{
    private:

        T* ptr;
    
    public:

        Iterator(T* p): ptr(p) {}

        T& operator*() const {
            return *ptr;
        }

        T* operator->() {
            return ptr;
        }

        Iterator& operator++() {
            ++ptr;
            return *this;
        }

        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        friend bool operator!=(const Iterator& a, const Iterator& b) {
            return a.ptr != b.ptr;
        }
};

}; // namespace