#pragma once
#include <cstddef>

namespace Ariana
{

template<typename T>
struct List // doubly linked list
{
    private:

        struct Node; // nested structure

        Node* m_head;
        Node* m_tail;
        size_t m_size;
    
    public:

        List();

        ~List();

        size_t size() const; // getter method

        bool empty() const;
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

template<typename T>
size_t List<T>::size() const {
    return m_size;
}

template<typename T>
bool List<T>::empty() const {
    return m_size == 0;
}

template<typename T>
struct List<T>::Node
{
    public:

        T data;
        Node* next;
        Node* prev;
};

}; // namespace