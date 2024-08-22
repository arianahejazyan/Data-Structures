#pragma once
#include <cstddef>
#include <utility>

namespace Ariana
{

template<typename T>
struct Stack // LIFO
{
    private:
    
        struct Node;

        Node* m_top;
        size_t m_size;
    
    public:

        Stack();

        ~Stack();

        void push(const T& element); // lvalue

        void push(T&& element); // rvalue, move semantices

        void pop();

        T& top() const;

        size_t size() const;

        bool empty() const;
};

template<typename T>
struct Stack<T>::Node
{
    public:

        T data;
        Node* next;

        Node(const T& data): data(data), next(nullptr) {}

        Node(T&& data): data(std::move(data)), next(nullptr) {}

        ~Node() = default;
};

template<typename T>
Stack<T>::Stack(): m_top(nullptr), m_size(0) {}

template<typename T>
Stack<T>::~Stack() {
    while (m_top) {
        Node* tmp = m_top;
        m_top = m_top->next;
        delete tmp;
    }
}

template<typename T>
void Stack<T>::push(const T& element) {
    Node* node = new Node(element);
    node->next = m_top;
    m_top = node;
    m_size++;
}

template<typename T>
void Stack<T>::push(T&& element) {
    Node* node = new Node(std::move(element));
    node->next = m_top;
    m_top = node;
    m_size++;
}

template<typename T>
void Stack<T>::pop() {
    if (m_top) {
        Node* tmp = m_top;
        m_top = m_top->next;
        delete tmp;
        m_size--;
    }
}

template<typename T>
T& Stack<T>::top() const {
    return m_top->data;
}

template<typename T>
size_t Stack<T>::size() const {
    return m_size;
}

template<typename T>
bool Stack<T>::empty() const {
    return m_size == 0;
}

}; // namespace