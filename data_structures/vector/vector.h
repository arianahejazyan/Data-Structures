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

        T* begin() const;

        T* end() const;
};

}; /* namespace */

/* ---------------------------------------------------------------------------- */

template<typename T>
size_t Ariana::Vector<T>::capacity() const {

}

template<typename T>
size_t Ariana::Vector<T>::size() const {

}

template<typename T>
T& Ariana::Vector<T>::front() const {

}

template<typename T>
T& Ariana::Vector<T>::back() const {

}

template<typename T>
T* Ariana::Vector<T>::begin() const {

}

template<typename T>
T* Ariana::Vector<T>::end() const {

}

/* ---------------------------------------------------------------------------- */

template<typename T>
class Ariana::Vector<T>::Iterator
{

};

/* ---------------------------------------------------------------------------- */