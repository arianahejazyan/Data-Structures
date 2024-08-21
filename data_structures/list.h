#pragma once
#include <cstddef>

namespace Ariana
{

template<typename T>
struct List // doubly linked list
{
    private:

        struct Node;

        Node* m_head;
        Node* m_tail;
        size_t m_size;
};

}; // namespace