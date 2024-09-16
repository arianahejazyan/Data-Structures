#pragma once

namespace Ariana
{

template<typename T>
struct Heap
{
    private:

        struct Node;

        Node* root;

        void heapifyUp();

        void heapifyDown();

    public:

        Heap();

        ~Heap();

        template<typename... Args>
        void emplace(Args&&... args);

        void push(const T& element);

        void push(T&& element);

        void pop();

        T& min();
};

template<typename T>
struct Heap<T>::Node
{
    T data;
    Node* left;
    Node* right;

    Node(const T& data): data(data), left(nullptr), right(nullptr) {}

    Node(T&& data);

    ~Node() = default;
};

template<typename T>
T& Heap<T>::min() {
    return root->data;
}

}; // namespace