#pragma once
#include "utility.h"

namespace Ariana
{

template<typename T>
struct Stack
{
    private:
    
        struct Node;

        Node* top;
    
    public:

        Stack();

        ~Stack();

        template<typename... Args>
        void emplace(Args&&... args);

        void push(const T& element);

        void push(T&& element);

        void pop();

        T& getTop();
};

template<typename T>
struct Stack<T>::Node
{
    T data;
    Node* next;

    Node(const T& data): data(data), next(nullptr) {}

    Node(T&& data);

    ~Node() = default;
};

template<typename T>
Stack<T>::Stack(): top(nullptr), size(0) {}

template<typename T>
Stack<T>::~Stack() {
    while (top) {
        Node* tmp = top;
        top = top->next;
        delete tmp;
    }
}

template<typename T>
template<typename... Args>
void Stack<T>::emplace(Args&&... args) {

}

template<typename T>
void Stack<T>::push(const T& element) {

}

template<typename T>
void Stack<T>::push(T&& element) {

}

template<typename T>
void Stack<T>::pop() {

}

template<typename T>
T& Stack<T>::getTop() {
    return top->data;
}

}; // namespace