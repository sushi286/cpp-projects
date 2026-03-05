//*****************************************************************************************************
//
//      This header file defines a class template for a binary search tree (BST) with recursive
//      methods. Includes in-order, pre-order, and post-order traversal methods for displaying the
//      tree in various orders.
//
//      Other files required:
//        1.    node.h - header file for the Node struct for use in the BST class
//
//*****************************************************************************************************

#ifndef BST_H
#define BST_H

#include "node.h"
#include <iostream>
using namespace std;

template <typename T>
class BST {

private:
    Node<T>* root;

    Node<T>* insert(Node<T>* node, const T& value) {

        if(node == nullptr)
            return new Node<T>(value);

        if(value < node->data)
            node->left = insert(node->left,value);

        else if(node->data < value)
            node->right = insert(node->right,value);

        return node;
    }

    Node<T>* searchNode(Node<T>* node,const T& key) const {

        if(node == nullptr)
            return nullptr;

        if(key < node->data)
            return searchNode(node->left,key);

        if(node->data < key)
            return searchNode(node->right,key);

        return node;
    }

    void inOrder(Node<T>* node,ostream& out) const {

        if(node==nullptr) return;

        inOrder(node->left,out);
        out<<node->data<<endl;
        inOrder(node->right,out);
    }

    void preOrder(Node<T>* node) const {

        if(node==nullptr) return;

        cout<<node->data<<endl;
        preOrder(node->left);
        preOrder(node->right);
    }

    void postOrder(Node<T>* node) const {

        if(node==nullptr) return;

        postOrder(node->left);
        postOrder(node->right);
        cout<<node->data<<endl;
    }

    int height(Node<T>* node) const {

        if(node==nullptr)
            return 0;

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        if(leftHeight > rightHeight)
            return leftHeight+1;
        else
            return rightHeight+1;
    }

public:

    BST() {
        root = nullptr;
    }

    void insert(const T& value) {
        root = insert(root,value);
    }

    T* search(const T& key) const {

        Node<T>* found = searchNode(root,key);

        if(found==nullptr)
            return nullptr;

        return new T(found->data);
    }

    void inOrder() const {
        inOrder(root,cout);
    }

    void inOrder(ostream& out) const {
        inOrder(root,out);
    }

    void preOrder() const {
        preOrder(root);
    }

    void postOrder() const {
        postOrder(root);
    }

    int height() const {
        return height(root);
    }

};

#endif
//*****************************************************************************************************

// template <typename T>
// Node<T> *_findMin(Node<T> *root) {
//     Node<T> *result = nullptr;

//     if (root) {
//         if (root->left == nullptr)
//             result = root;
//         else
//             result = _findMin(root->left);
//     }
//     return result;
// }

//*****************************************************************************************************

#endif
