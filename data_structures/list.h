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
    
    public:

        List();

        ~List();
};

template<typename T>
List<T>::List(): m_head(nullptr), m_tail(nullptr), m_size(0) {}

template<typename T>
List<T>::~List() {
    while (m_head) {
        Node* tmp = m_head;
        m_head = m_head->next;
        delete tmp;
    }
}

}; // namespace