#pragma once

namespace Ariana
{

template<typename Key, typename Value>
struct Tree
{

    public:

        void depth();

        void height();

        void inOrder();

        void preOrder();

        void postOrder();

        void levelOrder();

        void min();

        void max();

        void search();

        void mean();

        void predecessor();

        void successor();
};

}; // namespace