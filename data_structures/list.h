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

        void push_front(T elemenet);

        void push_back(T element);

        void pop_front();

        void pop_back();

        T& front();

        T& back();

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
void List<T>::push_front(T element) {
    Node* node = new Node(element);

    if (m_head) {
        node->next = m_head;
        m_head->prev = node;
    } else {
        m_tail = node;
    }

    m_head = node;
    ++m_size;
}

template<typename T>
void List<T>::push_back(T element) {
    Node* node = new Node(element);

    if (m_tail) {
        node->prev = m_tail;
        m_tail->next = node;
    } else {
        m_head = node;
    }

    m_tail = node;
    ++m_size;
}

template<typename T>
void List<T>::pop_front() {
    if (m_head) {
        Node* tmp = m_head;
        m_head = m_head->next;

        if (m_head) m_head->prev = nullptr;
        else m_tail = nullptr;

        delete tmp;
        --m_size;
    }
}

template<typename T>
void List<T>::pop_back() {
    if (m_tail) {
        Node* tmp = m_tail;
        m_tail = m_tail->prev;

        if (m_tail) m_tail->next = nullptr;
        else m_head = nullptr;

        delete tmp;
        --m_size;
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