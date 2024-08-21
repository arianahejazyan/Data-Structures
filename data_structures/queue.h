#pragma once
#include <utility>

namespace Ariana 
{

template<typename T>
struct Queue // FIFO
{
    private:

        struct Node;

        Node* front;
        Node* rear;

    public:

        void push(const T& item);

        void push(T&& item);

        void pop();
};

template<typename T>
void Queue<T>::push(const T& item) {
    Node* node = new Node(item);
    if (rear) {
        node->next = rear;
        rear = node;
    } else {
        front = rear = node;
    }node;
}

template<typename T>
void Queue<T>::push(T&& item) {
    Node* node = new Node(std::move(item));
    if (rear) {
        node->next = rear;
        rear = node;
    } else {
        front = rear = node;
    }
}

template<typename T>
void Queue<T>::pop() {
    if (front) {
        Node* tmp = front;
        front = front->next;
        delete tmp;
    }
}

template<typename T>
struct Queue<T>::Node
{
    public:

        T data;
        Node* next;
};

}; // namespace