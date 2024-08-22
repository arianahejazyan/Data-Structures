#include "stack.h"

namespace Ariana
{

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

}; // namespace