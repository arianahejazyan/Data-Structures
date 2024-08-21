#pragma once
#include <cstddef>
#include <utility>

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

        T& front();

        T& back();

        const T& front() const;

        const T& back() const;

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
T& List<T>::front() {
    return m_head->data;
}

template<typename T>
T& List<T>::back() {
    return m_tail->data;
}

template<typename T>
const T& List<T>::front() const {
    return m_head->data;
}

template<typename T>
const T& List<T>::back() const {
    return m_tail->data;
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

        Node(const T& data): data(data), next(nullptr), prev(nullptr) {} // pass by cosnt refence (optimized for lvalue) // copy constructor

        Node(T&& data): data(std::move(data)), next(nullptr), prev(nullptr) {} // pass by rvalue reference (optimized for rvalue) // move constructor

        ~Node() {}
};

}; // namespace