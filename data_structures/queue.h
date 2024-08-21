#pragma once

namespace Ariana 
{

template<typename T>
struct Queue // FIFO
{
    private:

        struct Node;

        Node* m_head;
        Node* m_tail;
};

template<typename T>
struct Queue<T>::Node
{
    public:

        T data;
        Node* next;
};

}; // namespace