#ifndef BALANCEDTREE_H
#define BALANCEDTREE_H

#include "Node.hpp"

template <class type>
class BalancedTree {
    private:
        int nodeCount;
        Node<type>* root;
        bool balanced(void);
        int getHeight(Node<type>*, int);
        
    public:
        BalancedTree(void);
        bool isEmpty(void);
        bool add(Node<type>*);
        bool remove(Node<type>*);
        void displayMonth(int);
};

#endif