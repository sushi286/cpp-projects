//*****************************************************************************************************
//
//      This header file defines a struct template that represents a node in a binary tree.
//
//*****************************************************************************************************

#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(const T& value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

#endif
