#pragma once
#include "utility.h"

namespace Ariana
{

template<typename T>
struct List
{
    private:

        struct Node;

        Node* front;
        Node* back;
        S size;
    
    public:

        List();

        ~List();

        template<typename... Args>
        void emplace_front(Args&&... args);

        template<typename... Args>
        void emplace_back(Args&&... args);

        void push_front(const T& elemenet);

        void push_front(T&& elemenet);

        void push_back(const T& element);

        void push_back(T&& element);

        void pop_front();

        void pop_back();

        T& getFront();

        T& getBack();

        S getSize() const;
};

template<typename T>
struct List<T>::Node
{
    T data;
    Node* next;
    Node* prev;

    Node(const T& data): data(data), next(nullptr), prev(nullptr) {}

    Node(T&& data);

    ~Node() = default;
};

template<typename T>
List<T>::List(): front(nullptr), back(nullptr), size(0) {}

template<typename T>
List<T>::~List() {
    while (front) {
        Node* tmp = front;
        front = front->next;
        delete tmp;
    }
}

template<typename T>
template< typename... Args>
void List<T>::emplace_front(Args&&... args) {

}

template<typename T>
template< typename... Args>
void List<T>::emplace_back(Args&&... args) {
 
}

template<typename T>
void List<T>::push_front(const T& element) {

}

template<typename T>
void List<T>::push_front(T&& element) {

}

template<typename T>
void List<T>::push_back(const T& element) {

}

template<typename T>
void List<T>::push_back(T&& element) {

}

template<typename T>
void List<T>::pop_front() {

}

template<typename T>
void List<T>::pop_back() {

}

template<typename T>
T& List<T>::getFront() {
    return head->data;
}

template<typename T>
T& List<T>::getBack() {
    return tail->data;
}

template<typename T>
S List<T>::getSize() const {
    return size;
}

}; // namespace