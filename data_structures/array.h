#pragma once
#include <cstddef>

namespace Ariana
{

template<typename T>
struct Array
{
    private:

        T* elements;
        size_t capacity;
        size_t size;

        void resize();

    public:

        Array();

        ~Array();

        T& operator[](size_t index);

        template<typename... Args>
        void emplace(Args&&... args);

        void push(const T& element);

        void push(T&& element);

        void pop();

        size_t getCapacity() const;

        size_t getSize() const;

        T* begin();

        T* end();
};

template<typename T>
Array<T>::Array(): size(0), capacity(1) {
    elements = new T[capacity];
}

template<typename T>
Array<T>::~Array() {
    delete[] elements;
}

template<typename T>
T& Array<T>::operator[](size_t index) {
    return *(elements + index);
}

template<typename T>
template<typename... Args>
void Array<T>::emplace(Args&&... args) {
    
}

template<typename T>
void Array<T>::push(const T& element) {
    
}

template<typename T>
void Array<T>::push(T&& element) {
    
}

template<typename T>
void Array<T>::pop() {
    --size;
}

template<typename T>
size_t Array<T>::getCapacity() const {
    return capacity;
}

template<typename T>
size_t Array<T>::getSize() const {
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