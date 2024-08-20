#pragma once

namespace Ariana {

/* ---------------------------------------------------------------------------- */

template<typename T>
struct Stack
{
    private:
        struct Node;

        Node* m_head;
        std::size_t m_size;
    
    public:

        Stack();

        ~Stack();

        template<typename... Args>
        void emplace(Args&&... args);

        void push(const T& element); // lvalue

        void push(T&& element); // rvalue, move semantices

        void pop();

        T& top() const;

        size_t size() const;

        bool empty() const;
};

/* ---------------------------------------------------------------------------- */

template<typename T>
Stack<T>::Stack(): m_head(nullptr), m_size(0) {}

template<typename T>
Stack<T>::~Stack() {
    while (m_head) {
        Node* tmp = m_head;
        m_head = m_head->next;
        delete tmp;
    }
}

template<typename T>
template<typename... Args>
void Stack<T>::emplace(Args&&... args) {
    
}

template<typename T>
void Stack<T>::push(const T& element) {
    m_head = new Node(element, m_head);
    m_size++;
}

template<typename T>
void Stack<T>::push(T&& element) {
    m_head = new Node(element, m_head);
    m_size++;
}

template<typename T>
void Stack<T>::pop() {
    if (m_head) {
        Node* tmp = m_head;
        m_head = m_head->prev;
        delete tmp;
        m_size--;
    }
}

template<typename T>
T& Stack<T>::top() const {
    return m_head->m_data;
}

template<typename T>
size_t Stack<T>::size() const {
    return m_size;
}

template<typename T>
bool Stack<T>::empty() const {
    return m_size == 0;
}

/* ---------------------------------------------------------------------------- */

template<typename T>
struct Stack<T>::Node
{
    public:
        T data;
        Node* next;

        Node(T data, Node<T>* next, Node<T>* prev): m_data(data), m_next(next), m_prev(prev) {}

        ~Node() {}
};

/* ---------------------------------------------------------------------------- */

}; /* namespace Ariana */