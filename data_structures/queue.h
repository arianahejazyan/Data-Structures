#pragma once
#include <utility>

namespace Ariana 
{

template<typename T>
struct Queue
{
    private:

        struct Node;

        Node* front;
        Node* back;

    public:

        Queue();

        ~Queue();

        template<typename... Args>
        void emplace(Args&&... args);

        void enQueue(const T& element);

        void enQueue(T&& element);

        void deQueue();

        T& getFront();

        T& getBack();
};

template<typename T>
struct Queue<T>::Node
{
    T data;
    Node* next;

    Node(const T& data): data(data), next(nullptr) {}

    Node(T&& data);

    ~Node() = default;
};

template<typename T>
Queue<T>::Queue(): front(nullptr), back(nullptr) {}

template<typename T>
Queue<T>::~Queue() = default;

template<typename T>
template<typename... Args>
void Queue<T>::emplace(Args&&... args) {

}

template<typename T>
void Queue<T>::enQueue(const T& element) {

}

template<typename T>
void Queue<T>::enQueue(T&& element) {

}

template<typename T>
void Queue<T>::deQueue() {

}

template<typename T>
T& Queue<T>::getFront() {
    return front->data;
}

template<typename T>
T& Queue<T>::getBack() {
    return back->data;
}

}; // namespace