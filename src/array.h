#pragma once
#include "utility.h"

namespace Ariana
{

template<typename T>
struct Array
{
    private:

        T* elements;
        S capacity;
        S size;

        void resize(S n);

    public:

        Array();

        ~Array();

        T& operator[](S index);

        template<typename... Args>
        void emplace(Args&&... args);

        void push(const T& element);

        void push(T&& element);

        void pop();

        S getCapacity() const;

        S getSize() const;

        T* begin();

        T* end();
};

template<typename T>
void Array<T>::resize(S n) {

}

template<typename T>
Array<T>::Array(): size(0), capacity(1) {
    elements = new T[capacity];
}

template<typename T>
Array<T>::~Array() {
    delete[] elements;
}

template<typename T>
T& Array<T>::operator[](S index) {
    return *(elements + index);
}

template<typename T>
template<typename... Args>
void Array<T>::emplace(Args&&... args) {
    if (size >= capacity) resize(capacity * 2);
}

template<typename T>
void Array<T>::push(const T& element) {
    if (size >= capacity) resize(capacity * 2);
}

template<typename T>
void Array<T>::push(T&& element) {
    if (size >= capacity) resize(capacity * 2);
}

template<typename T>
void Array<T>::pop() {
    if (size == 0) return;
    if (--size <= capacity / 4) resize(capacity / 2);
}

template<typename T>
S Array<T>::getCapacity() const {
    return capacity;
}

template<typename T>
S Array<T>::getSize() const {
    return size;
}

template<typename T>
T* Array<T>::begin() {
    return elements;
}

template<typename T>
T* Array<T>::end() {
    return elements + size;
}

}; // namespace