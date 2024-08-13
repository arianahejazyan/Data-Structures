#pragma once

/* ---------------------------------------------------------------------------- */

namespace Ariana
{

template<typename T>
struct Stack
{
    private:
        class Node;

        Node<T> m_top;
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
size_t Ariana::Stack<T>::size() const {
    return m_size;
}

template<typename T>
bool Ariana::Stack<T>::empty() const {
    return m_size == 0;
}

/* ---------------------------------------------------------------------------- */