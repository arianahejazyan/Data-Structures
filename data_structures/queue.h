#pragma once
#include <utility>

namespace Ariana 
{

template<typename T>
struct Queue // FIFO
{
    private:

        struct Node;

        Node* m_front;
        Node* m_rear;

    public:

        void push(const T& item);

        void push(T&& item);

        void pop();

        T& front();

        const T& front() const;
};

template<typename T>
void Queue<T>::push(const T& item) {
    Node* node = new Node(item);
    if (m_rear) {
        node->next = m_rear;
        m_rear = node;
    } else {
        m_front = m_rear = node;
    }node;
}

template<typename T>
void Queue<T>::push(T&& item) {
    Node* node = new Node(std::move(item));
    if (m_rear) {
        node->next = m_rear;
        m_rear = node;
    } else {
        m_front = m_rear = node;
    }
}

template<typename T>
void Queue<T>::pop() {
    if (m_front) {
        Node* tmp = m_front;
        m_front = m_front->next;
        delete tmp;
    }
}
template<typename T>
T& Queue<T>::front() {
    return m_front->data;
}

template<typename T>
const T& Queue<T>::front() const {
    return m_front->data;
}

template<typename T>
struct Queue<T>::Node
{
    public:

        T data;
        Node* next;
};

}; // namespace