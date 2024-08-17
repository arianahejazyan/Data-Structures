#pragma once
#include <initializer_list>

namespace Ariana {

/* ---------------------------------------------------------------------------- */

template<typename T, size_t N>
struct Array
{
    private:
        T m_elements[N];

    public:

        Array();

        Array(std::initializer_list<T>&& list);

        ~Array();
};

/* ---------------------------------------------------------------------------- */

template<typename T, size_t N>
Array<T, N>::Array() {}

template<typename T, size_t N>
Array<T, N>::Array(std::initializer_list<T>&& list) {
    for (int i = 0; i < list.size(); i++) {
        m_elements[i] = list[i];
    }
}

template<typename T, size_t N>
Array<T, N>::~Array() {}

/* ---------------------------------------------------------------------------- */



/* ---------------------------------------------------------------------------- */

}; /* namespace */