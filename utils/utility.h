#pragma once

namespace Ariana
{
    using S = unsigned long;

    template<typename T>
    void swap(T& a, T& b) {
        T tmp = b;
        b = a;
        a = tmp;
    }
} // namespace



// move (semantics), copy, print, is sorted, memory, forward, size_t


// move
// forward