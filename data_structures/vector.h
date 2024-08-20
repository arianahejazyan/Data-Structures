#pragma once
#include <initializer_list>

/* ---------------------------------------------------------------------------- */

namespace Ariana 
{

template<typename T> // generic structure
struct Vector
{
    private:

        T* m_elements;
        size_t m_capacity;
        size_t m_size;

        class Iterator; // forward declartion

        void allocate();

        void deallocate();

    public:

        Vector();

        Vector(const size_t cap);

        Vector(const std::initializer_list<T>& list);

        Vector(const Ariana::Vector<T>& other);

        ~Vector();

        T& operator[](const size_t index) const;

        Ariana::Vector<T>& operator=(const std::initializer_list<T>& list);

        Ariana::Vector<T>& operator=(const Ariana::Vector<T>& other); // assignment chaining

        void emplace();

        void emplace_back();

        void push_back();

        void pop_back();

        void insert();

        void erase();

        size_t capacity() const;

        size_t size() const;

        T& front() const;

        T& back() const;

        Iterator begin() const;

        Iterator end() const;
};

}; /* namespace */

/* ---------------------------------------------------------------------------- */

template<typename T>
Ariana::Vector<T>::Vector(): m_size(0), m_capacity(1) {
    m_elements = new T[m_capacity];
}

template<typename T>
Ariana::Vector<T>::Vector(const size_t cap): m_size(0), m_capacity(cap) {
    m_elements = new T[m_capacity];
}

template<typename T>
Ariana::Vector<T>::Vector(const std::initializer_list<T>& list): m_size(list.size()), m_capacity(list.size()) {
    m_elements = new T[m_capacity];
    for (int i = 0; i < list.size(); i++) {
        m_elements[i] = list[i];
    }
}

template<typename T>
Ariana::Vector<T>::Vector(const Ariana::Vector<T>& other): m_size(other.size()), m_capacity(other.size()) {
    m_elements = new T[m_capacity];
    for (int i = 0; i < other.size(); i++) {
        m_elements[i] = other[i];
    }
}

template<typename T>
Ariana::Vector<T>::~Vector() {
    delete[] m_elements;
}

template<typename T>
T& Ariana::Vector<T>::operator[](const size_t index) const {
    return *(m_elements + index); // m_elements[index]
}

template<typename T>
Ariana::Vector<T>& Ariana::Vector<T>::operator=(const std::initializer_list<T>& list) {

    return *this;
}

template<typename T>
Ariana::Vector<T>& Ariana::Vector<T>::operator=(const Ariana::Vector<T>& other) {
    if (this != &other) { // self assignment

    }
    return *this;
}

template<typename T>
size_t Ariana::Vector<T>::capacity() const {
    return m_capacity;
}

template<typename T>
size_t Ariana::Vector<T>::size() const {
    return m_size;
}

template<typename T>
T& Ariana::Vector<T>::front() const {
    return m_elements[0];
}

template<typename T>
T& Ariana::Vector<T>::back() const {
    return m_elements[m_size-1];
}

template<typename T>
Ariana::Vector<T>::Iterator Ariana::Vector<T>::begin() const {

}

template<typename T>
Ariana::Vector<T>::Iterator Ariana::Vector<T>::end() const {

}

/* ---------------------------------------------------------------------------- */

template<typename T>
class Ariana::Vector<T>::Iterator
{

};

/* ---------------------------------------------------------------------------- */