#ifndef NODE_H
#define NODE_H

#include "Person.hpp"

template<class type>
class Node {
    private:
        type data;
        Node<type>* parent;
        Node<type>* leftChild;
        Node<type>* rightChild;
    
    public:
        Node(void)
        { parent = nullptr; leftChild = nullptr; rightChild = nullptr; }

        Node(type& data)
        { this->data = data; parent = nullptr; leftChild = nullptr; rightChild = nullptr; }

        Node(type& data, Node<type>* parent)
        { this->data = data; this->parent = parent; leftChild = nullptr; rightChild = nullptr; }

        type getData(void)
        { return data; }

        void setData(type& data)
        { this->data = data; }

        Node<type>* getParent(void)
        { return parent; }

        void setParent(Node<type>* parent)
        {
            if (!this->parent && !parent) {
                this->parent = new Node<type>;
                this->parent = parent;
            } else {
                this->parent = parent;
            }
        }

        Node<type>* getLeft(void)
        { return leftChild; }

        void setLeft(Node<type>* left)
        { leftChild = left; }

        Node<type>* getRight(void)
        { return rightChild; }

        void setRight(Node<type>* right)
        { rightChild = right; }
};

template class Node<Person>;

#endif