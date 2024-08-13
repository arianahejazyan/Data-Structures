#pragma once

/* ---------------------------------------------------------------------------- */

namespace Ariana
{

template<typename T>
struct Stack
{
    private:
        template<typename T> class Node;

        Node<T>* m_head;
        size_t m_size;
    
    public:

        Stack();

        ~Stack();

        void emplace();

        void push(T& element);

        void pop();

        T& top();

        size_t size() const;

        bool empty() const;
};

};

/* ---------------------------------------------------------------------------- */

template<typename T>
Ariana::Stack<T>::Stack(): n_head(nullptr), m_size(0) {}

template<typename T>
size_t Ariana::Stack<T>::size() const {
    return m_size;
}

template<typename T>
bool Ariana::Stack<T>::empty() const {
    return m_size == 0;
}

/* ---------------------------------------------------------------------------- */

template<typename T>
class Node
{
    private:
        T m_data;
        Node<T>* m_next;
        Node<T>* m_prev;

    public:

        Node(T data, Node<T>* next, Node<T>* prev): m_data(data), m_next(next), m_prev(prev) {}

        ~Node() {}
};

/* ---------------------------------------------------------------------------- */