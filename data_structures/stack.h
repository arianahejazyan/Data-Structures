#pragma once
#include <cstddef>

namespace Ariana
{

template<typename T>
struct Stack // LIFO
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

template<typename T>
struct Stack<T>::Node
{
    public:
        T data;
        Node* next;

        Node(T data, Node<T>* next, Node<T>* prev): m_data(data), m_next(next), m_prev(prev) {}

        ~Node() {}
};

}; // namespace