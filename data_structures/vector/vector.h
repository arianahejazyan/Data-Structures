#pragma once
#include <initializer_list>

/* ---------------------------------------------------------------------------- */

namespace Ariana 
{

template<typename T>
struct Vector
{
    private:
        T* m_elements;
        size_t m_capacity;
        size_t m_size;

        class Iterator; // forward declartion

        void expand();

        void shrink();

    public:

        Vector();

        Vector(std::initializer_list);

        ~Vector();

        T& operator[](size_t index) const;

        void operator=(ariana::vector<T>& other);

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