#pragma once
#include <cstddef>
#include <initializer_list>

namespace Ariana {

/* ---------------------------------------------------------------------------- */

template<typename T, std::size_t N>
struct Array
{
    using reference = T&; // type alias
    using const_reference = const T&; // default access is public

    private: // access specifier

        T m_elements[N]; // member variable

    public:

        Array(); // default constructor

        Array(std::initializer_list<T>&& list);

        ~Array(); // default deconstructor

        reference operator[](std::size_t n); // random access

        const_reference operator[](std::size_t n) const; // const version of subscript (indexing) operator
};

/* ---------------------------------------------------------------------------- */

template<typename T, std::size_t N>
Array<T, N>::Array() {}

template<typename T, std::size_t N>
Array<T, N>::Array(std::initializer_list<T>&& list) {
    for (int i = 0; i < list.size(); i++) {
        m_elements[i] = list[i];
    }
}

template<typename T, std::size_t N>
Array<T, N>::~Array() {}

template<typename T, std::size_t N>
T& Array<T, N>::operator[](std::size_t n) {
    return m_elements[n]; // Overloading the [] operator to return a reference to the element
}

template<typename T, std::size_t N>
const T& Array<T, N>::operator[](std::size_t n) const {
    return m_elements[n];
}

/* ---------------------------------------------------------------------------- */



/* ---------------------------------------------------------------------------- */

}; /* namespace */