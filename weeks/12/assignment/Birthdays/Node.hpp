#ifndef NODE_H
#define NODE_H

#include "Person.hpp"

class Node {
    private:
        Person data;
        Node* parent;
        Node* leftChild;
        Node* rightChild;
    
    public:
        Node(void)
        { parent = nullptr; leftChild = nullptr; rightChild = nullptr; }

        Node(Person& data)
        { this->data = data; parent = nullptr; leftChild = nullptr; rightChild = nullptr; }

        Node(Person& data, Node* parent)
        { this->data = data; this->parent = parent; leftChild = nullptr; rightChild = nullptr; }

        Person getData(void)
        { return data; }

        void setData(Person& data)
        { this->data = data; }

        Node* getParent(void)
        { return parent; }

        void setParent(Node* parent)
        {
            if (!this->parent && !parent) {
                this->parent = new Node;
                this->parent = parent;
            } else {
                this->parent = parent;
            }
        }

        Node* getLeft(void)
        { return leftChild; }

        void setLeft(Node* left)
        { leftChild = left; }

        Node* getRight(void)
        { return rightChild; }

        void setRight(Node* right)
        { rightChild = right; }
};

#endif